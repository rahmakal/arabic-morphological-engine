#include <iostream>
#include "RootTree.h"
#include "HashTable.h"

using namespace std;

int main() {
    RootTree tree;
    HashTable hash_table = HashTable();
    tree.insertRootsFromFile("../data/roots.txt");
    tree.displayRoots();
    hash_table.insertPatternsFromFile("../data/patterns.txt");
    hash_table.show_hash_table();
    return 0;
}
