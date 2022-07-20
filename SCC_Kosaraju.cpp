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

int node,edge;
vector<int> graph[sz], revgraph[sz], ans[100];
vector<int>order;
bool vis[1000];

void DFS(int start)
{
	vis[start] = true;
	for (int child : graph[start])
	{
		if(!vis[child]){
			DFS(child);
		}
	}
	order.pb(start);
	return;
}

void DFSI(int start, int lbl)
{
	vis[start] = true;
	for (int child : revgraph[start])
	{
		if(!vis[child]){
			ans[lbl].pb(child);
			DFSI(child,lbl);
		}
	}
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
		revgraph[v].pb(u);
	}
	for (int i = 0; i < node; ++i)
		if(!vis[i])
			DFS(i);	

	for (int i = 0; i < node; ++i)
		vis[i] = false;

	int lbl = 0;
	for (int i = node - 1; i >= 0; --i)
	{
		int fin = order[i];
		if(!vis[fin]){
			ans[lbl].pb(fin);
			DFSI(fin,lbl++);;
		}
	}

	// print SCCs
	for(int i = 0; i<lbl; i++){
		cout<<"SCC "<<i+1<<" = ";
		for (int nodes : ans[i])
			cout<<nodes<<" ";
		cout<<endl;
	}
}