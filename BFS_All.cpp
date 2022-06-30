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
int level[1000];		//level no from root(0)
int parent[1000]; 		//path print back tracking

void BFS(int st)
{
	queue<int>bfsq;
	bfsq.push(st);
	level[st] = 0;
	parent[st] = -1;

	while(!bfsq.empty())
	{
		int par = bfsq.front();

		discover.pb(par);					//traversal order print		
		bfsq.pop();
		vis[par] = true;

		for (int i = 0; i < graph[par].size(); ++i)
		{
			int child = graph[par][i];

			if(!vis[child]){					//infinite loop e porsili remember?
				bfsq.push(child);			
				level[child] = level[par]+1;	//child level = parent level + 1
				parent[child] = par;			//parent initialize
			}
		}
	}
}

void levelprint()
{
	for (int i = 0; i < node; ++i)
	{
		cout<<"level["<<i<<"] = "<<level[i]<<endl;
	}
}

void traversalorder()
{
	cout<<"BFS order : ";
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
	// BFS(0);

	//for disconnected or connected graph
	for (int i = 0; i < node; ++i)
	{
		if(!vis[i])
			BFS(i);
	}

	//operations
	levelprint();
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

11 9
0 2
0 6
2 1
6 7
1 4
5 8
7 3
7 10
8 9

*/

/**

0 : 2 6
1 : 2 4
2 : 0 1
3 : 7
4 : 1
5 : 8
6 : 0 7
7 : 6 3 10
8 : 5 9
9 : 8
10 : 7
level[0] = 0
level[1] = 2
level[2] = 1
level[3] = 3
level[4] = 3
level[5] = 0
level[6] = 1
level[7] = 2
level[8] = 1
level[9] = 2
level[10] = 3
BFS order : 0 2 6 1 7 4 3 10 5 8 9
Parent arr : -1 2 0 7 1 -1 0 6 5 8 7
node 0 : 0 
node 1 : 0 2 1 
node 2 : 0 2 
node 3 : 0 6 7 3 
node 4 : 0 2 1 4 
node 5 : 5 
node 6 : 0 6 
node 7 : 0 6 7 
node 8 : 5 8 
node 9 : 5 8 9 
node 10 : 0 6 7 10 

*/