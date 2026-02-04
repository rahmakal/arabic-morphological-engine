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
    engine.generateWord(tree, "كتب", "مفعول", hash_table);
    engine.generateWord(tree, "كتب", "مفعول", hash_table);
    engine.generateWord(tree, "كتب", "استفعل", hash_table);
    engine.morphological_validation(tree, "مكتوب");
    return 0;
}
