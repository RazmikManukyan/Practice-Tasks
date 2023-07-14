#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#include <iostream>

class Book {
    std::string title;
    std::string author;
    std::string genre;
    bool isAvailable;
public:
    Book(const std::string& title, const std::string& author, const std::string& genre)
            :title(title), author(author), genre(genre), isAvailable(true){}

    const std::string &getTitle() const {
        return title;
    }

    const std::string &getAuthor() const {
        return author;
    }

    const std::string &getGenre() const {
        return genre;
    }

    bool getAvailability() const {
        return isAvailable;
    }

    void setAvailability(bool isAvailable) {
        this->isAvailable = isAvailable;
    }
};


#endif //LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
