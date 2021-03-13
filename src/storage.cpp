//
// Created by Michael Kotor on 2021-03-13.
//

#include "../include/storage.h"

storage::storage() {
    this->table.insert(pair<int, item>(0,{2,true}));
    this->table.insert(pair<int, item>(1,{2,true}));
    this->table.insert(pair<int, item>(2,{4,true}));
    this->table.insert(pair<int, item>(3,{4,true}));
    this->table.insert(pair<int, item>(4,{16,true}));
    this->table.insert(pair<int, item>(5,{16,true}));
    this->table.insert(pair<int, item>(6,{32,true}));
    this->table.insert(pair<int, item>(7,{32,true}));
    this->table.insert(pair<int, item>(8,{64,true}));
    this->table.insert(pair<int, item>(9,{128,true}));
}

int storage::allocate(const process& process) {

    //by default the index is not found
    int index = -1;

    for (auto const& [key, val] : this->table)
    {
        if(val.isFree && val.capacity >= process.size) {
            index = key;
            this->table.at(key) = {val.capacity, false, process};
            break;
        }
    }
    return index;
}

storage::~storage() {
    this->table.clear();
}

void storage::free(process &process) {
    for (auto const& [key, val] : this->table)
    {
        if(val.isFree && val.capacity >= process.size) {
            this->table.at(key) = {val.capacity, true , {}};
            break;
        }
    }
}

process &storage::getProcess(const string& name) {
    for (auto const& [key, val] : this->table)
    {
        if(!val.isFree && val.process.name == name) {
            return this->table.at(key).process;

        }
    }
}
