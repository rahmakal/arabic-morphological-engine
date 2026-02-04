#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include "HashTable.h"
using namespace std;
#include "RootTree.h"

class Engine
{
public:
    void morphological_validation(RootTree tree, string word);
};

class Engine {
public:
    string generateWord(const string& root, const string& pattern, HashTable& hashTable);
};

#endif