//
// Created by Tomi on 17/04/2020.
//

#include "phone.hpp"

#include "memtrace.h"

using namespace std;
string Work::toString() {
    // 06204623597, ID: 2
    string tmp = "Number: ";
    tmp.append((const char*)number);
    tmp.append(", WorkID: ");
    tmp.append((const char*)workID);
    return tmp;
}

string Private::toString() {
    // 06204623597, ID: 2
    string tmp = "Number: ";
    tmp.append((const char*)number);
    tmp.append(", WorkID: ");
    tmp.append((const char*)ID);
    return tmp;
}
