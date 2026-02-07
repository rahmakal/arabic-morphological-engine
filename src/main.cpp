#include <iostream>
#include <vector>
#include <string>
#include "RootTree.h"
#include "HashTable.h"
#include "Engine.h"

using namespace std;

int main() {
    RootTree tree;
    HashTable hash_table;
    Engine engine;

    tree.insertRootsFromFile("../data/roots.txt");
    hash_table.insertPatternsFromFile("../data/patterns.txt");

    int choice;
    while (true) {
        cout << "\n--- Arabic Morphological Engine ---\n";
        cout << "1. Generate words from root and patterns\n";
        cout << "2. Generate morphological family\n";
        cout << "3. Validate morphological structure of a word\n";
        cout << "4. Display roots tree\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            string root;
            int n;
            cout << "Enter root: ";
            cin >> root;
            cout << "Number of patterns: ";
            cin >> n;
            vector<string> patterns(n);
            for (int i = 0; i < n; i++) {
                cout << "Pattern " << i + 1 << ": ";
                cin >> patterns[i];
            }
            engine.generateWords(tree, root, patterns, hash_table);
        }
        else if (choice == 2) {
            string root;
            cout << "Enter root: ";
            cin >> root;
            engine.generateMorphologicalFamily(tree, root, hash_table);
        }
        else if (choice == 3) {
            string word;
            cout << "Enter word: ";
            cin >> word;
            engine.morphological_validation(tree, word);
        }
        else if (choice == 4) {
            tree.displayRoots();
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
