#ifndef DERIVEDWORD_H
#define DERIVEDWORD_H

#include <string>

using namespace std;

class DerivedWord {
public:
    string word;
    string pattern;
    int frequency;

    DerivedWord(const string& word, const string& pattern)
        : word(word), pattern(pattern), frequency(1) {}
};

#endif
