#include <fstream>
#include <sstream>
#include <string>
#include "DAO.hpp"
#include "PatientService.hpp"
#include "TreatmentPackageService.hpp"
#include "TreatmentPackage.hpp"
#include "SupporterService.hpp"
#include "HCD_Service.hpp"

DAO::DAO(PatientService *patient_service_, TreatmentPackageService *treatment_package_service_, SupporterService *supporter_service_, HCD_Service *hcd_service_)
{
    patient_service = patient_service_;
    treatment_package_service = treatment_package_service_;
    supporter_service = supporter_service_;
    hcd_service = hcd_service_;
}

void DAO::read_data_base()
{
    std::ifstream packages_file("Database/packageFile.txt");
    std::string line;

    int ID, capacity, estimated_cost;
    std::string token, name;
    long long t;

    while (std::getline(packages_file, line))
    {
        std::stringstream ss(line);
        ss >> token;
        ID = std::atoi(token.c_str());
        ss >> token;
        name = token;
        ss >> token;
        estimated_cost = std::atoi(token.c_str());
        ss >> token;
        t = std::atoi(token.c_str());
        ss >> token;
        capacity = std::atoi(token.c_str());
        TreatmentPackage *treatment_package = new TreatmentPackage(ID, name, estimated_cost, t, capacity);
        treatment_package_service->addPackage(treatment_package);
    }
    packages_file.close();

    std::vector<TreatmentPackage *> package_list = treatment_package_service->getPackages();

    std::ifstream supporters_file("Database/supporterFile.txt");
    std::string email, phone_number, status;
    int rank;

    while (std::getline(supporters_file, line))
    {
        std::stringstream ss(line);
        ss >> token;
        name = token;
        ss >> token;
        rank = std::atoi(token.c_str());
        ss >> token;
        email = token;
        ss >> token;
        phone_number = token;
        ss >> token;
        status = token;
        Supporter *supporter = new Supporter(name, rank, email, phone_number, status);
        supporter_service->addSupporter(supporter);
    }
    supporters_file.close();

    std::ifstream hcd_file("Database/hcdFile.txt");
    std::string password, hos_name;

    while (std::getline(hcd_file, line))
    {
        std::stringstream ss(line);
        ss >> name;
        ss >> password;
        ss >> email;
        ss >> hos_name;
        ss >> status;
        HospitalClinicDoctor *hcd = new HospitalClinicDoctor(name, password, email, hos_name, status);
        hcd_service->addHCD(hcd);
    }
    hcd_file.close();
}

void DAO::update_data_base()
{
    std::ofstream packages_file;
    packages_file.open("Database/packageFile.txt", std::ios::trunc);
    std::vector<TreatmentPackage *> package_list = treatment_package_service->getPackages();
    for (int i = 0; i < package_list.size(); i++)
    {
        std::string info = package_list[i]->getInfo();
        packages_file << info << std::endl;
    }
    packages_file.close();

    std::ofstream supporters_file;
    supporters_file.open("Database/supporterFile.txt", std::ios::trunc);
    std::vector<Supporter *> supporter_list = supporter_service->getSupporters();
    for (int i = 0; i < supporter_list.size(); i++)
    {
        std::string info = supporter_list[i]->getInfo();
        supporters_file << info << std::endl;
    }
    supporters_file.close();

    std::ofstream hcd_file;
    hcd_file.open("Database/hcdFile.txt", std::ios::trunc);
    std::vector<HospitalClinicDoctor *> hcd_list = hcd_service->getHCDs();
    for (int i = 0; i < hcd_list.size(); i++)
    {
        std::string info = hcd_list[i]->getInfo();
        hcd_file << info << std::endl;
    }
    hcd_file.close();

    std::ofstream requests_file;
    requests_file.open("Database/requstFile.txt", std::ios::trunc);
    std::vector<Patient *> patient_list = patient_service->getPatients();
    for (int i = 0; i < patient_list.size(); i++)
    {
        std::vector<PatientRequest *> request_list = patient_list[i]->getRequests();
        for (int j = 0; j < request_list.size(); j++)
        {
            std::string info = request_list[j]->getInfo();
            info += " ";
            info += patient_list[i]->getEmail();
            requests_file << info << std::endl;
        }
    }
    requests_file.close();
}
