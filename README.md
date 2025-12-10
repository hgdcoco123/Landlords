# Landlords
基于Qt6的电脑版斗地主



# 斗地主游戏核心逻辑与实现方案

## 一、核心逻辑概览

游戏整体遵循「初始化→发牌→叫地主→出牌→结算」的闭环流程，核心围绕「玩家交互、牌型规则、流程控制、界面反馈」四大模块展开，各模块通过信号槽联动，确保流程顺畅和交互响应及时。

## 二、分阶段核心逻辑与实现方式

### 1. 游戏初始化阶段

#### 核心逻辑

-   创建玩家对象（1 个用户 + 2 个机器人），初始化性别、方位、前后家关系。
-   初始化扑克牌（54 张牌，含大小王），准备牌组数据。
-   初始化界面组件（背景、卡牌、按钮、头像）和音效控制。
-   建立信号槽连接，打通「玩家动作→控制层→界面反馈」的通信链路。

#### 实现方式

-   **玩家初始化**：在`GameControl::playerInit()`中，实例化`UserPlayer`和`Robot`对象，随机分配性别，通过`setPrevPlayer/setNextPlayer`设置出牌顺序，绑定`notifyGrabLordBet`（叫地主）、`notifyPlayHand`（出牌）等信号。
-   **牌组初始化**：`GameControl::initAllCards()`循环创建 13 个点数 ×4 种花色的牌，再添加大小王，存储到`m_allCards`集合中。
-   **界面初始化**：`GamePanel::gameControlInit()`加载背景图、裁剪卡牌资源（`initCardMap()`）、创建玩家上下文（出牌区、手牌区、头像位置），绑定按钮点击（开始游戏、叫地主、出牌）信号。
-   **音效初始化**：`BGMControl`读取 JSON 配置的音频列表，初始化 5 个播放器（分别对应男性、女性、BGM、辅助音效、结束音效）。

----------

### 2. 发牌阶段

#### 核心逻辑

-   洗牌后按顺序给 3 名玩家发牌，每人 17 张，剩余 3 张作为底牌。
-   发牌过程伴随动画和音效，提升交互体验。
-   发牌结束后切换到「叫地主」阶段。

#### 实现方式

-   **洗牌与发牌**：`GameControl::resetCardData()`调用`initAllCards()`洗牌，`onDispatchCard()`通过定时器控制发牌节奏，每次调用`takeOneCard()`从牌组中随机取一张，通过`player->storeDispatchCard()`存入玩家手牌。
-   **发牌动画**：`GamePanel::cardMoveStep()`控制卡牌从发牌区移动到对应玩家手牌区，通过`curMovePos`累计移动进度，达到 100 时完成一张牌的发放。
-   **流程切换**：当剩余牌数为 3 时（底牌），停止定时器，调用`gameStatusPrecess(CallingLord)`进入叫地主阶段，停止发牌音效。

----------

### 3. 叫地主阶段

#### 核心逻辑

-   按玩家顺序轮流叫地主，可选择「不叫」「1 分」「2 分」「3 分」。
-   叫分最高者成为地主，获得 3 张底牌；无人叫分时重新发牌。
-   叫地主过程伴随界面提示（叫分 / 不叫图标）和对应音效。

#### 实现方式

-   **叫分交互**：玩家通过`ButtonGroup`的按钮触发`betPoint`信号，`UserPlayer::grabLordBet()`发射`notifyGrabLordBet`，由`GameControl::onGrabBet()`处理。
-   **地主判定**：通过`BetRecord`记录最高叫分和对应玩家，3 人都叫过或有人叫 3 分时终止，调用`becomeLord()`分配地主身份，将底牌通过`player->storeDispatchCard(m_allCards)`发给地主。
-   **界面反馈**：`GamePanel::onGrabLordBet()`显示「叫地主 / 抢地主 / 不叫」图标，播放对应音效（`BGMControl::playerRobLordMusic()`），叫分特效通过`showAnimation(Bet, bet)`展示。

----------

### 4. 出牌阶段（核心阶段）

#### 核心逻辑

-   按「地主→农民 1→农民 2」顺序出牌，玩家可选择「出牌」或「不出」。
-   出牌需满足牌型规则：需压制上一家牌型（或首家自由出牌），牌型包括单牌、对牌、顺子、炸弹等 18 种。
-   机器人通过 AI 策略自动出牌，玩家手动选牌后出牌。
-   出牌后更新界面（手牌减少、出牌区显示、剩余牌数提示），播放对应特效和音效。
-   剩余 1/2 张牌时播放一次提示音，避免重复触发。

#### 实现方式

