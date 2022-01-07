#include <iostream>
#include "coder.h"

int main() {
    Coder coder;

    coder.set("Hello world!", 15);

    coder.encode();

    return 0;
}
