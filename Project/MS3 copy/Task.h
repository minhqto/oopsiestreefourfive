//
// Created by Minh To on 2019-11-23.
//

#ifndef TASK_H
#define TASK_H

#include <deque>
#include <string>
#include <iostream>
#include "Item.h"
#include "CustomerOrder.h"



/*The `Task` class is a simulation of a station on the assembly line and
 * contains all the functionality for filling customer orders with items.
 * Each `Task` is responsible for a particular `Item`, through inheritance.
 * */

class Task : public Item{

    std::deque<CustomerOrder> m_orders;
    Task *m_pNextTask;

    public:

    Task(const std::string&);
    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;
    Task(Task&&) = delete;
    Task operator=(Task&&) = delete;
    void runProcess(std::ostream&);
    bool moveTask();
    void setNextTask(Task&);
    bool getCompleted(CustomerOrder&);
    void validate(std::ostream&);
    Task& operator+=(CustomerOrder&&);

};


#endif //TASK_H
