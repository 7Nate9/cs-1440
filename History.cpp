//
// Created by Nate on 2/4/2017.
//

#include "History.h"

History::History(int simDaysCount, int seedMoney)
{
    m_simDaysCount = simDaysCount;
    m_seedMoney = seedMoney;
}

int History::getSimDaysCount()
{
    return m_simDaysCount;
}

int History::getSeedMoney()
{
    return m_seedMoney;
}

int History::getTotalProfitLoss()
{
    int totalProfitLoss = 0;

    for (int i = 0; i < m_trades.size(); i++)
    {
        totalProfitLoss += m_trades[i]->getProfitLoss();
    }

    return totalProfitLoss;
}

int History::getTotalProfitLossPerDay()
{
    return getTotalProfitLoss() / m_simDaysCount;
}

int History::getTotalProfitLossPerStock(std::string symbol)
{
    int totalProfitLoss = 0;

    for (int i = 0; i < m_trades.size(); i++)
    {
        if (m_trades[i]->getSymbol() == symbol)
        {
            totalProfitLoss += m_trades[i]->getProfitLoss();
        }
    }

    return totalProfitLoss;
}