#ifndef DERIVEDWORDLIST_H
#define DERIVEDWORDLIST_H

#include <vector>
#include <string>
#include <iostream>
#include "DerivedWord.h"

using namespace std;

class DerivedWordList {
private:
    vector<DerivedWord> words;

public:
    void addWord(const string& word, const string& pattern);
    bool exists(const string& word) const;
    void display() const;
};

#endif
