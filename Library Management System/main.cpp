#include "Library.h"

int main() {
    Library library;

    library.registerBook("Book 1", "Author 1", "Genre 1");
    library.registerBook("Book 2", "Author 2", "Genre 2");
    library.registerBook("Book 3", "Author 3", "Genre 3");

    library.registerMember("Joe", "joe@example.com");
    library.registerMember("Jane", "jane@example.com");

    Book* book1 = library.findBookByTitle("Book 1");
    Member* member1 = library.findMemberByName("Joe");
    if(book1 and member1) {
        member1->borrowBook(book1);
    }

    Book* book2 = library.findBookByAuthor("Author 2");
    Member* member2 = library.findMemberByName("Jane");
    if(book2 and member2) {
        member2->borrowBook(book2);
    }

    if(book1 and member1) {
        member1->returnBook(book1);
    }

    if(book2 and member2) {
        member2->returnBook(book2);
    }
    return 0;
}
