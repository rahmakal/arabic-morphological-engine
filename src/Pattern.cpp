#include "Pattern.h"
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
