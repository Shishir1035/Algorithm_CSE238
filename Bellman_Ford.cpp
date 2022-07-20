#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define print(x) cout<<x<<endl;
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define printarr2d(arr,a,b); for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) cout<<arr[i][j]<<" \n"[j==b-1];
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz 100005

int node,nedge;
int dist[sz];
int par[sz];

struct edge{

	int u,v,w;
	edge(int u1, int v1, int w1)
	{
		u=u1, v=v1, w=w1;
	}
};

bool is_negativecycle(vector<edge>&edges)
{
	for (auto [u,v,w] : edges)
	if(dist[u] + w < dist[v])
		return true;
	return false;
}

void Bellman(int start, vector<edge>&edges)
{
	dist[start]=0;
	par[start]=-1;
	int temp = node-1;
	while(temp--)
		for (auto [u,v,w] : edges)
		{
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				par[v] = u;
			}
		}

	if(is_negativecycle(edges))
		cout<<"Negative Cycle Exists"<<endl;
	else
		cout<<"Bellman Ford Successfully ran!"<<endl;
}

int main()
{
	cin>>node>>nedge;
	vector<edge> edges;

	for (int i = 0; i < nedge; ++i){
		int u,v,w;
		cin>>u>>v>>w;
		// u--;v--; //if 1 base node
		edges.push_back(edge(u,v,w));
	}

	for (int i = 0; i < node; ++i)
		dist[i] = 30000;

	// int st;
	// cin>>st;
	Bellman(0,edges);
	printvec(dist, node);
	printvec(par, node);
}    