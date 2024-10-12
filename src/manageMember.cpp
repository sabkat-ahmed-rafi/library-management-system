#include "ManageMember.h"
#include <iostream>

void ManageMember::addMember(const Member& newMember) {
    member.push_back(newMember);
    cout << "Member with name \"" << newMember.getName() << "\" added to the system." << endl;
}

