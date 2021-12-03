//given array : a = [2,3,6,7,4,9]
//can we divide the array in 2 subsets such that there sum S1, S2 and S1-S2 = 0 ;

// for checking this, we just check that there is a subset with sum = (sum_of_array)/2 

#include <bits/stdc++.h>
using namespace std;
 
bool findpartition(int arr[], int n)
{
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)      //if sum is not even, equal partition not possible
        return false;
 
    bool t[sum / 2 + 1][n + 1]; 
 
    for (i = 0; i <= n; i++)
        t[0][i] = true;
 

    for (i = 1; i <= sum / 2; i++)
        t[i][0] = false;
 
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            t[i][j] = t[i][j - 1];
            if (i >= arr[j - 1])
                t[i][j] = t[i][j] || t[i - arr[j - 1]][j - 1];
        }
    }
 
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<t[i][j];
    cout<<endl;
    } 
 
    return t[sum / 2][n];
}
 
int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
     
    // Function call
    if (findpartition(arr, n) == true)
        cout << "Can be divided into two subsets of equal sum";
    else
        cout << "Can not be divided into two subsets of equal sum";
    return 0;
}