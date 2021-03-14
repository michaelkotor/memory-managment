#include <iostream>
#include "include/storage.h"
#include "include/process.h"

using namespace std;

int real(int a) {
    return a + 2;
}

int main() {
    storage storage;

    process first{"Name", 3};

    cout << storage.allocate(first) << endl;
    return 0;
}

