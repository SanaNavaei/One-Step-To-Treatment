#include "OneStepToTreatment.hpp"
#include "my_server.hpp"

#include <sstream>
#include <fstream>
#include <string>

OneStepToTreatment::OneStepToTreatment(PatientService *patient_service_, SignupHandler *signup_handler_, LoginHandler *login_handler_, TreatmentPackageService *treatment_package_service_,
                                       ChoosePackageHandler *choose_package_handler_, PayMoneyHandler *pay_money_handler_, SupporterService *supporter_service_,
                                       ChooseSupporterHandler *choose_supporter_handler_, HCD_Service *hcd_service_, SendInfoHandler *send_info_handler_)
{
    patient_service = patient_service_;
    signup_handler = signup_handler_;
    login_handler = login_handler_;
    treatment_package_service = treatment_package_service_;
    choose_package_handler = choose_package_handler_;
    pay_money_handler = pay_money_handler_;
    supporter_service = supporter_service_;
    choose_supporter_handler = choose_supporter_handler_;
    hcd_service = hcd_service_;
    send_info_handler = send_info_handler_;
}

void OneStepToTreatment::run()
{
    srand(time(NULL)); // for rand
    signup_handler->setOSTT(this);
    login_handler->setOSTT(this);
    choose_package_handler->setOSTT(this);
    pay_money_handler->setOSTT(this);
    choose_supporter_handler->setOSTT(this);
    send_info_handler->setOSTT(this);
    try
    {
        MyServer server(5000);
        server.get("/", new ShowPage("html/main.html"));
        server.get("/main_css", new ShowPage("html/css/main.css"));
        server.get("/icon", new ShowImage("html/images/icon.png"));
        server.get("/main_background", new ShowImage("html/images/mainpage.jpg"));
        server.get("/background", new ShowImage("html/images/main2.avif"));
        server.get("/show_signup", new ShowPage("html/signup.html"));
        server.get("/signup", signup_handler);
        server.get("/show_login", new ShowPage("html/login.html"));
        server.get("/login", login_handler);
        server.get("/show_package", new ShowPage("html/package.html"));
        server.get("/midwifery", new ShowImage("html/images/midwifery.jpg"));
        server.get("/orthopedics", new ShowImage("html/images/orthopedics.jpeg"));
        server.get("/General", new ShowImage("html/images/General surgery.jpg"));
        server.get("/ENT", new ShowImage("html/images/ENT.jpg"));
        server.get("/diabet", new ShowImage("html/images/diabet.jpg"));
        server.get("/kidney", new ShowImage("html/images/kidney.jpg"));
        server.get("/package", choose_package_handler);
        server.get("/show_paymoney", new ShowPage("html/payMoney.html"));
        server.get("/payMoneyBackground", new ShowImage("html/images/moneyBackground.jpg"));
        server.get("/paymoney", pay_money_handler);
        server.get("/supporter", choose_supporter_handler);
        server.get("/sendInfo", send_info_handler);
        server.get("/Thank_show", new ShowPage("html/thanks.html"));
        server.get("/thankyou", new ShowImage("html/images/thankyou.jpg"));
        server.run();
    }
    catch (const Server::Exception &e)
    {
        std::cerr << e.getMessage() << std::endl;
    }
}

void OneStepToTreatment::setPatient(Patient *patient_)
{
    current_patient = patient_;
}

Patient *OneStepToTreatment::getPatient()
{
    return current_patient;
}

void OneStepToTreatment::setRequest(PatientRequest *req_)
{
    req = req_;
}

PatientRequest *OneStepToTreatment::getRequest()
{
    return req;
}

void OneStepToTreatment::setSupporter(Supporter *supporter_)
{
    supporter = supporter_;
}

Supporter *OneStepToTreatment::getSupporter()
{
    return supporter;
}