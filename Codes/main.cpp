#include "OneStepToTreatment.hpp"
#include "DAO.hpp"

int main()
{
    PatientService *patient_service = new PatientService();
    SignupHandler *signup_handler = new SignupHandler(patient_service);
    LoginHandler *login_handler = new LoginHandler(patient_service);
    TreatmentPackageService *treatment_package_service = new TreatmentPackageService();
    ChoosePackageHandler *choose_package_handler = new ChoosePackageHandler(treatment_package_service);
    PayMoneyHandler *pay_money_handler = new PayMoneyHandler();
    SupporterService *supporter_service = new SupporterService();
    ChooseSupporterHandler *choose_supporter_handler = new ChooseSupporterHandler(supporter_service);
    HCD_Service *hcd_service = new HCD_Service();
    SendInfoHandler *send_info_handler = new SendInfoHandler(hcd_service, supporter_service, treatment_package_service, patient_service);

    DAO *dao_layer = new DAO(patient_service, treatment_package_service, supporter_service, hcd_service);
    dao_layer->read_data_base();

    OneStepToTreatment *ourWebsite = new OneStepToTreatment(patient_service, signup_handler, login_handler, treatment_package_service,
                                                            choose_package_handler, pay_money_handler, supporter_service,
                                                            choose_supporter_handler, hcd_service, send_info_handler);
    ourWebsite->run();

    dao_layer->update_data_base();

    return 0;
}