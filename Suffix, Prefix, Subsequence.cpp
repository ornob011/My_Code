#include <bits/stdc++.h>
using namespace std;

string str, check;

bool suffix()
{
    int i;
    int len_main = str.size();
    int len_check = check.size();

    if(len_check>len_main)
        return false;
    
    for (i = 0; i < len_check; i++)
    {
        if (str[len_main - i - 1] != check[len_check - i - 1])
        {
            return false;
        }
    }
    return true;
}


bool prefix()
{
    int len_main = str.size();
    int len_check = check.size();

    if(len_check>len_main)
        return false;
    
    for (int i = 0; i < len_check; i++)
    {
        if (str[i] != check[i])
            return false;
    }
    return true;
}

void subsequence()
{
    int i, j;
    int main_len = str.size();
    int check_len = check.size();

    for (i = 0, j = 0; i < main_len && j < check_len; i++)
    {
        if (str[i] == check[j])
            j++;
    }
    if (j == check_len)
        cout << "Subsequence" << endl;
    else
        cout << "Not subsequence" << endl;
}

int main()
{
    // freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
    // freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

    cin >> str >> check;

    suffix() == true ? cout << "suffix" << endl : cout << "Not suffix" << endl;

    prefix() ? cout << "prefix" << endl : cout << "Not prefix" << endl;
}