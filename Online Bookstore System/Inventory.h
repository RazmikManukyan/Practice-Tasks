#ifndef OBS_INVENTORY_H
#define OBS_INVENTORY_H
#include "Book.h"

class Inventory{
private:
    std::vector<Book> books;
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    Book* findBookByTitle(const std::string& title) {
        for(auto& book : books) {
            if(book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }
};

#endif //OBS_INVENTORY_H
