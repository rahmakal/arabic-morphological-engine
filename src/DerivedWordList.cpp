#include "DerivedWordList.h"

using namespace std;

void DerivedWordList::addWord(const string& root, const string& word, const string& pattern) {
    for (auto& w : words) {
        if (w.word == word) {
            w.frequency++;
            return;
        }
    }
    words.emplace_back(root, word, pattern);
}

DerivedWord DerivedWordList::exists(const string& word) const {
    for (DerivedWord w : words) {
        if (w.word == word)
            return w;
    }
    return DerivedWord();
}

void DerivedWordList::display() const {
    for (const auto& w : words) {
        cout << w.word << " (" << w.pattern << ", " << w.frequency << ")" << endl;
    }
}
