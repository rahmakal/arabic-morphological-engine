#include <iostream>
#include "RootTree.h"
#include "HashTable.h"
#include "Engine.h"
#include <fstream>

using namespace std;

int main() {
    ofstream out("output.txt");
    streambuf* oldCoutBuffer = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    RootTree tree;
    HashTable hash_table = HashTable();
    tree.insertRootsFromFile("../data/roots.txt");
    tree.displayRoots();
    hash_table.insertPatternsFromFile("../data/patterns.txt");
    hash_table.show_hash_table();

    Engine engine;
    vector<string> patterns = {"فاعل", "مفعول", "فعيل"};
    engine.generateWords(tree, "كتب", patterns, hash_table);
    engine.generateMorphologicalFamily(tree, "درس", hash_table);
    tree.displayRoots();
    engine.morphological_validation(tree, "مكتوب");
    engine.morphological_validation(tree, "أدرس");

    cout.rdbuf(oldCoutBuffer);
    out.close();
    return 0;
}
