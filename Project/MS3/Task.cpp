//
// Created by Minh To on 2019-11-23.
//

#include "Task.h"

/*
   * - a custom constructor -- upon instantiation, a `Task` object receives a reference to an u
   * nmodifiable `std::string`.  This string contains a single record (one line) that has been retrieved from
   * the input file specified by the user to be used for `Item` instantiation.
- this constructor will also set the `m_pNextTask` to a safe state.
- A `Task` object represents a single location on the assembly line for filling items into customer orders.
 Therefore, a `Task` object cannot be copied or moved.   You must make sure this capability has been deleted from
 your `Task` definition.
*/

Task::Task(const std::string& src) : Item(src)
{
    m_pNextTask = nullptr;
}

    /*- `void runProcess(std::ostream&)` – runs a single cycle of the assembly line for the current task.
- If there are `CustomerOrders` in the queue, it will verify the fill status of the **last** `CustomerOrder`
     and fill it if the order contains the `Item` specified by the current `Task`.
     */

    //if the orders queue is NOT empty, check the fill state of the ITEM (hint a task IS an item), if the fill state of the item is FALSE, call fillItem().

    void Task::runProcess(std::ostream& os)
{
    if(!m_orders.empty()){
        if(!m_orders.back().getItemFillState(m_pNextTask->getName())){
            m_orders.back().fillItem(*m_pNextTask ,os);
        }
    }
}
/*
   - `bool moveTask()` – moves the last `CustomerOrder` in the queue to the next task on the assembly line
   if the orders fill state for the current `Item` is true.  Otherwise, the `CustomerOrder` should remain
   in the queue for the next processing cycle.   If the queue is empty, return false.
*/
bool Task::moveTask()
{
    bool isMoved = false;
    if(!this->m_orders.empty()){
        if(this->m_orders.back().getItemFillState(this->getName())){
            //the object in the deque is a customerOrder object. need to move it to the next task.

        }
    }

    return isMoved;

}

/*
   - `void setNextTask(Task&)` – stores the provided `Task` object's reference into the `m_pNextTask` pointer.
*/
void Task::setNextTask(Task& tk)
{
    m_pNextTask = nullptr;
    m_pNextTask = &tk;
}

/*
   - `bool getCompleted(CustomerOrder&)` – Removes the last `CustomerOrder` from the queue,
   places it in the parameter and returns true.   If the `CustomerOrder` queue is empty, return false.
*/
bool Task::getCompleted(CustomerOrder& custOrd)
{
    bool notEmpty = true;
    if(m_orders.empty()){
        notEmpty = false;
    }
    else{
        custOrd = std::move(m_orders.back());
    };

    return notEmpty;

}
/*   - `void validate(std::ostream&)` – writes the name of the `Item` this `Task` is responsible for into
 * the parameter: `ITEM_NAME --> NEXT_ITEM_NAME`
- if `m_pNextTask` does not exist it writes: `ITEM_NAME --> END OF LINE`.
- the messages are terminated with an endline*/

void Task::validate(std::ostream& os)
{
    if(m_pNextTask == nullptr){
        os << this->getName() << "-->" << "END OF LINE";
    }
    else{
        os << this->getName() << "-->"  << this->m_pNextTask->getName();
    }

}

/*
   - `Task& operator+=(CustomerOrder&&)` – Moves the parameter onto the front of the `CustomerOrder` queue.
   * */

Task& Task::operator+=(CustomerOrder&& moveCustOrd)
{
    m_orders.push_front(moveCustOrd);
    return *this;
}