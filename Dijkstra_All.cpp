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
vector<pair<int,int> >graph[1000];	//graph adjacency list (pair<node,cost>)
int cost[1000];						//cost from starting node
int parent[1000]; 					//path print back tracking

void Dijkstra(int st)
{
	priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > >pq;
	
	cost[st] = 0, parent[st] = -1;
	pq.push({st,cost[st]});

	while(!pq.empty()){
		int par = pq.top().first;
		int par_curcost = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[par].size(); ++i){
			int child = graph[par][i].first;
			int child_edgecost = graph[par][i].second;

			// triple check this
			if(cost[child] > cost[par] + child_edgecost){
				cost[child] = cost[par] + child_edgecost;
				parent[child] = par;
				pq.push({child,cost[child]});
			}
		} 
	}
}

void init_cost()
{
	for (int i = 1; i <= node; ++i)
		cost[i] = 1<<25;
}

void pathprint(int x)
{
	if(x != -1){
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
		cin>>u>>v>>w;;
		graph[u].pb({v,w});
		graph[v].pb({u,w});
	}

	int starting_node;
	cin>>starting_node;
	init_cost();
	Dijkstra(starting_node);

	//operations
	for (int i = 1; i <= node; ++i)
		cout<<parent[i]<<" \n"[i==node];

	for (int i = 1; i <= node; ++i){
		cout<<"Path of node "<<i<<" : ";
		pathprint(i);
		cout<<endl;
		cout<<"Cost of reaching node "<<i<<" = "<<cost[i]<<"\n\n";
	}

}