#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
 	int n,q;
 	cin>>n>>q;
 	int h[n];
 	int a[n];
 	for(int i=0;i<n;i++)
 	cin>>h[i];
 	for(int i=0;i<n;i++)
 	cin>>a[i];
 	while(q--) 
 	{  
 		int no,x,y;
 		cin>>no>>x>>y;    
 		if(no==1)
 		a[x-1]=y;
 		else
 		{
 			x--;
 			y--;
 			int ans=0;
 			int flag=0;
 			if(h[x]<h[y])
 			{
 				cout<<"-1"<<endl;
 				continue;
			 }
			 if(x!=y && h[x]==h[y])
			 {
			 	cout<<"-1"<<endl;
			 	continue;
			 }
			 //cout<<"*"<<endl;
			 int start=min(x,y);
			 int end=max(x,y);
			 int mh=max(h[x],h[y]);
			 if(h[start]>h[end])
			 {
			 	int prev=h[end];
			 	for(int i=end-1;i>start;i--)
			 	{
			 		if(h[i]>prev)
			 		{
			 			prev=h[i];
			 		    ans+=a[i];
					 }
					 if(h[i]>=mh)
					 {
					 	//cout<<i<<endl;
					 	flag=1;
					 	break;
					 }
				 }
			 }
			 else
			 {
			 	int prev=h[start];
			 	for(int i=start+1;i<end;i++)
			 	{
			 		if(h[i]>prev)
			 		{
			 			prev=h[i];
			 			ans+=a[i];
					 }
					 if(h[i]>=mh)
					 {
					 	//cout<<i<<endl;
					 	flag=1;
					 	break;
					 }
				 }
			 }
			 if(flag)
			 {
			 	cout<<"-1"<<endl;
			 	continue;
			 }
			 else
			 {
			 	if(start!=end)
			 	cout<<ans+a[start]+a[end]<<endl;
			 	else
			 	cout<<ans+a[start]<<endl;
			 }
		}
	}
 }
