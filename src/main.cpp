#include <iostream>
#include "RootTree.h"
#include "HashTable.h"
#include "Engine.h"

using namespace std;

int main() {
    RootTree tree;
    HashTable hash_table = HashTable();
    tree.insertRootsFromFile("../data/roots.txt");
    tree.displayRoots();
    hash_table.insertPatternsFromFile("../data/patterns.txt");
    hash_table.show_hash_table();
    Engine engine;
    HashTable hashTable;
    Pattern p = Pattern();
    hashTable.insert("فعلت", p);
    cout << engine.generateWord("كتب", "فعلت", hashTable) << endl;

    return 0;
}
