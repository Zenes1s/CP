#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool comparator(pair<int,int> &a,pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
signed main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,a+b));
    }
    sort(v.begin(),v.end(),comparator);
    int cnt=1;
    int j=0;
    for(int i=1;i<n;)
    {
        int k=i;
        while(v[k].first<=v[j].second && k<n)
        cnt++,k++;
        i=k+1;
        j++;
    }
    cout<<cnt<<endl;
}
