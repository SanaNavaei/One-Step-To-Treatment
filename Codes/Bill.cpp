#include "Bill.hpp"

Bill::Bill(int cost_, int paid_, std::string description_)
{
    dept = cost_;
    paid = paid_;
    description = description_;
}

void Bill::setDebt(int precost)
{
    dept = dept - precost;
}

void Bill::setPaid(int precost)
{
    paid = paid + precost;
}

int Bill::getPaid()//new3
{
    return paid;
}

int Bill::getDept()//new3
{
    return dept;
}