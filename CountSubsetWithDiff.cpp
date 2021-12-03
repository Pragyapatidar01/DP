//given array : a = [2,3,6,7,4,9]
//find the count of ==>  (S1-S2 = diff ) in an array


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int CountOfSubsetSum(int a[], int n, int W)
{
    int t[n+1][W+1];

    for (int i = 0; i <= n; i++)
        t[i][0] = 1;
 
    for (int i = 1; i <= W; i++)
        t[0][i] = 0;


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
    return t[n][W];
}
 
int main()
{
    int n; cin>>n;
    int diff; cin>>diff;
    int set[n];
    for(int i=0;i<n;i++)
    cin>>set[i];

    int sum_array = 0; 
    for (int i = 0; i < n; i++)
        sum_array += set[i];

    //WE have S1+S2 = sum_array
    // and   |S1-S2| = diff , so=>

    int sum = (diff+sum_array)/2;

    cout << "count: "
         << CountOfSubsetSum(set, n, sum);
    return 0;
}