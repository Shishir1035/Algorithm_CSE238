#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pb push_back
#define print(x) cout<<x<<endl;
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define printarr2d(arr,a,b); for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) cout<<arr[i][j]<<" \n"[j==b-1];
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz 1e6

int node,edge;
bool visited[1000];
vector<int> topo_order;
vector<int> graph[1000];

void DFS(int st)
{
	visited[st]=true;
	for (int x : graph[st]){
		if(!visited[x])
			DFS(x);
	}
	topo_order.pb(st);
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
	for (int i = 0; i < node; ++i)
		if(!visited[i])
			DFS(i);
	
	reverse(topo_order.begin(), topo_order.end());
	printvec(topo_order,topo_order.size());
}