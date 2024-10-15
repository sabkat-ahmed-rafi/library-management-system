#include <iostream>
#include <string>

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
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6: 
            /* code */
            break;
        case 7: 
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9: 
            /* code */
            break;
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