#include<bits/stdc++.h>
using namespace std;
#define int long long int
int max(int a,int b)
{
    if(a>=b)
    return a;
    else
    return b;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *a=new int[n+1];
        int cnt=0;
        vector<int> v;
        v.push_back(0);
        for(int i=1;i<=n;i++)
        cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==0)
            {
                v.push_back(i);
            }
        }
        for(int i=1;i<v.size()-1;i++)
        {
            cout<<v[i]<<endl;
            if(a[i]%4!=0)
            {
            int x=max(0,v[i]-v[i-1]-1);
            int y=max(0,v[i+1]-v[i]-1);
            cout<<x<<" "<<y<<endl;
            if(x!=0 && y!=0)
            cnt+=2*(x+y);
            else
            cnt+=(x+y);
            }
            if(a[i]%4==2)
            cnt++;
        }
        if(a[v[v.size()-1]]%4!=0)
        {
        int x=max(0,v[v.size()-1]-v[v.size()-2]-1);
        int y=max(0,n-v[v.size()-1]);
        if(x!=0 && y!=0)
        cnt+=2*(x+y);
        else
        cnt+=(x+y);
        if(a[v[v.size()-1]]%4==2)
        cnt++;
        }
        cout<<cnt<<endl;
        int total=n*(n+1);
        cout<<(total/2)-cnt<<endl;
    }
}