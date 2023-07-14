#ifndef LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
#define LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
#include "Book.h"
#include <vector>

class Member {
private:
    std::string name;
    std::string contactInfo;
    std::vector<Book*> borrowedBooks;
public:
    Member(const std::string& name, const std::string& contactInfo)
            :name(name), contactInfo(contactInfo){}

    const std::string &getName() const {
        return name;
    }

    const std::string &getContactInfo() const {
        return contactInfo;
    }

    const std::vector<Book*>& getBorrowedBooks() const {
        return borrowedBooks;
    }

    void borrowBook(Book* book){
        book->setAvailability(false);
        borrowedBooks.push_back(book);
    }

    void returnBook(Book* book) {
        book->setAvailability(true);
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(),book);
        if(it != borrowedBooks.end()){
            borrowedBooks.erase(it);
        }
    }
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
