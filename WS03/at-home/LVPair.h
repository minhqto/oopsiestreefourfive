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

	//derived class
    template <class L, class V>
    class SummableLVPair : public LVPair<L, V>
    {
        static V initVal;
		static size_t minFieldWidth;

        public:
        
        SummableLVPair(){}

        SummableLVPair(const L& lbl, const V& valu) : LVPair<L, V>(lbl, valu)
        {
            if(lbl.size() > minFieldWidth){
                minFieldWidth = lbl.size();
            }
        }

		static const V& getInitialValue()
		{
			return initVal; //initVal must be static IOT to access it in a static member funciton
		}

        V sum(const L& lbl, const V& valu) const
        {
			V tempVal;
            if(this->key() == lbl){
                tempVal = this->value() + valu;
            }
			else{
				tempVal = valu;
			}
			return tempVal;
            
        }

        virtual void display(std::ostream& os) const
        {
            os.setf(std::ios::left);
            os.width(minFieldWidth);
            //call display from parent class
            LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
        
        }
    };

	template<>
	std::string SummableLVPair<std::string, std::string>::initVal = "";

	template<>
	int SummableLVPair<std::string, int>::initVal = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& valu) const
	{
		if (valu == "") {
			return valu + this->value();
		}
		else {
			return valu + ", " + this->value();
		}
		
	}

	//initialization of static data member minFieldWidth
	template<class L, class V>
	size_t SummableLVPair<L, V>::minFieldWidth = 0;

}



#endif
