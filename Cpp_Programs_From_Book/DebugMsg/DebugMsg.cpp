#include <iostream>

#define DEBUG 1
#include "LogMessage.h"

void testFunction(const char* msg) {
    logMessage(msg);
}

int main() {
    testFunction("Hello world!");
    
    return 0;
}
