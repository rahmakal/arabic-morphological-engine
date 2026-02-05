#include "Engine.h"
#include "RootTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void Engine::generateWords(RootTree &tree, const string& root, const vector<string>& patterns, HashTable& hashTable){
    RootNode* node = tree.searchRoot(root);
    if (node == nullptr) {
        tree.insertRoot(root);
        node = tree.searchRoot(root);
    }
    for (const string& pattern : patterns) {
        Pattern p = hashTable.search(pattern);

        if (p.transformed_word() != "") {
            cout << "Generating word for pattern: " << pattern << endl;

            string derived = p.generate_word(root);
            cout << "Generated word: " << derived << endl;

            node->derivedWords.addWord(root, derived, pattern);
        }
    }

    cout << "Derived words updated for root " << root << endl;
    node->derivedWords.display();
}

void Engine::generateMorphologicalFamily(RootTree &tree, const string& root, HashTable& hashTable)
{
    vector<string> patterns;
    ifstream file("../data/patterns.txt");

    string pattern;
    while (file >> pattern) {
        patterns.push_back(pattern);
    }

    generateWords(tree, root, patterns, hashTable);
}


void Engine::morphological_validation(RootTree tree, string word)
{

    DerivedWord derived_word = tree.find_derived_word(tree, word);
    if (derived_word.word!="")
    {
        cout << "The word " << word << " is morphologically valid, has pattern " << derived_word.pattern << " derived from root " << derived_word.root << " with frequency " << derived_word.frequency << endl;
    }
    else
    {
        cout << "The word " << word << " is not morphologically valid." << endl;
    }

}
