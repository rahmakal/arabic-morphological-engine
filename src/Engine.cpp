#include "Engine.h"
#include <iostream>
#include <string>

using namespace std;

string Engine::generateWord(const string& root, const string& pattern, HashTable& hashTable) {
    Pattern p = hashTable.search(pattern);
    cout << "Pattern found: " << p.transformed_word() << endl;
    string derived = p.generate_word(root);
    return derived;
}
