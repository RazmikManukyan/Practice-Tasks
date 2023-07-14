#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
#include "Member.h"
#include <fstream>

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
public:
    void registerBook(const std::string& title, const std::string& author, const std::string& genre) {
        books.push_back(Book(title, author, genre));
    }

    void registerMember(const std::string& name, const std::string& contactInfo){
        members.push_back(Member(name, contactInfo));
    }

    Book* findBookByTitle(const std::string& title) {
        for(auto& book : books) {
            if(book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    Book* findBookByAuthor(const std::string& author) {
        for(auto& book : books) {
            if(book.getAuthor() == author) {
                return &book;
            }
        }
        return nullptr;
    }

    Book* findBookByGenre(const std::string& genre) {
        for(auto& book : books) {
            if(book.getGenre() == genre) {
                return &book;
            }
        }
        return nullptr;
    }

    Member* findMemberByName(const std::string& name) {
        for(auto& member : members) {
            if(member.getName() == name) {
                return &member;
            }
        }
        return nullptr;
    }

};


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARY_H
