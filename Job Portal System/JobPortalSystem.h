#ifndef JOB_PORTAL_SYSTEM_JOBPORTALSYSTEM_H
#define JOB_PORTAL_SYSTEM_JOBPORTALSYSTEM_H
#include "User.h"
#include "Job.h"

class JobPortalSystem {
    std::vector<Job> jobs;
    std::vector<User> users;
public:
    void registerJobOpening(const Job &jobOpening) {
        jobs.push_back(jobOpening);
    }

    void registerUser(const User& user) {
        users.push_back(user);
    }

    void searchJob(const std::string& searchCriteria) const {
        std::cout << "Search Results: " << searchCriteria <<  std::endl;
        std::cout << "-----------------------" << std::endl;

        bool found = false;
        for(const auto& job : jobs) {
            if(job.getTitle().find(searchCriteria) != std::string::npos ||
               job.getDescription().find(searchCriteria) != std::string::npos ||
               job.getRequirements().find(searchCriteria) != std::string::npos) {
                std::cout << "Title: " << job.getTitle() << std::endl;
                std::cout << "Description: " << job.getDescription() << std::endl;
                std::cout << "Requirements: " << job.getRequirements() << std::endl;
                std::cout << "Salary: " << job.getSalary() << std::endl;
                std::cout << "Company: " << job.getCompany() << std::endl;
                std::cout << "-------------------------" << std::endl;
                found = true;
            }
        }
        if(!found) {
            std::cout <<  "No jobs found matching the search criteria." << std::endl;
        }
    }

    void applyJob(const std::string& userName, const std::string& jobTitle) {
        for(auto& job : jobs) {
            if(job.getTitle() == jobTitle && !job.getIsField()) {
                job.addApplicant(userName);
                std::cout << "Successfully applied fot the job: " << jobTitle << std::endl;
                return;
            }
        }
        std::cout << "Job not found or already filled: " << jobTitle << std::endl;
    }

    void generateNotification(const User& user) {
        std::cout << "Notifications for " << user.getName() << ":" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        bool found = false;
        for(const auto& job : jobs) {
            if(!job.getIsField() && isJobMatchingCriteria(job, user)) {
                std::cout << "New job matching your profile:" << std::endl;
                std::cout << "Title: " << job.getTitle() << std::endl;
                std::cout << "Description: " << job.getDescription() << std::endl;
                std::cout << "Requirements: " << job.getRequirements() << std::endl;
                std::cout << "Salary: " << job.getSalary() << std::endl;
                std::cout << "Company: " << job.getCompany() << std::endl;
                std::cout << "-------------------------------------" << std::endl;
                found = true;
            }
        }
        if(!found) {
            std::cout << "No new jobs found matching your profile." << std::endl;
        }
    }

private:
    bool isJobMatchingCriteria(const Job& job, const User& user) {
        for(const auto& u : users) {
            if(u.getName() == user.getName() && job.getRequirements() == user.getResume()) {
                std::cout << "Notification sent to " << user.getContactInfo() << std::endl;
            }
        }
    }
};

#endif //JOB_PORTAL_SYSTEM_JOBPORTALSYSTEM_H
