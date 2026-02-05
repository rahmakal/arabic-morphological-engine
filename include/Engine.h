#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include "HashTable.h"
#include "RootTree.h"
using namespace std;

class Engine {
public:
    void generateWords(RootTree &tree, const string& root, const vector<string>& patterns, HashTable& hashTable);
    void generateMorphologicalFamily(RootTree &tree, const string& root, HashTable& hashTable);
    void morphological_validation(RootTree tree, string word);
};

#endif