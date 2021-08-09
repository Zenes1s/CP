#include <bits/stdc++.h> 
using namespace std; 
#define int long long int
void subsetsUtil(int A[], vector<vector<int> >& res, 
                 vector<int>& subset, int index) 
{ 
    res.push_back(subset); 
    for (int i = index; i < 25; i++) { 
  
        // include the A[i] in subset. 
        subset.push_back(A[i]); 
  
        // move onto the next element. 
        subsetsUtil(A, res, subset, i + 1); 
  
        // exclude the A[i] from subset and triggers 
        // backtracking. 
        subset.pop_back(); 
    } 
  
    return; 
} 
  
// below function returns the subsets of vector A. 
vector<vector<int> > subsets(int A[]) 
{ 
    vector<int> subset; 
    vector<vector<int> > res; 
  
    // keeps track of current element in vector A; 
    int index = 0; 
    subsetsUtil(A, res, subset, index); 
  
    return res; 
} 
  
// Driver Code. 
signed main() 
{ 
    // find the subsets of below vector. 
    int arr[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97 }; 
  
    // res will store all subsets. 
    // O(2 ^ (number of elements inside array)) 
    // because at every step we have two choices 
    // either include or ignore. 
    vector<vector<int> > res = subsets(arr); 
  
    // Print result 
    for (int i = 0; i < res.size(); i++) 
    {
        int mul=1,mul1=1;
        int visited[100]={0};
        for (int j = 0; j < res[i].size(); j++) 
        {
            mul*=res[i][j];
            visited[res[i][j]]=1;
        }
        for(int k=0;k<25;k++)
        {
            if(!visited[arr[k]])
            mul1*=arr[k];
        }
        int x=mul;
        int y=mul1;
        if((x<=2e18 && x>=0)&&(y>=0 && y<=2e18))
        {
        	cout<<x<<" "<<y<<endl;
		}
    } 
  
    return 0; 
} 
