#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag, 
    tree_order_statistics_node_update>  nds;
#define pb push_back
#define mk make_pair
#define ff first  
#define ss second
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int,int>> 
#define vpci vector<pair<char,int>>
#define vpcc vector<pair<char,char>> 
#define mi map<int,int> 
#define mc map<char,int> 
#define mpii map<pair<int,int>,int> 
#define mpci map<pair<char,int>,int>
#define mpsi map<pair<string,int>,int>
#define ms map<string,int>
#define pii pair<int,int>
#define pc pair<char,char>
#define fbo find_by_order // (use *) value at  index in sorted array.
#define odk order_of_key  // tells index of element in array.
#define int long long int
#define double long double
#define f(x,a,b) for(int x=a;x<=b;x++)
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define wt() int t; cin>>t;while(t--)
bool cmp1(pair<int,pair<int,int> > &a,pair<int,pair<int,int> > &b)
{
    if(a.ss.ff==b.ss.ff)
    {
        if(a.ff==b.ff)
        {
            return a.ss.ss<=b.ss.ss;
        }
        return a.ff<=b.ff;
    }
    return a.ss.ff<=b.ss.ff;
}
bool cmp2(pair<int,pair<int,int> > &a,pair<int,pair<int,int> > &b)
{
    if(a.ss.ss==b.ss.ss)
    {
        if(a.ff==b.ff)
        {
            return a.ss.ff<=b.ss.ff;
        }
        return a.ff<=b.ff;
    }
    return a.ss.ss<=b.ss.ss;
}
 // Bhai modulo lene ke baad sub. karte waqt +mod lagana mat bhulna
 // warna time aur dimaag dono barbad honge faltu mai.
signed main()
{
    int n,q;
    cin>>n>>q;
    vector<pair<int,pair<int,int> > > v;
    f(i,0,n-1)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v.pb(mk(x,mk(y,z)));
    }
    sort(v.begin(),v.end());
    vector<pair<int,pair<int,int> > > v1=v;
    sort(v.begin(),v.end(),cmp1);
    vector<pair<int,pair<int,int> > > v2=v;
    sort(v.begin(),v.end(),cmp2);
    vector<pair<int,pair<int,int> > > v3=v;
    while(q--)
    {
        int r,b,g;
        cin>>r>>b>>g;
        int s=0;
        int e=n-1;
        int flag1=0,flag2=0,flag3=0;
        while(s<=e)
        {
            int mid=(e+s)/2;
            if(v1[mid].ff==r && v1[mid].ss.ff<=b && v1[mid].ss.ss<=g)
            {
                flag1=1;
                break;
            }
            if(v1[mid].ff==r)
            {
                if(v1[mid].ss.ff==b)
                {
                    if(v1[mid].ss.ss>g)
                    e=mid-1;
                    else
                    s=mid+1;
                }
                else if(v1[mid].ss.ff>b)
                e=mid-1;
                else
                s=mid+1;
            }
            else if(v1[mid].ff>r)
            e=mid-1;
            else
            s=mid+1;
        }
        if(flag1)
        {
            int s=0;
            int e=n-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                if(v2[mid].ss.ff==b && v2[mid].ff<=r && v2[mid].ss.ss<=g)
                {
                    flag2=1;
                    break;
                }
                if(v2[mid].ss.ff==b)
                {
                    if(v2[mid].ff==r)
                    {
                        if(v2[mid].ss.ss>g)
                        e=mid-1;
                        else
                        s=mid+1;
                    }
                    else if(v2[mid].ff>r)
                    e=mid-1;
                    else
                    s=mid+1;
                }
                else if(v2[mid].ss.ff>b)
                e=mid-1;
                else
                s=mid+1;
            }
        }
        if(flag2)
        {
            int s=0;
            int e=n-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                if(v3[mid].ss.ss==g && v3[mid].ff<=r && v3[mid].ss.ff<=b)
                {
                    flag3=1;
                    break;
                }
                if(v3[mid].ss.ss==g)
                {
                    if(v3[mid].ff==r)
                    {
                        if(v3[mid].ss.ff>b)
                        e=mid-1;
                        else
                        s=mid+1;
                    }
                    else if(v3[mid].ff>r)
                    e=mid-1;
                    else
                    s=mid+1;
                }
                else if(v3[mid].ss.ss>g)
                e=mid-1;
                else
                s=mid+1;
            }
        }
        int ans=flag1&flag2&flag3;
        if(ans)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
