#include<bits/stdc++.h>
using namespace std;
#define int long long int
int max(int a,int b)
{
    return (a>=b?a:b);
}
void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int value=a[i];
        int flag=0,index=-1;
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>value)
            {
                flag=1;
            }
            if(flag==1 && a[j]<=value)
            {
                index=j;
                break;
            }
        }
        if(flag==0)
        {
            continue;
        }
        else
        {
            for(int k=i;k>index+1;k--)
            a[k]=a[k-1];
            a[index+1]=value;
            continue;
        }
    }
}
signed main()
{
    int n;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"\n";
    int a[n];
    cout<<"Input the array elements : \n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    insertion_sort(a,n);
    cout<<"Sorted Array by Insertion Sort :\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
