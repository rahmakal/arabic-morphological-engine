#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include "HashTable.h"
using namespace std;

class Engine {
public:
    string generateWord(const string& root, const string& pattern, HashTable& hashTable);
};

#endif