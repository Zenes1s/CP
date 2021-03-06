#include<bits/stdc++.h>
using namespace std;
#define int long long int
int getMinVertex(int *visited,int *weight,int n)
{
    int ans=INT_MAX,index;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(weight[i]<ans)
            {
                ans=weight[i];
                index=i;
            }
        }
    }
    return index;
}
void prims(int **edges,int n)
{
    int *visited=new int[n];
    int *parent=new int[n];
    int *weight=new int[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    weight[i]=INT_MAX;
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<n-1;i++)
    {
        //Find vertex with minimum weight
        int minVertex=getMinVertex(visited,weight,n);
        visited[minVertex]=1;
        //Now explore its unvisited neigbours and update them accordingly
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && edges[minVertex][j]!=0)
            {
                if(weight[j]>edges[minVertex][j])
                {
                    weight[j]=edges[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(parent[i]<i)
        cout<<parent[i]+1<<"     "<<i+1<<"     "<<weight[i]<<endl;
        else
        cout<<i+1<<"     "<<parent[i]+1<<"     "<<weight[i]<<endl;
    }
}
signed main()
{
        int n,e;
        cin>>n>>e;
        int **edges=new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            edges[i]=new int[n+1];
            for(int j=0;j<=n;j++)
            edges[i][j]=0;
        }
        for(int i=0;i<e;i++)
        {
            int s,d,w;
            cin>>s>>d>>w;
            s--,d--;
            edges[s][d]=w;
            edges[d][s]=w;
        }
        cout<<"MST by Kruskal's' Algorithm"<<endl;
        cout<<"Src"<<"  "<<"Dest"<<"  "<<"Weight"<<endl;
        //Prim's Algo.
        prims(edges,n);
}
