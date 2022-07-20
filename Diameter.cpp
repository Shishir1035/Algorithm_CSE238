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
std::vector<int> graph[1000];
bool visited[1000];
int level[1000];
vector<int>disc;

void initall()
{	
	disc.clear();
	for (int i = 0; i < 1000; ++i){
		level[i] = 0; visited[i] = false;
	}
}
int BFS(int start)
{
	initall();
	int node;
	queue<int>q;
	q.push(start);
	level[start] = 0;

	while(!q.empty())
	{
		node = q.front();
		q.pop();
		visited[node] = true;
		disc.push_back(node);
		for (int child : graph[node])
		{
			if(!visited[child]){
				q.push(child);
				level[child] = level[node]+1;
			}
		}
	}
	return node;
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

	int first_end = BFS(0);		//run bfs/dfs for finding furthest node
	int second_end = BFS(first_end);	// run bfs from first node
	cout<<"two end of tree "<<first_end<<" "<<second_end<<endl;
	cout<<"dia = "<<level[second_end]<<endl;
}

/**
11 10
0 2
0 6
2 1
4 5
6 7
1 4
5 8
7 3
7 10
8 9

two end of tree 9 10
*/