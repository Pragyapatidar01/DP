//given:  wt = [1,2,4,5]      
//        val = [1,3,5,7]
//        So, n=4 (size of arrays)
//        max weight for knapsack = W = 11 
//ques:   maximize the profit

// DP SOLN

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
 ll t;cin>>t;
  while(t--){
    int n; cin>>n;
    int W; cin>>W;
    int wt[n] , val[n] ;
    for(int i=0;i<n;i++)
    cin>>wt[i];
    for(int i=0;i<n;i++)
    cin>>val[i];

    int t[n+1][W+1];

    //recursive BASE condition = DP initialisation
    for(int i=0;i<n+1;i++)
    for(int j=0;j<W+1;j++)
    {
        if(i==0 || j==0)
        t[i][j] = 0;
    }

    //leaving the first row and col, we fill the rest of the array according the choice diagram that used recursion previously.
	// In DP, no recursion.

    for(int i=1;i<n+1;i++)
    for(int j=1;j<W+1;j++)
    {
        if(wt[i-1]<=j)
        {
            t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
        }
        else
        t[i][j] = t[i-1][j];
    }

    cout<<t[n][W]<<endl;
  }
  return 0;
}