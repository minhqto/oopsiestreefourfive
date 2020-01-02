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
LineManager::LineManager(const std::string& src, std::vector<Task*>& task_vec, std::vector<CustomerOrder>& cust_vec) {
    Utilities utilObj;
    size_t nextPos = 0;
    bool more = true;
    std::string tempLine;
    std::fstream file(src);
    m_cntCustomerOrder = cust_vec.size();
    std::string task1;
    std::string task2;
    //takes in the file
    do {
        std::getline(file, tempLine);
        task1 = utilObj.extractToken(tempLine, nextPos, more);
        tempLine.erase(0, tempLine.find(utilObj.getDelimiter())+1);
        task2 = utilObj.extractToken(tempLine, nextPos, more);

        for(auto i : task_vec){
            if(i->getName() == task1){
                for(auto k : task_vec){
                    if(k->getName() == task2 && task1 != task2){
                        i->setNextTask(*k);
                    }
                }
            }
        }

    } while (file && file.good());

    std::vector<Task*>::iterator it;
    for(it = task_vec.begin(); it != task_vec.end(); it++){
        this->AssemblyLine.push_back(*it);
    }

    std::vector<CustomerOrder>::iterator it2;
    for(it2 = cust_vec.begin(); it2 != cust_vec.end(); it2++){
        this->ToBeFilled.push_front(std::move(*it2));
    }

}
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
    bool isFilled = false;
    CustomerOrder completedOrder;

    if(!ToBeFilled.empty()){
        *this->AssemblyLine.back() += std::move(ToBeFilled.back());
        ToBeFilled.pop_back();
    }
    for(size_t i = 0; i < AssemblyLine.size(); i++){
        this->AssemblyLine[i]->runProcess(std::cout);
    }

    for(size_t i = 0; i < AssemblyLine.size(); i++){
        this->AssemblyLine[i]->moveTask();
        if(AssemblyLine[i]->getCompleted(completedOrder)) {
            Completed.push_back(std::move(completedOrder));
        }
    }

    if(Completed.size() == m_cntCustomerOrder){
        isFilled = true;
    }
    return isFilled;
}

/*
 * -- displays all the orders that were completed
 * */

void LineManager::displayCompleted(std::ostream& os) const
{
    for(size_t i = 0; i < Completed.size(); i++){
        Completed[i].display(std::cout);
    }
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
