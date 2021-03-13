//
// Created by Michael Kotor on 2021-03-13.
//

#ifndef MEMORY_MANAGEMENT_STORAGE_H
#define MEMORY_MANAGEMENT_STORAGE_H

#include <map>
#include "item.h"

using namespace std;

class storage {
private:
    map<int, item> table;

public:
    int allocate(const process& process);
    void free(process& process);
    process& getProcess(const string& name);

    storage();
    ~storage();
};


#endif //MEMORY_MANAGEMENT_STORAGE_H
