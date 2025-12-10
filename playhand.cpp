#include "playhand.h"

PlayHand::PlayHand() {}

PlayHand::PlayHand(Cards &cards)
{
    //1.对扑克牌进行分类：1张，2张，3张，4张有多少种
    classify(cards);
    //2.对牌型进行分类
    judgeCardType();
}

PlayHand::PlayHand(HandType type, Card::CardPoint pt, int extra)
{
    m_type = type;
    m_pt = pt;
    m_extra = extra;
}

void PlayHand::classify(Cards &cards)
{
    CardList list = cards.toCardList();
    int cardRecord[Card::Card_End];
    memset(cardRecord, 0, sizeof(int) * Card::Card_End);

    for(int i = 0; i < list.size(); ++i)
    {
        Card c = list.at(i);
        cardRecord[c.point()]++;
    }

    m_onecard.clear();
    m_twocard.clear();
    m_threecard.clear();
    m_fourcard.clear();

    for(int i = 0; i < Card::Card_End; ++i)
    {
        if(cardRecord[i] == 1)
        {
            m_onecard.push_back((Card::CardPoint)i);
        }
        else if(cardRecord[i] == 2)
        {
            m_twocard.push_back((Card::CardPoint)i);
        }
        else if(cardRecord[i] == 3)
        {
            m_threecard.push_back((Card::CardPoint)i);
        }
        else if(cardRecord[i] == 4)
        {
            m_fourcard.push_back((Card::CardPoint)i);
        }
    }
}

void PlayHand::judgeCardType()
{
    m_type = Hand_unknown;
    m_pt = Card::Card_Begin;
    m_extra = 0;

    if(isPass())
    {
        m_type = Hand_Pass;
    }
    if(isSingle())
    {
        m_type = Hand_Single;
        m_pt = m_onecard[0];
    }
    else if(isPair())
    {
        m_type = Hand_Pair;
        m_pt = m_twocard[0];
    }
    else if(isTriple())
    {
        m_type = Hand_Triple;
        m_pt = m_threecard[0];
    }
    else if(isTripleSingle())
    {
        m_type = Hand_Triple_Single;
        m_pt = m_threecard[0];
    }
    else if(isTriplePair())
    {
        m_type = Hand_Triple_Pair;
        m_pt = m_threecard[0];
    }
    else if(isPlane())
    {
        m_type = Hand_Plane;
        //记录点数最小的牌
        m_pt = m_threecard[0];
    }
    else if(isPlaneTwoSingle())
    {
        m_type = Hand_Plane_Two_Single;
        //记录点数最小的牌
        m_pt = m_threecard[0];
    }
    else if(isPlaneTwoPair())
    {
        m_type = Hand_Plane_Two_Pair;
        //记录点数最小的牌
        m_pt = m_threecard[0];
    }
    else if(isSeqPair())
    {
        m_type = Hand_Seq_Pair;
        //记录点数最小的牌
        m_pt = m_twocard[0];
        m_extra = m_twocard.size();
    }
    else if(isSeqSingle())
    {
        m_type = Hand_Seq_Single;
        //记录点数最小的牌
        m_pt = m_onecard[0];
        m_extra = m_onecard.size();
    }
    else if(isBomb())
    {
        m_type = Hand_Bomb;
        //记录点数最小的牌
        m_pt = m_fourcard[0];
    }
    else if(isBombSingle())
    {
        m_type = Hand_Bomb_Single;
        //记录点数最小的牌
        m_pt = m_fourcard[0];
    }
    else if(isBombPair())
    {
        m_type = Hand_Bomb_Pair;
        m_pt = m_fourcard[0];
    }
    else if(isBombTwoSingle())
    {
        m_type = Hand_Bomb_Two_Single;
        m_pt = m_fourcard[0];
    }
    else if(isBombJokers())
    {
        m_type = Hand_Bomb_Jokers;
    }
    else if(isBombJokersSingle())
    {
        m_type = Hand_Bomb_Jokers_Single;
    }
    else if(isBombJokersPair())
    {
        m_type = Hand_Bomb_Jokers_Pair;
    }
    else if(isBombJokersTwoSingle())
    {
        m_type = Hand_Bomb_Jokers_Two_Single;
    }
}

bool PlayHand::isPass()
{
    if(m_onecard.isEmpty() && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        return true;
    }
    return false;
}

Card::CardPoint PlayHand::getcardPoint()
{
    return m_pt;
}

int PlayHand::getExtra()
{
    return m_extra;
}

bool PlayHand::canBeat(const PlayHand &other)
{
    //我的牌型是未知的
    if(m_type == Hand_unknown)
    {
        return false;
    }
    //对方放弃出牌
    if(other.m_type == Hand_Pass)
    {
        return true;
    }
    //我是王炸
    if(m_type == Hand_Bomb_Jokers)
    {
        return true;
    }
    if(m_type == Hand_Bomb && other.m_type >= Hand_Single && other.m_type <= Hand_Seq_Single)
    {
        return true;
    }
    //双方牌型一致
    if(m_type == other.m_type)
    {
        if(m_type == Hand_Seq_Pair || m_type == Hand_Seq_Single)
        {
            return m_pt > other.m_pt && m_extra == other.m_extra;
        }
        else
        {
            return m_pt > other.m_pt;
        }
    }
    return false;
}

