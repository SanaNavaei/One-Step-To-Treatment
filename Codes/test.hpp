#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#include "PatientService.hpp"

#include "ChoosePackageHandler.hpp"
#include "TreatmentPackageService.hpp"

#include "PayMoneyHandler.hpp"

#include "ChooseSupporterHandler.hpp"
#include "SupporterService.hpp"


class Test{
private:
public:
    Test(){}
    bool test_reserve_package();
    bool test_adding_request();
    bool test_pay_money();
    bool test_choose_supporter();
    void test_run();
};

#endif
