#include <iostream>
#include <iomanip>
#include "Analyst.h"

void generateComparison(std::string outputFilePath, std::vector<Analyst*> analysts);
std::vector<std::string>* generateSymbolList(std::vector<Analyst*> analysts);

int main() {
    /**
     * To generate a comparison, create a vector of Analyst object pointers using the Analyst constructor, pass that vector to the generateComparison() function.
     */
    return 0;
}

std::vector<std::string>* generateSymbolList(std::vector<Analyst*> analysts)
{
    std::vector<std::string> symbolList = {};

    for (int i = 0; i < analysts.size(); i++)
    {
        for (int j = 0; j < analysts[i]->m_tradeHistory.m_trades.size(); j++)
        {
            std::string tempSymbol = analysts[i]->m_tradeHistory.m_trades[j]->getSymbol();

            bool alreadyInList = false;

            for (int k = 0; k < symbolList.size(); k++)
            {
                if (symbolList[k] == tempSymbol)
                    alreadyInList = true;
            }

            if (!alreadyInList)
            {
                symbolList.push_back(tempSymbol);
            }
        }
    }

    return &symbolList;
}

void generateComparison(std::string outputFilePath, std::vector<Analyst*> analysts)
{
    std::ofstream fout;
    fout.open(outputFilePath);

    fout << "Analyst Comparison" << std::endl << std::endl << "Investors" << std::endl;

    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(5) << std::right;
        fout << analysts[i]->getInitials();
        fout << std::setw(4) << std::left << " ";
        fout << analysts[i]->getName() << std::endl;
    }

    fout << std::endl;
    fout << "Overall Performance" << std::endl;
    fout << std::setw(16) << std::left << " " << std::setw(1) << "|";

    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(7) << std::right;
        fout << analysts[i]->getInitials();
        fout << std::setw(6) << " ";
        fout << std::setw(1) << "|";
    }

    fout << std::endl;

    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(13);
        fout << "-------------";
        fout << std::setw(1) << "|";
    }

    fout << std::endl;

    fout << std::setw(16) << std::left << "d (Days)";
    fout << std::setw(1) << "|";
    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(13) << std::right;
        fout << analysts[i]->m_tradeHistory.getSimDaysCount();
        fout << std::setw(1) << "|";
    }

    fout << std::endl;

    fout << std::setw(16) << std::left << "Seed Amount ($)";
    fout << std::setw(1) << "|";
    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(13) << std::right << std::fixed << std::setprecision(2);
        fout << analysts[i]->m_tradeHistory.getSeedMoney();
        fout << std::setw(1) << "|";
    }

    fout << std::endl;

    fout << std::setw(16) << std::left << "TPL ($)";
    fout << std::setw(1) << "|";
    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(13) << std::right << std::fixed << std::setprecision(2);
        fout << analysts[i]->m_tradeHistory.getTotalProfitLoss();
        fout << std::setw(1) << "|";
    }

    fout << std::endl;

    fout << std::setw(16) << std::left << "PLPD ($/Day)";
    fout << std::setw(1) << "|";
    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(13) << std::right << std::fixed << std::setprecision(2);
        fout << analysts[i]->m_tradeHistory.getTotalProfitLossPerDay();
        fout << std::setw(1) << "|";
    }

    fout << std::endl << std::endl;

    std::vector<std::string>* symbolListPointer = generateSymbolList(analysts);
    std::vector<std::string> symbolList = *symbolListPointer;
    symbolListPointer = nullptr;

    fout << "Stock Performance" << std::endl;
    fout << std::setw(8) << std::left << " ";
    fout << std::setw(1) << "|" << std::setw(25) << std::right << "SPLPDs" << std::left << std::endl;

    fout << std::setw(8) << "Symbol" << std::setw(1) << "|";

    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(7) << std::right;
        fout << analysts[i]->getInitials();
        fout << std::setw(6) << " ";
        fout << std::setw(1) << "|";
    }

    fout << std::endl;

    for (int i = 0; i < analysts.size(); i++)
    {
        fout << std::setw(13);
        fout << "-------------";
        fout << std::setw(1) << "|";
    }

    fout << std::endl;

    for (int i = 0; i < symbolList.size(); i++)
    {
        fout << std::setw(8) << std::left;
        fout << symbolList[i];
        fout << std::setw(1) << "|";

        for (int j = 0; j < analysts.size(); j++)
        {
            fout << std::setw(13) << std::right << std::fixed << std::setprecision(2);
            fout << analysts[j]->m_tradeHistory.getTotalProfitLossPerStock(symbolList[i]);
            fout << std::setw(1) << "|";
        }

        fout << std::endl;
    }

}