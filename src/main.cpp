#include <iostream>
#include <string>

#include "Book.h"
#include "Library.h"
#include "Loan.h"
#include "ManageMember.h"
#include "Member.h"

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
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    

    int choice = -1;

    while(choice != 0) {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
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
            /* code */
            break;
        case 11:
            /* code */
            break;
        case 0:
            cout<< "Exiting the system.\n";
            break;        
        default:
            cout<< "Invalid choice. Please try again.\n";
            break;
        }

    }

}