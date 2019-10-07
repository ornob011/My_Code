#include <bits/stdc++.h>
using namespace std;
#define llu unsigned long long

int main()
{
    llu limit, i, j;
    cin >> limit;
    bitset<10000> b;
    vector<int> prime((int)limit);

    b.set();

    b[0] = 0, b[1] = 0;

    prime.push_back(2);

    for (i = 3; i <= limit; i = i + 2)
    {
        if (b[i])
        {
            for (j = i * i; j <= limit; j = j + i)
                b[j] = 0;

            prime.push_back(int(i));
        }
    }

    for (vector<int>::iterator it = prime.begin(); it != prime.end(); it++)
    {
        if (*it != 0)
            cout << *it << " ";
    }

    cout << endl;

    return 0;
}