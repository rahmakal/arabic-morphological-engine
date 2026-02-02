#include "HashTable.h"

#include <codecvt>
#include <locale>
#include <iostream>
using namespace std;


HashTable::HashTable():values(16, Pattern())
{
}

int HashTable::find_index(string key)
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring wkey = conv.from_bytes(key);
    int ascii_sum = 0;
    for (auto c:wkey)
    {
        ascii_sum+=c;
    }
    return ascii_sum;
}

void HashTable::insert(string key, Pattern value)
{
    int index = find_index(key);
    value.TransformationRule(key);
    values[index%16] = value;

};
Pattern HashTable::search(string key)
{
    int index = find_index(key);
    return values[index%16];
}
