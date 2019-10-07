#include<bits/stdc++.h>
using namespace std;

int gcd_of_two(int a, int b)
{
	int result=0;

	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	result=a;

	return result;
}

int gcd_of_many(vector<int>& nums)
{
	int result=0;
	for(unsigned i=1; i<nums.size(); i++)
	{
		result=gcd_of_two(nums[i], nums[i-1]);
		nums[i]=result;
	}                
	return result;
}

int main()
{

	freopen("/home/ornob/Downloads/Practice/input.txt", "r", stdin);
	freopen("/home/ornob/Downloads/Practice/output.txt", "w", stdout);

	vector<int>nums;
	int x, result;
	while(cin>>x)
	{
		nums.push_back(x);
	}
	result=gcd_of_many(nums);
	
	cout<<result<<endl;
	return 0;
}

	

