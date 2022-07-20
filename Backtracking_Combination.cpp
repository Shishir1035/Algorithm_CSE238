#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define sz 100010

vector<int> npr;
bool taken[sz];
void combination(int n,int r,int j)
{
	if(npr.size() == r){
		printvec(npr,r);
		return;
	}
	for (int i = j; i <= n; ++i)
	{
		if(!taken[i]){
			taken[i] = true;
			npr.push_back(i);
			combination(n,r,i+1);
			npr.pop_back();		//backtrack
			taken[i] = false;	//backtrack
		}
	}
}

int main()
{
	int n,r;
	cin>>n>>r;
	combination(n,r,1);
}
