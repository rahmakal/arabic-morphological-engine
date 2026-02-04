#ifndef DERIVEDWORD_H
#define DERIVEDWORD_H

#include <string>

using namespace std;

class DerivedWord {
public:
    string root;
    string word;
    string pattern;
    int frequency;

    DerivedWord() : root(""), word(""), pattern(""), frequency(0) {} 

    DerivedWord(const string& root, const string& word, const string& pattern)
        : root(root), word(word), pattern(pattern), frequency(1) {}
};

#endif
