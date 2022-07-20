#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define sz 200010

bool arr[sz];

void sieve(int n)
{
	for (int i = 2; i*i <= n; ++i)
		if(!arr[i])	//if false then prime
			for (int j = i*i; j <= n; j+=i)
				arr[j] = true;
}
int main()
{
	int n;
	cin>>n;
	sieve(n);	
	for (int i = 2; i <= n ; ++i)
		if(!arr[i])
			cout<<i<<" \n"[i==n];
}