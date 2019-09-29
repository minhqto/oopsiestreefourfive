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
        
        virtual void display(std::ostream& os) const
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

    template <class L, class V>
    class SummableLVPair : public LVPair<L, V>
    {
        static V initVal;
        static size_t minFieldWidth; 

        public:
        
        SummableLVPair(){}

        static const V& getInitialValue()
        {
            return initVal; //initVal must be static IOT to access it in a static member funciton
        }

        SummableLVPair(const L& lbl, const V& valu)
        {
            this->keke = lbl;
            this->val = valu;

            if(lbl.size() > minFieldWidth){
                minFieldWidth = lbl.size();
            }
            else{
                minFieldWidth = 0;
            }
        }

        //specization for two strins
        template<>
        SummableLVPair<std::string>(std::string lbl, std::string valu)
        {
            initVal = "";
            this->keke = lbl;
            this->val = valu;

            if(lbl.size() > minFieldWidth){
                minFieldWidth = lbl.size();
            }
        }

        
        SummableLVPair<std::string, int>(std::string lbl, int valu)
        {
            
        }

        V sum(const L& lbl, const V& valu) const
        {
            if(this->keke == lbl){
                valu += this->val;
            }
            return valu;
        }

        void display(std::ostream& os) const
        {
            os.setf(std::ios::left);
            os.width(minFieldWidth);
            //call display from parent class
            LVPair::display(os);
            os.setf(std::ios::right);
        }

        
    };
}



#endif
