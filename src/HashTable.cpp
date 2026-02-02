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
    return ascii_sum%16;
}

void HashTable::insert(string key, Pattern value)
{
    int index = find_index(key);
    if (values[index].transformed_word() == "")
    {
        value.TransformationRule(key);
        values[index] = value;
    }


};
Pattern HashTable::search(string key)
{
    int index = find_index(key);
    return values[index];
}

void HashTable::modify(string key, string new_key)
{
    int old_key_idx = find_index(key);
    if (values[old_key_idx].transformed_word()!="")
    {
        delete_key(key);
        int new_key_idx = find_index(new_key);
        Pattern new_pattern = Pattern();
        new_pattern.TransformationRule(new_key);
        values[new_key_idx] = new_pattern;
    }


}

void HashTable::delete_key(string key)
{
    int key_idx = find_index(key);
    if (values[key_idx].transformed_word()!="")
    {
        values[key_idx] = Pattern();
    }

}

void HashTable::show_hash_table()
{
    for (auto element:values)
    {
        if (element.transformed_word()!="")
        {
            cout<<element.transformed_word()<<endl;
        }
    }
}
