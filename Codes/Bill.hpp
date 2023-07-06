#ifndef BILL_HPP
#define BILL_HPP

#include <iostream>

class Bill{
private:
    std::string description;///
    int dept;
    int paid;
public:
    Bill(int cost_, int paid_, std::string description);
    //std::string getBill();///?string
    void setDebt(int precost);//
    void setPaid(int precost);//
    void checkPay();
    int getPaid();//new3
    int getDept();//new3
};

#endif