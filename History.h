//
// Created by Nate on 2/4/2017.
//

#ifndef HW2_HISTORY_H
#define HW2_HISTORY_H

#include "PurchaseSale.h"
#include <vector>

class History {
private:
    int m_simDaysCount;
    int m_seedMoney;
public:
    std::vector<PurchaseSale*> m_trades;

    History(int simDaysCount, int seedMoney);

    int getSimDaysCount();
    int getSeedMoney();

    int getTotalProfitLoss();
    int getTotalProfitLossPerDay();
    int getTotalProfitLossPerStock(std::string symbol);
};


#endif //HW2_HISTORY_H
