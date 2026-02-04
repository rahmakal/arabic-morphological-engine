#include "Engine.h"
#include "RootTree.h"
#include <iostream>
#include <string>

using namespace std;

void Engine::generateWord(RootTree tree, const string& root, const string& pattern, HashTable& hashTable) {
    Pattern p = hashTable.search(pattern);
    string derived = "";
    if (p.transformed_word() != ""){
        cout << "Generating word for pattern: " << p.transformed_word() << endl;
        derived = p.generate_word(root);
        cout << "Generated word: " << derived << endl;
        RootNode* node = tree.searchRoot(root);
        if(node != nullptr){
            node->derivedWords.addWord(root, derived, pattern);
        }else{
            tree.insertRoot(root);
            tree.searchRoot(root)->derivedWords.addWord(root, derived, pattern);
        }
        cout << "Derived words updated for root " << root << endl;
        tree.searchRoot(root)->derivedWords.display();
    }
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
