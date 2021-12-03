 //given array : a = [2,3,6,7,4,9]
//find the minimum difference between the sum of two subsets of array


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int findMin(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0; 
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    int halfSum = sum/2;
    bool dp[n+1][halfSum+1];
 

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= halfSum; i++)
        dp[0][i] = false;
 
    // Fill the partition table in bottom up manner
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=halfSum; j++)
        {
            // If i'th element is excluded
            dp[i][j] = dp[i-1][j];
 
            // If i'th element is included
            if (arr[i-1] <= j)
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }
  
    // Initialize difference of two sums. 
    int diff = INT_MAX;

    //let the sums of the subset are S1 and S2
    // now the range for (S1-S2) = (0 to sum)
    // also (S1+S2)=sum
    // we need to calculate the minimum |S1-S2| = sum-S2-S2 = sum-2*S2 
     
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=halfSum; j>=0; j--)
    {
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
 
int main()
{
    int n; cin>>n;
    int set[n];
    for(int i=0;i<n;i++)
    cin>>set[i];

    cout << "The minimum difference between 2 sets is "
         << findMin(set, n);
    return 0;
}