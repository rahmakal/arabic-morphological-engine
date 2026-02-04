#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include "HashTable.h"
#include "RootTree.h"
using namespace std;

class Engine {
public:
    string generateWord(const string& root, const string& pattern, HashTable& hashTable);
    void morphological_validation(RootTree tree, string word);
};

#endif