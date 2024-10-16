#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>


#include "../include/Book.h"
#include "../include/Library.h"
#include "../include/Loan.h"
#include "../include/ManageMember.h"
#include "../include/Member.h"

using namespace std;

void displayMenu() {
    cout << "\n==== Library Management System ====\n";
    cout << "1. Add Book\n";
    cout << "2. Remove Book\n";
    cout << "3. Search Book by Title\n";
    cout << "4. Search Book by Author\n";
    cout << "5. Borrow Book\n";
    cout << "6. Return Book\n";
    cout << "7. Add Member\n";
    cout << "8. Search Member\n";
    cout << "9. Remove Member\n";
    cout << "10. Display All Books\n";
    cout << "11. Display All Members\n";
    cout << "12. Display All Loans\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {

    Library library;
    ManageMember manageMember;
    

    int choice = -1;

    while(choice != 0) {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1: {
            // Add a book 
            string title, author, isbn;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book ISBN: ";
            getline(cin, isbn);

            Book newBook(title, author, isbn);

            library.addBook(newBook);
            
            break;
        }
        case 2: {
            // Remove a book 
            string isbn;
            cout << "Enter ISBN to remove: ";
            cin.ignore();
            getline(cin, isbn); 

            if(!library.removeBook(isbn)) {
                cout << "Book not found.\n";    
            }

            break;
        }
        case 3: {
            // Search by title 
            string title;
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, title);

            if(library.searchBookByTitle(title)) {
                cout << "Book \"" << title << "\" found";
            } else {
                cout << "Book with title \"" << title << "\" not found." << endl;
            }
            break;
        }
        case 4: {
            // Search by author 
            string author;
            cout << "Enter the book title: ";
            cin.ignore();
            getline(cin, author);

            if(library.searchBookByAuthor(author)) {
                cout << "Book with author \"" << author << "\" found";
            } else {
                cout << "Book with author \"" << author << "\" not found." << endl;
            }
            break;
        }
        case 5: {
            // Borrow a book 
            string borrower, title, isbn, membershipId;
            time_t borrowingDate;
            time_t dueDate;
            cout << "Enter your membership Id: ";
            cin.ignore();
            getline(cin, membershipId);
            cout << "Enter borrower name to borrow: ";
            getline(cin, borrower);
            cout << "Enter book name: ";
            getline(cin, title);
            cout << "Enter the ISBN of book: ";
            getline(cin, isbn);

            borrowingDate = time(0);
            dueDate = borrowingDate + (14 * 24 * 60 * 60);

            if(!manageMember.searchMemberById(membershipId)) {
                cout << "You are not a member of our library.";
                break;
            }
            
            ostringstream borrowingDateStr;
            borrowingDateStr << put_time(localtime(&borrowingDate), "%Y-%m-%d");

            ostringstream dueDateStr;
            dueDateStr << put_time(localtime(&dueDate), "%Y-%m-%d");

            if(library.borrowBook(isbn)) {
                cout << "Book borrowed successfully.";
                library.addLoan(borrower, title, borrowingDateStr.str(), dueDateStr.str());
            }
            break;
        }
        case 6: {
            // Return book 
             string isbn;
             cout << "Enter book ISBN to return: ";
             cin.ignore();
             getline(cin, isbn);

                if (library.returnBook(isbn)) {
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Returning failed. Book might not have been borrowed.\n";
                }
                break;
        }
        case 7: {
            // Add a member to the library 
            string name, membershipId;
            cout << "Enter new member name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter a membership id for new member: ";
            getline(cin, membershipId);

            Member newMember(name, membershipId);

            manageMember.addMember(newMember);

            break;
        }
        case 8: {
            // Search member with membership id 
            string membershipId;
            cout << "Enter the membership id to search: ";
            cin.ignore();
            getline(cin, membershipId);
            Member* foundMember = manageMember.searchMemberById(membershipId);
            if(foundMember) {
                cout << "Member with \"" << membershipId << "\" found.";
            }
            break;
        }
        case 9: {
            // Remove member from library 
            string membershipId;
            cout << "Enter membership id to remove: ";
            cin.ignore();
            getline(cin, membershipId);

            manageMember.removeMember(membershipId);
            
            break;
        }
        case 10:
            library.displayAllBooks();
            break;
        case 11:
            manageMember.displayAllMember();
            break;
        case 12:
            library.displayAllLoans();
        case 0:
            cout<< "Exiting the system.\n";
            break;        
        default:
            cout<< "Invalid choice. Please try again.\n";
            break;
        }

    }

}