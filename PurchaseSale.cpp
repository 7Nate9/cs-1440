//
// Created by Nate on 2/4/2017.
//

#include "PurchaseSale.h"

PurchaseSale::PurchaseSale(std::string symbol, int quantity, int purchaseTime, int purchasePrice, int purchaseFee, int saleTime, int salePrice, int saleFee)
{
    m_symbol = symbol;
    m_quantity = quantity;
    m_purchaseTime = purchaseTime;
    m_purchasePrice = purchasePrice;
    m_purchaseFee = purchaseFee;
    m_saleTime = saleTime;
    m_salePrice = salePrice;
    m_saleFee = saleFee;
}

std::string PurchaseSale::getSymbol()
{
    return m_symbol;
}

int PurchaseSale::getQuantity()
{
    return m_quantity;
}

int PurchaseSale::getPurchaseTime()
{
    return m_purchaseTime;
}

int PurchaseSale::getPurchasePrice()
{
    return m_purchasePrice;
}

int PurchaseSale::getPurchaseFee()
{
    return m_purchaseFee;
}

int PurchaseSale::getSaleTime()
{
    return m_saleTime;
}

int PurchaseSale::getSalePrice()
{
    return m_salePrice;
}

int PurchaseSale::getSaleFee()
{
    return m_saleFee;
}

int PurchaseSale::getProfitLoss()
{
    return (m_quantity * m_salePrice) - ((m_quantity * m_purchasePrice) + m_saleFee + m_purchaseFee);
}