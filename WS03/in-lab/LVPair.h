// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca    
// Date of completion: 25 Sep 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef LVPAIR_H
#define LVPAIR_H

#include <iostream>
#include <string>
#include <iomanip>
namespace sdds
{
    template<class L, class V>
    class LVPair{
        L keke;
        V val;
    
    public:

        LVPair() : keke(), val() {}

        LVPair(const L& aa, const V& bb)
        {
            keke = aa;
            val = bb;
        }

        const L& key() const
        {
            return keke;
        }
        
        const V& value() const
        {
            return val;
        }
        
        void display(std::ostream& os) const
        {
            os << keke << " : " << val << std::endl;
        }
    };

    template<class L, class V>
    std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair)
    {
        pair.display(os);
        return os;
    }
}

#endif
