#ifndef ROBOT_H
#define ROBOT_H

#include <QObject>
#include "player.h"
#include "robotgrablord.h"
#include "robotplayhand.h"

class Robot : public Player
{
    Q_OBJECT
public:
    using Player::Player;
    explicit Robot(QObject *parent = nullptr);

    void prepareCallLord() override;
    void preparePlayHand() override;

    //考虑叫地主
    void thinkCallLord() override;
    void thinkPlayHand() override;

    RobotGrabLord* m_grabThread = nullptr; // 抢地主线程
    RobotPlayHand* m_playThread = nullptr; // 出牌线程
};

#endif // ROBOT_H
