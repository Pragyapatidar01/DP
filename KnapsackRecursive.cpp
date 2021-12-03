//given:  wt = [1,2,4,5]      
//        val = [1,3,5,7]
//        So, n=4 (size of arrays)
//        max weight for knapsack = W = 11 
//ques:   maximize the profit

// RECURSIVE SOLN

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int knapsack(int wt[], int val[], int n, int W)
{
  //if the size of array becomes 0 or capacity of knapsack becomes 0 (base condition)
  if(n==0 || W==0)
  return 0;

  //if weight of the last element of weight array is less or equal to the capacity of knapsack,
  //then we take the max(either we put the item in knapsack or not)
  if(wt[n-1]<=W)
  {
    return max(val[n-1] + knapsack(wt, val, n-1, W-wt[n-1]), knapsack(wt, val, n-1, W));
  }
  else
  return knapsack(wt, val, n-1, W);         //else we don't take the item in knapsack

}

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

    int max_profit = knapsack(wt, val, n, W);
    cout<<max_profit<<endl;
    
  }
  return 0;
}
