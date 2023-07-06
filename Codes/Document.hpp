#ifndef DOCUMENT_HPP
#define DOCUMENT_Hpp

#include <iostream>

class Document{
private:
    std::string status;
    std::string DiseaseBackground;
    std::string KindOfDisease;
    int age;
public:
    Document(std::string document);
    bool DocExists();
};

#endif