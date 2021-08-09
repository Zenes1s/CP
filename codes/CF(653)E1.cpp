#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
	int n,k;
	cin>>n>>k;
	multiset<int> both,a,b;
	int time,al,bl;
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
	{
		cin>>time>>al>>bl;
		if(al&bl)
		{
			cnt1++;   
			cnt2++;
			both.insert(time);
		}
		else if(al)
		{
			cnt1++;
			a.insert(time);
		}
		else if(bl)
		{
			cnt2++;
			b.insert(time);
		}
		else
		continue;
	}
	if(cnt1<k || cnt2<k)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	multiset<int>::iterator it1,it2,it3;
	it1=a.begin();
	it2=b.begin();
	it3=both.begin();
	int ans=0;
	int alice=0;
	int bob=0;
	while(alice<k || bob<k)
	{
		//cout<<*it1<<" "<<*it2<<" "<<*it3<<endl;
		if(it1!=a.end() && it2!=b.end() && it3!=both.end())
		{
			if(*it1+*it2<=*it3)
			{
				ans+=*it1+*it2;
				it1++;
				it2++;
			}
			else
			{
				ans+=*it3;
				it3++;
			}
			alice++;
			bob++;  
		}
		else if(it1==a.end() && it2!=b.end() && it3!=both.end())
		{
			if(alice<k)
			{
				ans+=*it3;
				alice++;
				bob++;
				it3++;
			}
			else
			{
				if(*it2<=*it3)
				{
					ans+=*it2;
					bob++;
					it2++;
				}
				else
				{
					ans+=*it3;
					alice++;
					bob++;
					it3++;
				}
			}
		}
		else if(it2==b.end() && it1!=a.end() && it3!=both.end())
		{
			if(bob<k)
			{
				ans+=*it3;
				alice++;
				bob++;
				it3++;
			}
			else
			{
				if(*it1<=*it3)
				{
					ans+=*it1;
					alice++;
					it1++;
				}
				else
				{
					ans+=*it3;
					alice++;
					bob++;
					it3++;
				}
			}
		}
		else if(it1!=a.end() && it2!=b.end() && it3==both.end())
		{
			if(alice<k && bob<k)
			{
				ans+=*it1+*it2;
				alice++;
				bob++;
				it1++;
				it2++;
			}
			else if(alice<k)
			{
				ans+=*it1;
				alice++;
				it1++;
			}
			else
			{
				ans+=*it2;
				bob++;
				it2++;
			}			
		}
		else if(it1==a.end() && it2==b.end() && it3!=both.end())
		{
			ans+=*it3;
			it3++;
			alice++;
			bob++;
		}
	}
	cout<<ans<<endl;
}
