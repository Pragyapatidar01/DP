//given array : a = [2,3,6,7,4,9]
//is there any subset that has sum =14 

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isSubsetSum(int set[], int n, int sum)
{

    bool subset[n + 1][sum + 1];
 
    //recursive BASE condition = DP initialisation
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;                //sum I need is 0, so an empty subset always exists
 
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;              //when array is empty,no elements to choose from
 
    // Fill the subset table in botton up manner
    //leaving the first row and col, we fill the rest of the array according the choice diagram that used
	// recursion previously. In DP, no recursion.

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i-1][j - set[i - 1]];
        } 
    }
 
    return subset[n][sum];
}
 
int main()
{
    int n; cin>>n;
    int sum ;cin>>sum;
    int set[n];
    for(int i=0;i<n;i++)
    cin>>set[i];

    if (isSubsetSum(set, n, sum) == true)
        cout << "True";
    else
        cout << "False";
    
    return 0;
}