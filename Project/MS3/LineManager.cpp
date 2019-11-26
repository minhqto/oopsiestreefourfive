//
// Created by Minh To on 2019-11-23.
//

#include "LineManager.h"

/*
 custom constructor
  - with the following arguments:
    - a reference to an unmodifiable `std::string`.  This string contains the filename specified by the user to
    be used for linking the assembly line objects (example:  `AssemblyLine.dat`)
    - a reference to a `std::vector<Task*>` that contains the addresses of all the `Task` objects created for the
    assembly line
    - a reference to a `std::vector<CustomerOrder>` that contains all the `CustomerOrder` objects to be filled
  - the constructor will:

    - read the records from file and setup all the `m_pNextTask` references in the `Task` objects, Linking each `Task`
    object together to form the assembly line
    - Move all the `CustomerOrder` objects onto the front of the `ToBeFilled` queue
    - Copy all the `Task` objects into the `AssemblyLine` container
 * */
LineManager::LineManager(const std::string& src, std::vector<Task*>& task_vec, std::vector<CustomerOrder>& cust_vec)
{
    //called only once
    //src is the actual file name
    Utilities utilObj;
    size_t nextPos = 0;
    bool more = true;
    std::string taskString = "";

    for(auto it : task_vec){
        while(taskString.find(utilObj.getDelimiter()) != std::string::npos){
            taskString = utilObj.extractToken(src, nextPos, more);
            Task tempTask(taskString);
            it->setNextTask(tempTask);
        }

    }



}

/*LineManager::LineManager(const LineManager& src)
{
    if(this != &src){
        *this = src;
    }
}

LineManager& LineManager::operator=(const LineManager& src)
{
    if(this != &src){
        this->m_cntCustomerOrder = src.m_cntCustomerOrder;

    }
}

LineManager::LineManager(LineManager&& m_src)
{

}

LineManager LineManager::operator=(LineManager&& m_src)
{

}*/

/*
 * `bool run(std::ostream&)` –  this function performs **one** cycle of operations on the assembly line by doing
 * the following:
  - If there are any `CustomerOrder` objects in the `ToBeFilled` queue, move the last `CustomerOrder` object onto
  the starting point of the `AssemblyLine` (you have to identify which task is the starting point of your assembly line)
  - Loop through all tasks on the assembly line and run one cycle of the task's process
  - Loop through all tasks on the assembly line and move the `CustomerOrder` objects down the line.
    - **Hint:**  completed orders should be moved into the `Completed` queue.
  - return `true` if all customer orders have been filled, otherwise returns `false`.
 * */
bool LineManager::run(std::ostream& os)
{

}

/*
 * -- displays all the orders that were completed
 * */

void LineManager::displayCompleted(std::ostream& os) const
{

}

/*
 *  validates each task on the assembly line
 * */

void LineManager::validateTasks() const
{
    for(auto it : AssemblyLine){
        it->validate(std::cout);
    }
}
