#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
	freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

	int in;
	cin>>in;
	vector<int>arr;

	int temp=in;

	while(temp>=1)
	{
		arr.push_back(temp);
		temp=temp>>1;
	}

	reverse(arr.begin(), arr.end());

	for(vector<int>::iterator it=arr.begin(); it!=arr.end(); it++)
	{
		if(*it & 1)
			cout<<"1";
		else
			cout<<"0";
	}

	cout<<endl;

	return 0;
}
