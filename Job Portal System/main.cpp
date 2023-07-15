#include "JobPortalSystem.h"

int main() {
    JobPortalSystem jobSystem;

    Job job1("Software Engineer", "Develop software applications", "Bachelor's degree in Computer Science",
    80000.0, "ABC Company");
    Job job2("Data Analyst", "Analyze and interpret complex data", "Bachelor's degree in Statistics",
             60000.0, "XYZ Corporation");
    jobSystem.registerJobOpening(job1);
    jobSystem.registerJobOpening(job2);


    User user1("John Doe", "john@example.com", "Bachelor's degree in Computer Science");
    User user2("Jane Smith", "jane@example.com", "Bachelor's degree in Business Administration");
    jobSystem.registerUser(user1);
    jobSystem.registerUser(user2);

    jobSystem.searchJob("Software");
    jobSystem.searchJob("Data");
    jobSystem.searchJob("Sales");

    jobSystem.applyJob("John Doe", "Software Engineer");
    jobSystem.applyJob("Jane Smith", "Data Analyst");
    jobSystem.applyJob("John Doe", "Data Analyst");

    jobSystem.generateNotification(user1);
    jobSystem.generateNotification(user2);


    return 0;
}
