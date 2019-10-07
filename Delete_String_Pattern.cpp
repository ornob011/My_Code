#include <bits/stdc++.h>
using namespace std;

void replace_every(string &str, string to_search, string replace_str)
{
    size_t pos=str.find(to_search);

    while(pos != -1)
    {
        str.replace(pos, to_search.size(), replace_str);

        pos=str.find(to_search, pos+replace_str.size());
    }
}

int main()
{
    string str, to_search, replace_str;

    getline(cin, str);
    cin>>to_search;
    cin>>replace_str;

    cout<<str<<endl;

    replaceall(str, to_search, replace_str);

    cout<<str<<endl;
}