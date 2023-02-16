#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)
#define N 100000
int a[N+5],seg[4*N+5],lazy[4*N+5];
 
void build(int node,int l,int r)
{
	if(l==r)
	{
		seg[node]=a[l];
		//cout<<"seg "<<l<<" took "<<a[l]<<endl;
		lazy[node]=0;
		return;
	}
	int mid=(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	seg[node]+=seg[2*node]+seg[2*node+1];
	lazy[node]+=lazy[2*node]+lazy[2*node+1];
}
 
void update(int node,int l,int r,int L,int R,int val)
{
	if(l>R||r<L) return;
	if(L>=l&&R<=r)
	{
		seg[node]+=(R-L+1)*val;
		lazy[node]+=val;
		return;
	}
	int mid=(L+R)/2;
	update(2*node,l,r,L,mid,val);
	update(2*node+1,l,r,mid+1,R,val);
	seg[node]=seg[2*node]+seg[2*node+1]+(R-L+1)*lazy[node];
}//update(1,x,y,l,r,z);
 
int query(int node,int l,int r,int L,int R,int carry)
{
	if(l>R||r<L) return 0;
	if(L>=l&&R<=r)
	{
		//cout<<"gien "<<L<<" to "<<R<<endl;
		return seg[node]+carry*(R-L+1);
	}
	int mid=(L+R)/2;
	int x=query(2*node,l,r,L,mid,carry+lazy[node]);
	int y=query(2*node+1,l,r,mid+1,R,carry+lazy[node]);
	return x+y;
}//query(1,x-1,y-1,l,r,0);
 
int32_t main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
    	cout<<"Case "<<cas++<<":\n";
        int n,m,i,q,j,k,c,ans=0;
        cin>>n>>q;
        for(i=0;i<n;i++) cin>>a[i];
        for(i=0;i<4*n;i++) seg[i]=0;
        for(i=0;i<4*n;i++) lazy[i]=0;
        build(1,0,n-1);
        int l=0,r=n-1;
        while(q--)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int x,y,z;
                cin>>x;
                int val=query(1,x,x,l,r,0);
                cout<<val<<endl;
                update(1,x,x,l,r,-val);
 
            }
            else if(type==2)
            {
                int x,y;
                cin>>x>>y;
                update(1,x,x,l,r,y);
            }
            else
            {
            	int x,y;
            	cin>>x>>y;
            	cout<< query(1,x,y,l,r,0)<<endl;
            }
 
        }
 
    }
    return 0;
}
