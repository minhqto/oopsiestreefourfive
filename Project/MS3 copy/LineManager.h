//
// Created by Minh To on 2019-11-23.
//

#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <vector>
#include <deque>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "Task.h"
#include "CustomerOrder.h"
#include "Utilities.h"


class LineManager{
    std::vector<Task*> AssemblyLine;
    std::deque<CustomerOrder> ToBeFilled;
    std::deque<CustomerOrder> Completed;
    unsigned int m_cntCustomerOrder;

    public:

    LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
    bool run(std::ostream&);
    void displayCompleted(std::ostream&) const;
    void validateTasks() const;

};

#endif
