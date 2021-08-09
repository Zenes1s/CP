#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,k;
int a[200010];
int validE(int x)
{
	int cnt=0;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(!flag)
		{
			cnt++;
			flag^=1;
		}
		else
		{
			if(a[i]<=x)
			{
				cnt++;
				flag^=1;
			}
		}
	}
	if(cnt>=k)
	return 1;
	else
	return 0;
}
int validO(int x)
{
	int cnt=0;
	int flag=1;
	for(int i=0;i<n;i++)
	{
		if(!flag)
		{
			cnt++;
			flag^=1;
		}
		else
		{
			if(a[i]<=x)
			{
				cnt++;
				flag^=1;
			}
		}
	}
	if(cnt>=k)
	return 1;
	else
	return 0;
}
int solve(int lb,int hb)
{
	int mid,ans=1e9;
	while(lb<hb)
	{
		mid=(lb+hb)/2;
		if(validO(mid) || validE(mid))
		hb=mid,ans=min(ans,mid);
		else
		lb=mid+1;
	}
	return ans;
}
signed main()
{
	int t;
	t=1;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
		cin>>a[i];
		int lb=1;
		int hb=1e9;
		int ans=solve(lb,hb);
		cout<<ans<<endl;
	}
}