bool PlayHand::isSingle()
{
    if(m_onecard.size() == 1 && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        return true;
    }
    return false;
}

bool PlayHand::isPair()
{
    if(m_onecard.isEmpty() && m_twocard.size() == 1 && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        return true;
    }
    return false;
}

bool PlayHand::isTriple()
{
    if(m_onecard.isEmpty() && m_twocard.isEmpty() && m_threecard.size() == 1 && m_fourcard.isEmpty())
    {
        return true;
    }
    return false;
}

bool PlayHand::isTripleSingle()
{
    if(m_onecard.size() == 1 && m_twocard.isEmpty() && m_threecard.size() == 1 && m_fourcard.isEmpty())
    {
        return true;
    }
    return false;
}

bool PlayHand::isTriplePair()
{
    if(m_onecard.isEmpty() && m_twocard.size() == 1 && m_threecard.size() == 1 && m_fourcard.isEmpty())
    {
        return true;
    }
    return false;

}

bool PlayHand::isPlane()
{
    if(m_onecard.isEmpty() && m_twocard.isEmpty() && m_threecard.size() == 2 && m_fourcard.isEmpty())
    {
        std::sort(m_threecard.begin(), m_threecard.end());
        if(m_threecard[1] - m_threecard[0] == 1 && m_threecard[1] < Card::Card_2)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isPlaneTwoSingle()
{
    if(m_onecard.size() == 2 && m_twocard.isEmpty() && m_threecard.size() == 2 && m_fourcard.isEmpty())
    {
        std::sort(m_threecard.begin(), m_threecard.end());
        std::sort(m_onecard.begin(), m_onecard.end());
        if(m_threecard[1] - m_threecard[0] == 1 && m_threecard[1] < Card::Card_2 &&
            m_onecard[0] != Card::Card_SJ && m_onecard[1] != Card::Card_BJ)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isPlaneTwoPair()
{
    if(m_onecard.isEmpty() && m_twocard.size() == 2 && m_threecard.size() == 2 && m_fourcard.isEmpty())
    {
        std::sort(m_threecard.begin(), m_threecard.end());
        if(m_threecard[1] - m_threecard[0] == 1 && m_threecard[1] < Card::Card_2)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isSeqPair()
{
    if(m_onecard.isEmpty() && m_twocard.size() >= 3 && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        std::sort(m_twocard.begin(), m_twocard.end());
        if(m_twocard.last() - m_twocard.first() == (m_twocard.size() - 1) &&
            m_twocard.first() >= Card::Card_3 && m_twocard.last() < Card::Card_2)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isSeqSingle()
{
    if(m_onecard.size() >= 5 && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        std::sort(m_onecard.begin(), m_onecard.end());
        if(m_onecard.last() - m_onecard.first() == (m_onecard.size() - 1) &&
            m_onecard.first() >= Card::Card_3 && m_onecard.last() < Card::Card_2)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isBomb()
{
    if(m_onecard.isEmpty() && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.size() == 1)
    {
        return true;
    }
    return false;
}

bool PlayHand::isBombSingle()
{
    if(m_onecard.size() == 1 && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.size() == 1)
    {
        return true;
    }
    return false;
}

bool PlayHand::isBombPair()
{
    if(m_onecard.isEmpty() && m_twocard.size() == 1 && m_threecard.isEmpty() && m_fourcard.size() == 1)
    {
        return true;
    }
    return false;
}

bool PlayHand::isBombTwoSingle()
{
    if(m_onecard.size() == 2 && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.size() == 1)
    {
        std::sort(m_onecard.begin(), m_onecard.end());
        if(m_onecard.first() != Card::Card_SJ && m_onecard.last() != Card::Card_BJ)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isBombJokers()
{
    if(m_onecard.size() == 2 && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        std::sort(m_onecard.begin(), m_onecard.end());
        if(m_onecard.first() == Card::Card_SJ && m_onecard.last() == Card::Card_BJ)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isBombJokersSingle()
{
    if(m_onecard.size() == 3 && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        std::sort(m_onecard.begin(), m_onecard.end());
        if(m_onecard[1] == Card::Card_SJ && m_onecard[2] == Card::Card_BJ)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isBombJokersPair()
{
    if(m_onecard.size() == 2 && m_twocard.size() == 1 && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        std::sort(m_onecard.begin(), m_onecard.end());
        if(m_onecard[0] == Card::Card_SJ && m_onecard[1] == Card::Card_BJ)
        {
            return true;
        }
    }
    return false;
}

bool PlayHand::isBombJokersTwoSingle()
{
    if(m_onecard.size() == 4 && m_twocard.isEmpty() && m_threecard.isEmpty() && m_fourcard.isEmpty())
    {
        std::sort(m_onecard.begin(), m_onecard.end());
        if(m_onecard[2] == Card::Card_SJ && m_onecard[3] == Card::Card_BJ)
        {
            return true;
        }
    }
    return false;
}

PlayHand::HandType PlayHand::getHandtype()
{
    return m_type;
}
