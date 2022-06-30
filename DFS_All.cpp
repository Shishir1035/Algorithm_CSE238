#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define print(x) cout<<x<<endl;
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define printarr2d(arr,a,b); for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) cout<<arr[i][j]<<" \n"[j==b-1];
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz 1e6

int node,edge;
bool vis[1000];			//initialed with 0
vector<int>graph[1000];	//graph adjacency list
vector<int>discover;	//traversal order
int depth[1000];		//depth no from root(0)
int parent[1000]; 		//path print back tracking

void DFS(int st,int par)
{
	// vis[st] = true;	
	discover.pb(st);
	parent[st] = par;
	for (int x : graph[st])
	{
		// vis[st] = true;	//also works. but i prefer the outer one
		if(!vis[x]){
			depth[x] = depth[st]+1;
			DFS(x,st);
		}
	}
}

void depthprint()
{
	for (int i = 0; i < node; ++i)
	{
		cout<<"depth["<<i<<"] = "<<depth[i]<<endl;
	}
}

void traversalorder()
{
	cout<<"DFS order : ";
	for (int i = 0; i < node; ++i)
	{
		cout<<discover[i]<<" \n"[i==node-1];
	}
}

void pathprint(int x)
{
	if(x != -1)
	{
		pathprint(parent[x]);
		cout<<x<<" ";
	}
	return;
}

int main()
{
	//nodes should be less than 1000
	cin>>node>>edge;

	//graph construct
	for(int i=0; i<edge; i++)
	{
		int u,v,w;
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	//Adjacency Graph
	for (int i = 0; i < node; ++i)
	{
		cout<<i<<" : ";
		for (int j = 0; j < graph[i].size(); ++j)
		{
			cout<<graph[i][j]<<" \n"[j==graph[i].size()-1];
		}
	}

	//for connected graph
	// DFS(0,-1);

	//for disconnected graph
	for (int i = 0; i < node; ++i)
	{
		if(!vis[i])
			DFS(i,-1);
	}

	//operations
	depthprint();
	traversalorder();
	cout<<"Parent arr : ";
	printvec(parent,node);

	for (int i = 0; i < node; ++i)	//path print
	{
		cout<<"node "<<i<<" : ";
		pathprint(i);
		cout<<endl;
	}
}

/**

5 3
0 1
0 2
2 3


*/

/**

0 : 1 2
1 : 0
2 : 0 3
3 : 2
4 : 
depth[0] = 0
depth[1] = 1
depth[2] = 1
depth[3] = 2
depth[4] = 0
DFS order : 0 1 2 3 4
Parent arr : -1 0 0 2 -1
node 0 : 0 
node 1 : 0 1 
node 2 : 0 2 
node 3 : 0 2 3 
node 4 : 4 


*/