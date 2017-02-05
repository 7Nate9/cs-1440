//
// Created by Nate on 2/4/2017.
//

#ifndef HW2_PURCHASESALE_H
#define HW2_PURCHASESALE_H

#include <string>

class PurchaseSale {
private:
    std::string m_symbol;
    int m_quantity;
    int m_purchaseTime;
    int m_purchasePrice;
    int m_purchaseFee;
    int m_saleTime;
    int m_salePrice;
    int m_saleFee;
public:
    PurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee, int saleTime, int salePrice, int SaleFee);

    std::string getSymbol();
    int getQuantity();
    int getPurchaseTime();
    int getPurchasePrice();
    int getPurchaseFee();
    int getSaleTime();
    int getSalePrice();
    int getSaleFee();

    int getProfitLoss();
};


#endif //HW2_PURCHASESALE_H
