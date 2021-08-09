#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mx 200010
int t[4*mx];
int arr[mx];
void build(int v,int l,int r)
{
	if(l==r)
	t[v]=arr[l];
	else
	{
		int mid=(l+r)/2;
		build(2*v,l,mid);
		build(2*v+1,mid+1,r);
		t[v]=t[2*v]+t[2*v+1];
	}
}
int range(int v,int tl,int tr,int l,int r)
{
	if(l>r)
	return 0;
	else
	{
		if(tl==l && tr==r)
		return t[v];
		int m=(tl+tr)/2;
		int x=range(2*v,tl,m,l,min(r,m));
		int y=range(2*v+1,m+1,tr,max(l,m+1),r);
		return x+y;
	} 
}
void update(int v,int tl,int tr,int l,int r)
{
	if(tl==tr)
	t[v]=r;
	else
	{
		int m=(tl+tr)/2;
		if(l<=m)
		update(2*v,tl,m,l,r);
		else
		update(2*v+1,m+1,tr,l,r);
		t[v]=t[2*v]+t[2*v+1];
	}
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		for(int i=0;i<n;i++)
		cin>>arr[i];
		build(1,0,n-1);
		while(q--)
		{
			int x,y;
            char ch;
			cin>>ch>>x>>y;
			if(ch=='U')
			x--,update(1,0,n-1,x,y);
			else
	        {
	        	x--;
	        	y--;
	        	cout<<range(1,0,n-1,x,y)<<endl;
			}
		}
	}
}
