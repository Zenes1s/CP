#include<bits/stdc++.h>
using namespace std;
#define int long long int
int a[100010],v[100010];
signed main()
{
	int n,q;
	scanf("%lld %lld",&n,&q);
	int root=sqrt(n);
	for(int i=0;i<n;i++)
	scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
	{
		if(i%root==0)
		v[i/root]=a[i];
		else
		v[i/root]=min(v[i/root],a[i]);
	}
	for(int j=0;j<q;j++)
	{
		char ch;
		cin>>ch;
		int l,r;
		scanf("%lld %lld",&l,&r);
		l--;
		r--;
		if(ch=='q')
		{
		int ans=1e9;
		for(int i=l;i<=r;i++)
		{
			if(i%root==0 && i+root-1<=r)
			ans=min(ans,v[i/root]),i+=root-1;
			else
			ans=min(ans,a[i]);
		}
		printf("%lld\n",ans);
	    }
	    else
	    {
	    	int min=INT_MAX;
	    	a[l]=r+1;
	    	int x=l/root;
	    	for(int i=x*root;i<(x+1)*root && i<n;i++)
	    	{
	    		if(a[i]<min)
	    		min=a[i];
			}
			v[l/root]=min;
		}
	}
}
