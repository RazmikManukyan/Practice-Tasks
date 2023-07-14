#ifndef E_HEALTHCARE_MANAGEMENT_SYSTEM_DOCTOR_H
#define E_HEALTHCARE_MANAGEMENT_SYSTEM_DOCTOR_H
#include <iostream>

class Doctor {
private:
    std::string name;
    std::string specialization;
    int yearOfExperience;
    std::string contactInfo;
public:
    Doctor(const std::string& name, const std::string& specialization, int yearOfExperience, const std::string& contactInfo)
            :name(name), specialization(specialization), yearOfExperience(yearOfExperience), contactInfo(contactInfo) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getSpecialization() const {
        return specialization;
    }

    int getYearOfExperience() const {
        return yearOfExperience;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }
};

#endif //E_HEALTHCARE_MANAGEMENT_SYSTEM_DOCTOR_H
