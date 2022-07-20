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
vector<pair<int,int> >graph[sz];
vector<pair<int, pair<int,int> > > path; // {cost,{src,dest}}
bool vis[sz];

int findpar(int x)
{
	if(par[x]==x)
		return x;
	return par[x] = findpar(par[x]);
}

void prims(int start)
{
	// mincost edge (cost, {src, dest})
	priority_queue< pair<int, pair<int,int>>, 
				    vector<pair<int, pair<int,int>>>,
				    greater<pair<int, pair<int,int>>> > mincost_edge;

	for (auto [v, w] : graph[start])
		mincost_edge.push({w,{start,v}});

	while(!mincost_edge.empty())
	{
		int u = mincost_edge.top().second.first;
		int v = mincost_edge.top().second.second;
		int w = mincost_edge.top().first;

		mincost_edge.pop();
		
		int paru = findpar(u);
		int parv = findpar(v);

		if(paru == parv)
			continue;

		else{
			par[paru] = parv;
			path.push_back({w,{u,v}}) ;
		}

		if(!vis[u])
		{
			for (auto [e,w] : graph[u])
			{
				mincost_edge.push({w, {u,e}});
			}
			vis[u] = true;
		}

		if(!vis[v])
		{
			for (auto [e,w] : graph[v])
			{
				mincost_edge.push({w, {v,e}});
			}
			vis[v] = true;
		}

	}
}

int main()
{
	cin>>node>>edge;
	for (int i = 0; i < edge; ++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].pb({v,w});		// {node.cost}
		graph[v].pb({u,w});
	}

	for (int i = 0; i < node; ++i)
		par[i] = i;

	prims(0);	
	int cost = 0;
	for (auto [w,p] : path)
	{
		cout<<p.first<<" "<<p.second<<" "<<w<<endl;
		cost+=w;
	}
	cout<<cost<<endl;
}



