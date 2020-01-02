//
// Created by Minh To on 2019-11-18.
//
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder()
{
    m_name = "";
    m_product = "";
    m_cntItem = 0;
    m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder(const std::string &src)
{

    Utilities uObj;
    std::string tempSrc = src;
    size_t nextPos = 0;
    bool more = true;
    m_cntItem = 1;

    m_name = uObj.extractToken(tempSrc, nextPos, more);
    tempSrc.erase(0, tempSrc.find(uObj.getDelimiter()) + 1);
    m_product = uObj.extractToken(tempSrc, nextPos, more);
    tempSrc.erase(0, tempSrc.find(uObj.getDelimiter()) + 1);

    std::string tempSrcCount = tempSrc;
    while(tempSrcCount.find(uObj.getDelimiter()) != std::string::npos){
        //get a count of how many items needed
        m_cntItem++;
        tempSrcCount.erase(0, tempSrcCount.find(uObj.getDelimiter()) + 1);
    }

    //allocate dynamic memory
    m_lstItem = new ItemInfo*[m_cntItem];

    std::string tempItemString;
    for(size_t i = 0; i < m_cntItem; i++){
        ItemInfo *anItem = nullptr;
        //extract the token and put into tempItemString
        tempItemString = uObj.extractToken(tempSrc, nextPos, more);
        tempSrc.erase(0, tempSrc.find(uObj.getDelimiter()) + 1);
        //now make that string into an item
         anItem = new ItemInfo(tempItemString);

        //assign to
        m_lstItem[i] = anItem;
    }

    if(CustomerOrder::m_widthField < uObj.getFieldWidth()){
        CustomerOrder::m_widthField = uObj.getFieldWidth();
    }
}


CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
{
    m_lstItem = nullptr;
    *this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)
{
    if(this != &src){

        this->m_name = src.m_name;
        this->m_product = src.m_product;
        this->m_cntItem = src.m_cntItem;

        delete [] m_lstItem;
        m_lstItem = src.m_lstItem;
        src.m_lstItem = nullptr;
        src.m_name = "";
        src.m_product = "";
        src.m_cntItem = 0;
    }

    return *this;
}

CustomerOrder::~CustomerOrder()
{
    delete [] m_lstItem;
    m_lstItem = nullptr;

}

bool CustomerOrder::getItemFillState(std::string src) const
{
    bool filled = false;
    for(size_t i = 0; i < m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == src && m_lstItem[i]->m_fillState == true){
            filled = true;
        }
    }
    return filled;
}


bool CustomerOrder::getOrderFillState() const
{
    bool isFilled = false;
    size_t tempCntItems = 0;
    for(size_t i = 0; i < m_cntItem; i++){
        if((m_lstItem[i])->m_fillState ){
            tempCntItems++;
        }
    }
    if(tempCntItems == m_cntItem){

        isFilled = true;
    }

    return isFilled;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os)
{
    for(size_t i = 0; i < m_cntItem; i++){
        if(item.getName() == m_lstItem[i]->m_itemName){
            if(item.getQuantity() > 0) {
                item.updateQuantity();
                m_lstItem[i]->m_serialNumber = item.getSerialNumber();
                m_lstItem[i]->m_fillState = true;
                os << "Filled " << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
            }
            else{
                os << "Unable to fill" << m_name << ", " << m_product << "[" << item.getName() << "]" << std::endl;
            }
        }
    }
}


void CustomerOrder::display(std::ostream& os) const
{
    os << m_name << " - " << m_product << std::endl;
    //access the serial number for the item
    for(size_t i = 0; i < this->m_cntItem; i++){
        os << "[";
        os.width(6);
        os.fill('0');
        os << this->m_lstItem[i]->m_serialNumber << "] ";
        os.fill(' ');
        os.width(CustomerOrder::m_widthField + 1);
        os.setf(std::ios::left);
        os << this->m_lstItem[i]->m_itemName;
        os.unsetf(std::ios::left);


        if(getOrderFillState() == false){
            os.setf(std::ios::right);
            os << "- MISSING" << std::endl;
            os.unsetf(std::ios::right);
        }
        else{
            os.setf(std::ios::right);
            os << "- FILLED" << std::endl;
            os.unsetf(std::ios::right);
        }
    }
}


