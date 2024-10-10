#ifndef Load_H
#define Load_H

#include "Book.h"
#include "Member.h"
#include <ctime>

class Loan {
    private:
        Book book;
        Member member;
        time_t borrowingDate;
        time_t dueDate;
    
    public:
        Loan(Book& book, Member member);
        void displayLoanInfo();
}





#endif