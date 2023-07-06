CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

ifeq ($(OS),Windows_NT)
	LDLIBS += -l Ws2_32
endif

all: $(BUILD_DIR) OSTT.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

OSTT.out : $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/main.o $(BUILD_DIR)/OneStepToTreatment.o $(BUILD_DIR)/Bankcard.o $(BUILD_DIR)/Bill.o $(BUILD_DIR)/ChoosePackageHandler.o $(BUILD_DIR)/ChooseSupporterHandler.o $(BUILD_DIR)/Document.o $(BUILD_DIR)/HCD_Service.o $(BUILD_DIR)/HospitalClinicDoctor.o $(BUILD_DIR)/LoginHandler.o $(BUILD_DIR)/Patient.o $(BUILD_DIR)/PatientService.o $(BUILD_DIR)/PayMoneyHandler.o $(BUILD_DIR)/Request2.o $(BUILD_DIR)/SendInfoHandler.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/Supporter.o $(BUILD_DIR)/SupporterService.o $(BUILD_DIR)/TreatmentPackageService.o $(BUILD_DIR)/TreatmentPackage.o $(BUILD_DIR)/TreatmentProcess.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/my_server.o $(BUILD_DIR)/errors.o $(BUILD_DIR)/DAO.o 
	$(CC) $(CF) $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/main.o $(BUILD_DIR)/OneStepToTreatment.o $(BUILD_DIR)/Bankcard.o $(BUILD_DIR)/Bill.o $(BUILD_DIR)/ChoosePackageHandler.o $(BUILD_DIR)/ChooseSupporterHandler.o $(BUILD_DIR)/Document.o $(BUILD_DIR)/HCD_Service.o $(BUILD_DIR)/HospitalClinicDoctor.o $(BUILD_DIR)/LoginHandler.o $(BUILD_DIR)/Patient.o $(BUILD_DIR)/PatientService.o $(BUILD_DIR)/PayMoneyHandler.o $(BUILD_DIR)/Request2.o $(BUILD_DIR)/SendInfoHandler.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/Supporter.o $(BUILD_DIR)/SupporterService.o $(BUILD_DIR)/TreatmentPackageService.o $(BUILD_DIR)/TreatmentPackage.o $(BUILD_DIR)/TreatmentProcess.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/my_server.o $(BUILD_DIR)/errors.o $(BUILD_DIR)/DAO.o -o OSTT.out

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/handlers.o: Codes/handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp Codes/PatientService.hpp Codes/Patient.hpp Codes/SignupHandler.hpp Codes/PatientService.hpp Codes/LoginHandler.hpp Codes/ChoosePackageHandler.hpp Codes/TreatmentPackageService.hpp Codes/PayMoneyHandler.hpp Codes/ChooseSupporterHandler.hpp Codes/SupporterService.hpp Codes/SendInfoHandler.hpp Codes/HCD_Service.hpp
	$(CC) $(CF) -c Codes/handlers.cpp -o $(BUILD_DIR)/handlers.o

$(BUILD_DIR)/my_server.o: Codes/my_server.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c Codes/my_server.cpp -o $(BUILD_DIR)/my_server.o

$(BUILD_DIR)/main.o : Codes/main.cpp Codes/OneStepToTreatment.hpp Codes/my_server.hpp Codes/DAO.hpp
	$(CC) $(CF) -c Codes/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/OneStepToTreatment.o : Codes/OneStepToTreatment.cpp Codes/OneStepToTreatment.hpp Codes/handlers.hpp
	$(CC) $(CF) -c Codes/OneStepToTreatment.cpp -o $(BUILD_DIR)/OneStepToTreatment.o

$(BUILD_DIR)/Bankcard.o : Codes/Bankcard.cpp Codes/Bankcard.hpp
	$(CC) $(CF) -c Codes/Bankcard.cpp -o $(BUILD_DIR)/Bankcard.o

$(BUILD_DIR)/Bill.o : Codes/Bill.cpp Codes/Bill.hpp
	$(CC) $(CF) -c Codes/Bill.cpp -o $(BUILD_DIR)/Bill.o

$(BUILD_DIR)/ChoosePackageHandler.o : Codes/ChoosePackageHandler.cpp Codes/ChoosePackageHandler.hpp Codes/TreatmentPackageService.hpp Codes/PatientRequest.hpp Codes/Patient.hpp
	$(CC) $(CF) -c Codes/ChoosePackageHandler.cpp -o $(BUILD_DIR)/ChoosePackageHandler.o

$(BUILD_DIR)/ChooseSupporterHandler.o : Codes/ChooseSupporterHandler.cpp Codes/ChooseSupporterHandler.hpp Codes/SupporterService.hpp Codes/PatientRequest.hpp Codes/Patient.hpp
	$(CC) $(CF) -c Codes/ChooseSupporterHandler.cpp -o $(BUILD_DIR)/ChooseSupporterHandler.o

