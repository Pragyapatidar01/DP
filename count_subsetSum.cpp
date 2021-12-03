//given array : a = [2,4,5,6,7,9,7]
//how many subsets that has sum =14 
//ans: {9,5},{7,7},{7,5,2} = 3

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
 ll t;cin>>t;
  while(t--){
    int n; cin>>n;
    int W; cin>>W;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    int t[n+1][W+1];

    //recursive BASE condition = DP initialisation
    for (int i = 0; i <= n; i++)
        t[i][0] = 1;
 
    for (int i = 1; i <= W; i++)
        t[0][i] = 0;

    //leaving the first row and col, we fill the rest of the array according the choice diagram that used recursion previously. In DP, no recursion.

    for(int i=1;i<n+1;i++)
    for(int j=1;j<W+1;j++)
    {
        if(a[i-1]<=j)
        {
            t[i][j] = (t[i-1][j-a[i-1]] + t[i-1][j]);
        }
        else
        t[i][j] = t[i-1][j];
    }

    for(int i=0;i<n+1;i++)
    {for(int j=0;j<W+1;j++)
    cout<<t[i][j]<<" ";
    cout<<endl;
    }
    cout<<"ans:"<<t[n][W]<<endl;
  }
  return 0;
}