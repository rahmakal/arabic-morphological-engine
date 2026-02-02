#ifndef ARABIC_MORPHOLOGICAL_ENGINE_HASHTABLE_H
#define ARABIC_MORPHOLOGICAL_ENGINE_HASHTABLE_H
#include <string>
#include <vector>
#include <Pattern.h>
using namespace std;
class HashTable
{
public:
    HashTable();
    void insert(string key, Pattern value);
    Pattern search(string key);
private:
    vector<Pattern> values;
    int find_index(string key);

};

#endif //ARABIC_MORPHOLOGICAL_ENGINE_HASHTABLE_H