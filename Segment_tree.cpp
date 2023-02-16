#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define print(x) cout<<x<<endl;
#define printvec(vec,n); for (int i = 0; i < n; ++i) cout<<vec[i]<<" \n"[i==n-1];
#define printarr2d(arr,a,b); for (int i = 0; i < a; ++i) for (int j = 0; j < b; ++j) cout<<arr[i][j]<<" \n"[j==b-1];
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz 1000005
#define sz1 50005

int tree[3*sz];
vector<int> v(sz);

void reset(){
	for (int i = 0; i < sz; i++) v[i] = 0;
	return;
}

void create(int node, int begin, int end){
	if(begin == end){
		tree[node] = v[begin];
		return;
	}
	int left = 2*node;
	int right = 2*node + 1;
	int mid = (begin + end) >> 1;
	create(left, begin, mid);
	create(right, mid+1, end);
	tree[node] = tree[left] + tree[right];
	return;
}
int query(int node, int begin, int end, int l, int r){
	if(l > end || r < begin)
		return 0;
	if(begin>=l && end<=r)
		return tree[node];

	int left = 2*node;
	int right = 2*node + 1;
	int mid = (begin + end) >> 1;
	int val1 = query(left, begin, mid, l, r);
	int val2 = query(right, mid+1, end, l, r);
	return val1+val2;
}

void update(int node, int begin, int end, int pos, int val){
	if(pos > end || pos < begin)
		return;
	if(begin>=pos && end<=pos){
		tree[node] = val;
		return;
	}
	int left = 2*node;
	int right = 2*node + 1;
	int mid = (begin + end) >> 1;
	update(left, begin, mid, pos, val);
	update(right, mid+1, end, pos, val);
	tree[node] = tree[left] + tree[right];
}


void add(int node, int begin, int end, int pos, int val){
	if(pos > end || pos < begin)
		return;
	if(begin>=pos && end<=pos){
		tree[node] += val;
		return;
	}
	int left = 2*node;
	int right = 2*node + 1;
	int mid = (begin + end) >> 1;
	add(left, begin, mid, pos, val);
	add(right, mid+1, end, pos, val);
	tree[node] = tree[left] + tree[right];
}

int main()
{
	int t = 1;
	cin>>t;
	for (int cnt = 1; cnt <= t; ++cnt)
	{
		int n,q,a,l,r;
		cin>>n>>q;
		reset();
		for (auto i = 1; i <= n; i++) cin>>v[i];	
		create(1,1,n);
		printvec(tree,4*n)
		// queries
		cout<<"Case "<<cnt<<":\n";
		for (int i = 0; i<q; i++) {
			cin>>a;
			if(a==1) {
				int pos;
				cin>>pos;
				// cout<<pos<<endl;
				update(1,1,n,pos,0);
			}
			printvec(tree,4*n)

			if(a==2) {
				int pos,val;
				cin>>pos>>val;
				add(1,1,n,pos+1,val);
			}
			printvec(tree,4*n)

			if(a==3){
				int l,r,sum;
				cin>>l>>r;
				sum = query(1,1,n,l+1,r+1);
				cout<<sum<<endl;
			}
			printvec(tree,4*n)
			

		}

		
	}
	return 0;
}