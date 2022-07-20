#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define print(x) cout<<x<<endl;
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define printarr2d(arr,a,b); for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) cout<<arr[i][j]<<" \n"[j==b-1];
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz 100010

int node, edge;
int par[sz];
std::vector<int> graph[sz];

void init(int n)
{
	for (int i = 0; i < n; ++i)
		par[i] = i;
}

int findpar(int x)
{
	if(par[x] == x) 
		return x;
	else 
		return findpar(par[x]);		//return par[x] = findpar(par[x])

}

void dsu(int u,int v)
{
	int paru = findpar(u);
	int parv = findpar(v);
	cout<<paru<<endl;
	par[parv] = paru;
	return;
}
int main()
{
	cin>>node>>edge;
	for (int i = 0; i < edge; ++i)
	{
		int u,v;
		cin>>u>>v;
		graph[u].pb(v);
	}
	init(node);
	for (int i = 0; i < sz; ++i)
		for (int fr : graph[i])
			{
				cout<<i<< " " <<fr<<endl;
				dsu(i,fr);
			}
	printvec(par,node);
}