#include "HashTable.h"

#include <codecvt>
#include <locale>
#include <iostream>
using namespace std;


HashTable::HashTable():values(16, Pattern())
{
}

void HashTable::insert(string key, Pattern value)
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring wkey = conv.from_bytes(key);
    int ascii_sum = 0;
    for (auto c:wkey)
    {
        ascii_sum+=c;
    }
    value.TransformationRule(key);
    values[ascii_sum%16] = value;

    for (auto x:values)
    {
        cout<<x.transformed_word()<<endl;
    }

};
