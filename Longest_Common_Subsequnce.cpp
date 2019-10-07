#include <bits/stdc++.h>
using namespace std;

int L[100][100];
int M[100][100];

int lcs(string s1, string s2, int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
            {
                L[i][j] = 1 + L[i - 1][j - 1];
                M[i][j] = 1;
            }

            else
            {
                if (L[i][j - 1] > L[i - 1][j])
                {
                    L[i][j] = L[i][j - 1];
                    M[i][j] = 3;
                }
                else
                {
                    L[i][j] = L[i - 1][j];
                    M[i][j] = 2;
                }
            }
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << L[i][j] << " ";

            if (M[i][j] == 1)
                cout << "\\";

            else if (M[i][j] == 2)
                cout << "^";

            else
                cout << "<";

            cout << "\t";
        }
        cout << endl;
    }
    return L[m][n];
}

void PrintLCS(string s1, string s2, int index, int m, int n)
{
    char ans_lcs[index + 1];
    ans_lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans_lcs[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "Longest Common Subsequnce = " << ans_lcs << endl;
}

int main()
{
    string s1, s2;
    //cout << "Enter first string: ";
    // cin >> s1;
    // //cout << "Enter second string: ";
    // cin >> s2;
    s1 = "ABCBDAB";
    s2 = "BDCABA";
    int m = s1.length();
    int n = s2.length();

    int length = lcs(s1, s2, m, n);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    PrintLCS(s1, s2, length, m, n);

    return 0;
}