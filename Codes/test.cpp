#include "test.hpp"

bool Test::test_reserve_package(/*check if capacity being reduced*/)
{
    TreatmentPackageService* TPS = new TreatmentPackageService();
    TreatmentPackage* package = new TreatmentPackage(2, "name", 1000, 16, 3);
    TPS->addPackage(package);
    TPS->reservePackage(2);
    if(package->getCapacity() == 2)
        return true;
    return false;
}

bool Test::test_adding_request()
{
    Document* document = new Document("kindOfdisease, diseaseBackground");
    BankCard* bank_card = new BankCard("963523","1211");
    Patient * patient = new Patient("maryam", "1234", "maryam@gmail.com", "09144749754", document, bank_card);
    TreatmentPackage* package = new TreatmentPackage(2, "name", 1000, 1223, 3);
    TreatmentPackageService* TPS = new TreatmentPackageService();
    TPS->addPackage(package);

    ChoosePackageHandler* CPH = new ChoosePackageHandler(TPS);
    CPH->ChoosePackageTreatment(patient, 2);
    if(patient->getBill()->getDept() == 1000)
        return true;
    return false;
}



bool Test::test_pay_money()
{

    Document* document = new Document("kindOfdisease, diseaseBackground");
    BankCard* bank_card = new BankCard("963523","1211");
    Patient * patient = new Patient("maryam", "1234", "maryam@gmail.com", "09144749754", document, bank_card);
    TreatmentPackage* package = new TreatmentPackage(2, "name", 1000, 1223, 3);
    //PatientRequest* request = new PatientRequest(123, package);
    TreatmentPackageService* TPS = new TreatmentPackageService();
    TPS->addPackage(package);
    ChoosePackageHandler* CPH = new ChoosePackageHandler(TPS);
    PatientRequest* request = CPH->ChoosePackageTreatment(patient, 2);
    PayMoneyHandler* PMH = new PayMoneyHandler();
    PMH->PayMoney(request, patient, 25);
    Bill* bill = patient->getBill();
    if(bill->getDept() == 750 && bill->getPaid() == 250)
        return true;
    return false;
}

bool Test::test_choose_supporter()
{
    SupporterService* supS = new SupporterService();
    ChooseSupporterHandler* CSH = new ChooseSupporterHandler(supS);
    Supporter* supporter = new Supporter("name", 3, "email", "phonenumber", "available");
    supS->addSupporter(supporter);
    Document* document = new Document("kindOfdisease, diseaseBackground");
    BankCard* bank_card = new BankCard("963523","1211");
    Patient * patient = new Patient("maryam", "1234", "maryam@gmail.com", "09144749754", document, bank_card);
    TreatmentPackage* package = new TreatmentPackage(2, "name", 1000, 1223, 3);
    //PatientRequest* request = new PatientRequest(123, package);
    TreatmentPackageService* TPS = new TreatmentPackageService();
    TPS->addPackage(package);
    ChoosePackageHandler* CPH = new ChoosePackageHandler(TPS);
    PatientRequest* request = CPH->ChoosePackageTreatment(patient, 2);
    PayMoneyHandler* PMH = new PayMoneyHandler();
    PMH->PayMoney(request, patient, 25);
    Supporter* sup = CSH->ChooseSupporter(request, patient);
    if(sup->getStatus() == "busy")
        if(patient->getSup() == sup)
            if(request->getStatus() == "sup assigned")
                return true;
                
    return false;
}


void Test::test_run()
{
    if(!test_reserve_package())
        std::cout << "error in reserve_package method catched!\n";
    else if(!test_adding_request())
        std::cout << "error in adding request catched!\n";
    else if(!test_pay_money())
        std::cout << "error in pay money handler catched!\n";
    else if(!test_choose_supporter())
        std::cout << "error in choose supporeter handler cathced!\n";
    else
        std::cout << "passed all tests! successfully done!\n";
}
