#include "Pattern.h"
#include <iostream>
#include <string>
#include <codecvt>
#include <locale>
using namespace std;
Pattern::Pattern()
{
    transformed_word_ = "";
}
void Pattern::TransformationRule(string key)
{

    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring wkey = conv.from_bytes(key);

    wstring rule = L"";
    for (auto c:wkey)
    {
        if (c == L'ف' || c == L'ع' || c == L'ل')
        {
            rule+='*';
        }else
        {
            rule+=c;
        }
    }
    transformed_word_ = conv.to_bytes(rule);
}

string Pattern::transformed_word()
{
    return transformed_word_;
}

string Pattern::generate_word(const string& word)
{
    wstring_convert<codecvt_utf8<wchar_t>> conv;
    wstring generated = L"";
    wstring w_word= conv.from_bytes(word);
    wstring w_transformed_ = conv.from_bytes(transformed_word_);
    size_t word_index = 0;
    for (auto c : w_transformed_) {
        if (c == '*') {
            generated += w_word[word_index++];
        } else {
            generated += c;
        }
    }

    return conv.to_bytes(generated);
}
