
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>
#include "Item.h"
#include "Utilities.h"

struct ItemInfo{
    std::string m_itemName;
    size_t m_serialNumber = 0;
    bool m_fillState = false;

    ItemInfo(std::string src) : m_itemName(src){};
};


class CustomerOrder{

    std::string m_name;
    std::string m_product;
    size_t m_cntItem;
    ItemInfo** m_lstItem = nullptr; //an array of ItemInfo pointers
    static size_t m_widthField;

    public:

    CustomerOrder();
    CustomerOrder(const std::string&);
    CustomerOrder(const CustomerOrder&){throw "Copying not allowed!";};
    CustomerOrder& operator=(const CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder&&) noexcept;
    CustomerOrder& operator=(CustomerOrder&&);
    ~CustomerOrder();
    bool getItemFillState(std::string) const;
    bool getOrderFillState() const;
    void fillItem(Item&, std::ostream&);
    void display(std::ostream&) const;
};


#endif
