//
// Created by Michael Kotor on 2021-03-13.
//

#ifndef MEMORY_MANAGEMENT_ITEM_H
#define MEMORY_MANAGEMENT_ITEM_H


#include "process.h"

struct item {
    int capacity;
    bool isFree;
    process process;
};


#endif //MEMORY_MANAGEMENT_ITEM_H
