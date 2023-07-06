#ifndef ONESTEPTOTREATMENT_HPP
#define ONESTEPTOTREATMENT_HPP

#include <iostream>

#include "SignupHandler.hpp"
#include "PatientService.hpp"

#include "LoginHandler.hpp"

#include "ChoosePackageHandler.hpp"
#include "TreatmentPackageService.hpp"

#include "PayMoneyHandler.hpp"

#include "ChooseSupporterHandler.hpp"
#include "SupporterService.hpp"

#include "SendInfoHandler.hpp"
#include "HCD_Service.hpp"
#define PERCENTAGE 25

class Patient;
class PatientRequest;

class OneStepToTreatment
{
private:
    Patient *current_patient;
    Supporter *supporter;
    PatientRequest *req;
    PatientService *patient_service;
    SignupHandler *signup_handler;
    LoginHandler *login_handler;
    TreatmentPackageService *treatment_package_service;
    ChoosePackageHandler *choose_package_handler;
    PayMoneyHandler *pay_money_handler;
    SupporterService *supporter_service;
    ChooseSupporterHandler *choose_supporter_handler;
    HCD_Service *hcd_service;
    SendInfoHandler *send_info_handler;

public:
    OneStepToTreatment(PatientService *patient_service_, SignupHandler *signup_handler_, LoginHandler *login_handler_, TreatmentPackageService *treatment_package_service_,
                       ChoosePackageHandler *choose_package_handler_, PayMoneyHandler *pay_money_handler_, SupporterService *supporter_service_,
                       ChooseSupporterHandler *choose_supporter_handler_, HCD_Service *hcd_service_, SendInfoHandler *send_info_handler_);
    void run();
    void setPatient(Patient *patient_);
    void setRequest(PatientRequest *req_);
    void setSupporter(Supporter *supporter_);

    Patient *getPatient();
    PatientRequest *getRequest();
    Supporter *getSupporter();
};

#endif