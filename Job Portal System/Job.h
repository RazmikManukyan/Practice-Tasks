#ifndef JOB_PORTAL_SYSTEM_JOB_H
#define JOB_PORTAL_SYSTEM_JOB_H
#include <iostream>
#include <vector>

class Job {
    std::string title;
    std::string description;
    std::string requirements;
    double salary;
    std::string company;
    bool isField;
    std::vector<std::string> applicants;
public:
    Job(const std::string &title, const std::string &description, const std::string &requirements, double salary,
        const std::string &company)
            : title(title), description(description), requirements(requirements), salary(salary), company(company),
              isField(false) {}

    const std::string &getTitle() const {
        return title;
    }

    const std::string &getDescription() const {
        return description;
    }

    const std::string &getRequirements() const {
        return requirements;
    }

    double getSalary() const {
        return salary;
    }

    const std::string &getCompany() const {
        return company;
    }

    bool getIsField() const {
        return isField;
    }

    const std::vector<std::string> &getApplicants() const {
        return applicants;
    }

    void addApplicant(const std::string& applicant){
        applicants.push_back(applicant);
    }


};

#endif //JOB_PORTAL_SYSTEM_JOB_H
