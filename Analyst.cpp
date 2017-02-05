//
// Created by Nate on 2/4/2017.
//

#include "Analyst.h"

Analyst::Analyst(std::string filePath)
{
    std::ifstream fin;
    fin.open(filePath);

    std::getline(fin, m_name);
    std::getline(fin, m_initials);

    m_tradeHistory = new History(static_cast<int>(fin.get()), static_cast<int><fin.get());

    int tradeCount = static_cast<int>(fin.get());

    for (int i = 0; i < tradeCount; i++)
    {
        m_tradeHistory.m_trades.push_back(new PurchaseSale(fin.get(','), static_cast<int>(fin.get(',')), static_cast<int>(fin.get(',')), static_cast<int>(fin.get(',')), static_cast<int>(fin.get(',')), static_cast<int>(fin.get(',')), static_cast<int>(fin.get(',')), static_cast<int>(fin.get(','))));
    }

    fin.close();
}

std::string Analyst::getName()
{
    return m_name;
}

std::string Analyst::getInitials()
{
    return m_initials;
}