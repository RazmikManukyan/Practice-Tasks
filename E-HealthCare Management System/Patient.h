#ifndef E_HEALTHCARE_MANAGEMENT_SYSTEM_PATIENT_H
#define E_HEALTHCARE_MANAGEMENT_SYSTEM_PATIENT_H
#include <iostream>

class Patient{
public:
    std::string name;
    int dataOfBirth;
    std::string gender;
    std::string contactInfo;
    std::string medicalCondition;
public:
    Patient(const std::string &name, int dataOfBirth, const std::string &gender, const std::string &contactInfo,
            const std::string &medicalCondition)
            : name(name), dataOfBirth(dataOfBirth), gender(gender), contactInfo(contactInfo){}

    const std::string &getName() const {
        return name;
    }

    int getDataOfBirth() const {
        return dataOfBirth;
    }

    const std::string &getGender() const {
        return gender;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }

    const std::string &getMedicalCondition() const {
        return medicalCondition;
    }

};



#endif //E_HEALTHCARE_MANAGEMENT_SYSTEM_PATIENT_H