$(BUILD_DIR)/Document.o : Codes/Document.cpp Codes/Document.hpp 
	$(CC) $(CF) -c Codes/Document.cpp -o $(BUILD_DIR)/Document.o

$(BUILD_DIR)/HCD_Service.o : Codes/HCD_Service.cpp Codes/HCD_Service.hpp Codes/HospitalClinicDoctor.hpp Codes/Patient.hpp
	$(CC) $(CF) -c Codes/HCD_Service.cpp -o $(BUILD_DIR)/HCD_Service.o

$(BUILD_DIR)/HospitalClinicDoctor.o : Codes/HospitalClinicDoctor.cpp Codes/HospitalClinicDoctor.hpp Codes/Patient.hpp
	$(CC) $(CF) -c Codes/HospitalClinicDoctor.cpp -o $(BUILD_DIR)/HospitalClinicDoctor.o

$(BUILD_DIR)/LoginHandler.o : Codes/LoginHandler.cpp Codes/LoginHandler.hpp Codes/PatientService.hpp Codes/errors.hpp
	$(CC) $(CF) -c Codes/LoginHandler.cpp -o $(BUILD_DIR)/LoginHandler.o

$(BUILD_DIR)/Patient.o : Codes/Patient.cpp Codes/Patient.hpp Codes/Document.hpp Codes/Bill.hpp Codes/Bankcard.hpp Codes/PatientRequest.hpp Codes/Supporter.hpp
	$(CC) $(CF) -c Codes/Patient.cpp -o $(BUILD_DIR)/Patient.o

$(BUILD_DIR)/PatientService.o : Codes/PatientService.cpp Codes/PatientService.hpp Codes/Patient.hpp
	$(CC) $(CF) -c Codes/PatientService.cpp -o $(BUILD_DIR)/PatientService.o

$(BUILD_DIR)/PayMoneyHandler.o : Codes/PayMoneyHandler.cpp Codes/PayMoneyHandler.hpp Codes/PatientRequest.hpp Codes/Patient.hpp
	$(CC) $(CF) -c Codes/PayMoneyHandler.cpp -o $(BUILD_DIR)/PayMoneyHandler.o

$(BUILD_DIR)/Request2.o : Codes/PatientRequest.cpp Codes/PatientRequest.hpp Codes/TreatmentPackage.hpp
	$(CC) $(CF) -c Codes/PatientRequest.cpp -o $(BUILD_DIR)/Request2.o

$(BUILD_DIR)/SendInfoHandler.o : Codes/SendInfoHandler.cpp Codes/SendInfoHandler.hpp Codes/HCD_Service.hpp Codes/Patient.hpp Codes/Supporter.hpp
	$(CC) $(CF) -c Codes/SendInfoHandler.cpp -o $(BUILD_DIR)/SendInfoHandler.o

$(BUILD_DIR)/SignupHandler.o : Codes/SignupHandler.cpp Codes/SignupHandler.hpp Codes/PatientService.hpp server/server.hpp
	$(CC) $(CF) -c Codes/SignupHandler.cpp -o $(BUILD_DIR)/SignupHandler.o

$(BUILD_DIR)/Supporter.o : Codes/Supporter.cpp Codes/Supporter.hpp
	$(CC) $(CF) -c Codes/Supporter.cpp -o $(BUILD_DIR)/Supporter.o

$(BUILD_DIR)/SupporterService.o : Codes/SupporterService.cpp Codes/SupporterService.hpp Codes/Supporter.hpp
	$(CC) $(CF) -c Codes/SupporterService.cpp -o $(BUILD_DIR)/SupporterService.o

$(BUILD_DIR)/TreatmentPackageService.o : Codes/TreatmentPackageService.cpp Codes/TreatmentPackageService.hpp Codes/TreatmentPackage.hpp
	$(CC) $(CF) -c Codes/TreatmentPackageService.cpp -o $(BUILD_DIR)/TreatmentPackageService.o

$(BUILD_DIR)/TreatmentPackage.o : Codes/TreatmentPackage.cpp Codes/TreatmentPackage.hpp 
	$(CC) $(CF) -c Codes/TreatmentPackage.cpp -o $(BUILD_DIR)/TreatmentPackage.o

$(BUILD_DIR)/TreatmentProcess.o : Codes/TreatmentProcess.cpp Codes/TreatmentProcess.hpp
	$(CC) $(CF) -c Codes/TreatmentProcess.cpp -o $(BUILD_DIR)/TreatmentProcess.o

$(BUILD_DIR)/errors.o : Codes/errors.cpp Codes/errors.hpp
	$(CC) $(CF) -c Codes/errors.cpp -o $(BUILD_DIR)/errors.o

$(BUILD_DIR)/DAO.o : Codes/DAO.cpp Codes/DAO.hpp
	$(CC) $(CF) -c Codes/DAO.cpp -o $(BUILD_DIR)/DAO.o

clean :
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null