#include <iostream>
#include <string>
#include <iomanip>

template<typename A, typename B>
A addEm(A first, B second)
{
    return first + second;
}

template<>
std::string addEm(std::string first, std::string second)
{   
    std::cout << "Specialization called" << std::endl;
    return first;
}
