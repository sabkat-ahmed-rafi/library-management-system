#include "Member.h"
#include <iostream>
using namespace std;

Member::Member(const string& name, const string& membershipId)
    : name(name), membershipId(membershipId) {}

void Member::displayMemberInfo() const {
    cout << "Member Name: " << name << endl;
    cout << "Membership ID: " << membershipId << endl;
}
