//
// Created by Nate on 2/4/2017.
//

#ifndef HW2_ANALYST_H
#define HW2_ANALYST_H

#include "History.h"
#include <fstream>

class Analyst {
private:
    std::string m_name;
    std::string m_initials;
public:
    History m_tradeHistory;

    Analyst(std::string filePath);

    std::string getName();
    std::string getInitials();
};


#endif //HW2_ANALYST_H
