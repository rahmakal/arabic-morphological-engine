#include "Engine.h"
#include "RootTree.h"
#include <iostream>
#include <string>

using namespace std;

string Engine::generateWord(const string& root, const string& pattern, HashTable& hashTable) {
    Pattern p = hashTable.search(pattern);
    string derived = "";
    if (p.transformed_word() != ""){
        cout << "Pattern found: " << p.transformed_word() << endl;
        derived = p.generate_word(root);
    }
    return derived;
}

void Engine::morphological_validation(RootTree tree, string word)
{

    DerivedWord derived_word = tree.find_derived_word(tree, word);
    if (derived_word.word!="")
    {
        cout<<"OUI  " + derived_word.pattern;
    }

}
