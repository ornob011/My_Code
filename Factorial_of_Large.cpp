#include <bits/stdc++.h>
using namespace std;

int multiply(int x, int result[], int result_size)
{
    int i, carry = 0;
    for (i = 0; i < result_size; i++)
    {
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        result[result_size] = carry % 10;
        carry = carry / 10;
        result_size++;
    }
    return result_size;
}

void factorial(int n)
{
    int result[10000];
    int result_size, x, i;

    result[0] = 1;
    result_size = 1;

    for (x = 2; x <= n; x++)
    {
        result_size = multiply(x, result, result_size);
    }
    cout<<"Factorial of "<<n<<" = ";
    for (i = result_size - 1; i >= 0; i--)
        cout << result[i];

    cout << endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        factorial(n);
    }
    return 0;
}
