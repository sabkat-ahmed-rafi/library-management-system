#include "../include/Member.h"
#include <iostream>
using namespace std;



void Member::displayMemberInfo() const {
    cout << "Member Name: " << name << endl;
    cout << "Membership ID: " << membershipId << endl;
}
