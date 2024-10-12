#include "../include/ManageMember.h"
#include <iostream>

void ManageMember::addMember(const Member& newMember) {
    member.push_back(newMember);
    cout << "Member with name \"" << newMember.getName() << "\" added to the system." << endl;
}

bool ManageMember::removeMember(const string& membershipId) {
    for(auto it = member.begin(); it != member.end(); ++it) {
        if(it->getMembershipId() == membershipId) {
            cout << "Member with ID \"" << membershipId << "\" removed from the system." << endl;
            member.erase(it);
            return true;
        }
    }
    cout << "Member with ID \"" << membershipId << " not found." << endl;
    return false;
}

Member* ManageMember::searchMemberById(const string& membershipId) {
    for(auto& m: member) {
        if(m.getMembershipId() == membershipId) {
            return &m;
        }
    }
    cout << "Member with ID \"" << membershipId << "\" not found." << endl;
    return nullptr;
}


Member* ManageMember::searchMemberByName(const string& name) {
    for (auto& m : member) {
        if (m.getName() == name) {
            return &m;
        }
    }
    cout << "Member with name \"" << name << "\" not found." << endl;
    return nullptr;
}

void ManageMember::displayAllMember() {
    if (member.empty()) {
        cout << "No members in the system." << endl;
        return;
    }

    cout << "Members in the system:" << endl;
    for (const auto& m : member) {
        m.displayMemberInfo();  
        cout << "-----------------------------" << endl;
    }
}