-   **出牌流程控制**：
    1.  玩家出牌：`UserPlayer::playHand()`发射`notifyPlayHand`信号，`GameControl::onPlayHand()`接收后，更新`m_pendPlayer`（上一个出牌玩家）和`m_pendCards`（上一轮牌），并转发`notifyPlayHand`给界面。
    2.  机器人出牌：`Robot::preparePlayHand()`启动子线程`RobotPlayHand`，通过`Strategy::makeStrategy()`分析手牌，自动生成出牌策略（优先出顺子、连对，压制对手牌型）。
-   **牌型判断**：`PlayHand`类核心处理 ——`classify()`按点数统计牌组（1 张、2 张、3 张、4 张的点数集合），`judgeCardType()`通过集合特征判断牌型（如`isSeqSingle()`判断顺子：5 张以上连续点数单牌），`canBeat()`对比当前牌型与上一轮牌型的大小。
-   **界面与音效反馈**：
    1.  `GamePanel::onDisposePlayHand()`存储玩家出牌记录，根据牌型播放特效（如飞机、炸弹动画）。
    2.  不出牌时显示「pass.png」图标，播放过牌音效；出牌时根据是否为「首家 / 压制出牌」播放对应音效。
    3.  剩余牌数提示：通过`m_playedLastCardMusicMap`记录已播放过的提示音类型，首次剩余 1/2 张牌时，调用`BGMControl::playLastMusic()`播放提示音，后续不再重复。
-   **合法性校验**：玩家出牌前，`onUserPlayHand()`校验牌型是否合法（`PlayHand::getHandtype() != Hand_unknown`），能否压制上一轮牌型（`hand.canBeat(PlayHand(cards))`）。

----------

### 5. 结算阶段

#### 核心逻辑

-   当某玩家手牌出完时，判定游戏结束。
-   地主获胜则获得 2 倍底分，两名农民各扣除 1 倍底分；农民获胜则获胜农民各获得 1 倍底分，地主扣除 2 倍底分。
-   结算后显示胜负结果、玩家分数，提供「继续游戏」选项。

#### 实现方式

-   **胜负判定**：`GameControl::onPlayHand()`中检测`player->getCards().isEmpty()`，若为空则根据玩家角色（地主 / 农民）计算分数：
    -   地主获胜：`player->setScore(+2*m_curBet)`，另外两名玩家各`-m_curBet`。
    -   农民获胜：获胜农民`+m_curBet`，地主`-2*m_curBet`，另一名农民`+m_curBet`。
-   **界面展示**：`GamePanel::showEndingScorePanel()`创建结算面板，加载胜负图标（如「lord_win.png」），显示三名玩家分数，通过动画弹出面板。
-   **音效与重置**：播放胜利 / 失败音效（`BGMControl::playEndingMusic()`），点击「继续游戏」后，调用`GameControl::resetCardData()`重置牌组和玩家手牌，回到发牌阶段。

## 三、关键技术亮点与核心类职责

### 1. 核心类职责分工

类名

核心职责

核心方法 / 属性

`GameControl`

游戏流程总控（发牌、叫地主、出牌、结算）

`onGrabBet()`「叫地主处理」、`onPlayHand()`「出牌处理」

`GamePanel`

界面渲染与用户交互（卡牌、按钮、动画）

`onDisposePlayHand()`「出牌界面反馈」、`showAnimation()`「特效播放」

`Player`

玩家数据与行为抽象（手牌、角色、动作）

`storeDispatchCard()`「存牌」、`playHand()`「出牌」

`PlayHand`

牌型判断与大小对比

`judgeCardType()`「牌型识别」、`canBeat()`「牌型对比」

`Strategy`

机器人出牌 AI 策略

`makeStrategy()`「生成出牌方案」、`pickOptimalSeqSingle()`「最优顺子筛选」

`BGMControl`

音效管理（BGM、出牌音、提示音）

`playCardMusic()`「出牌音效」、`playLastMusic()`「剩余牌提示音」

### 2. 关键技术实现

-   **信号槽通信**：Qt 核心机制，如玩家点击「出牌」按钮→`ButtonGroup::playHand`信号→`GamePanel::onUserPlayHand`→`UserPlayer::playHand`→`GameControl::onPlayHand`→`GamePanel::onDisposePlayHand`（界面更新），确保动作传递无延迟。
-   **牌型识别算法**：通过统计牌组中「1 张 / 2 张 / 3 张 / 4 张点数」的集合特征，结合连续点数判断（如顺子需 5 张以上连续点数），实现 18 种牌型的精准识别。
-   **机器人 AI 策略**：`Strategy`类优先拆分顺子、连对减少单牌，优先用非核心牌型压制对手，保留炸弹、王炸等关键牌型应对残局。
-   **音效重复控制**：通过`GamePanel::m_playedLastCardMusicMap`（玩家→已播放提示音类型集合），确保剩余 1/2 张牌时仅播放一次提示音，新局通过`resetLastCardMusicRecord()`清空记录。
