#ifndef SUPPORTERSERVICE_HPP
#define SUPPORTERSERVICE_HPP

#include <iostream>
#include <vector>
#include "Supporter.hpp"

class SupporterService{
private:
    std::vector<Supporter*> supporter_list;
public:
    SupporterService(){}
    Supporter* setSupporter();
    void addSupporter(Supporter* sup);//new
    std::vector<Supporter*> getSupporters();//new
};

#endif