#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int sum=0;
		int flag=0;
		vector<pair<int,int> > v1;
		vector<int> v;
		map<int,int> mp,mp1,mp2; 
		int a[n],b[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(mp[a[i]]==0)
			v.push_back(a[i]);
			mp[a[i]]++;
			mp1[a[i]]++;
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			if(mp[b[i]]==0)
			v.push_back(b[i]);
			mp[b[i]]++;
			mp2[b[i]]++;
		}
		for(int i=0;i<v.size();i++)
		{
			int x=mp2[v[i]]+mp1[b[i]];
			if(x&1)
			{
				flag=1;
				break;
			}
			if(!(x&1) && mp2[v[i]]!=mp1[v[i]])
			{
				v1.push_back(make_pair(v[i],abs(mp1[v[i]]-mp2[v[i]])));
				sum+=abs(mp1[v[i]]-mp2[v[i]])/2;
			}
		}
		if(flag)
		{
			cout<<"-1"<<endl;
			continue;
		}
		else
		{
			int check=sum/2;
			int cnt=0;
			int ans=0;
			sort(v1.begin(),v1.end());
			for(int i=0;i<v1.size();i++)
			{
				if(cnt+v1[i].second>check)
				{
					ans+=(check-cnt)*v1[i].first;
					break;
				}
				else
				{
					ans+=v1[i].first*v1[i].second;
					cnt+=v1[i].second;
				}
			}
			cout<<ans<<endl;
		}
	}
}
