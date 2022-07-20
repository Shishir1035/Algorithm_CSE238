#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define print(x) cout<<x<<endl;
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define printarr2d(arr,a,b); for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) cout<<arr[i][j]<<" \n"[j==b-1];
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz 10005

int node, edge;
int par[sz];
vector<array<int,3>> graph;
vector<pair<int, pair<int,int> > > path; // {cost,{src,dest}}

int findpar(int x)
{
	if(par[x]==x)
		return x;
	return par[x] = findpar(par[x]);
}

int main()
{
	cin>>node>>edge;
	for (int i = 0; i < edge; ++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph.push_back({w,u,v});
	}

	for (int i = 0; i < node; ++i)
		par[i] = i;
	sort(graph.begin(), graph.end());
	for (auto [w,u,v] : graph)
	{
		int paru = findpar(u);
		int parv = findpar(v);

			if(paru == parv)
				continue;
			else{
				par[paru] = parv;
				path.push_back({w,{u,v}}) ;
			}
	}
	int cost = 0;
	for (auto [w,p] : path)
	{
		cout<<p.first<<" "<<p.second<<" "<<w<<endl;
		cost+=w;
	}
	cout<<cost<<endl;
}



