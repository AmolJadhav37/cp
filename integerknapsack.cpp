//JAI SHRI RAM
//integer knapsack
#include <bits/stdc++.h>
using namespace std;

int value[100];
int weight[100];
int dp[100][1000];
//assuming items are only between 1 to 100 and weight is between 1 to 1000
int knapsack(int n,int w)
{
    if(w==0 || n < 0)
    return 0;
    if(dp[n][w]!=-1)
    return dp[n][w];
    //case 1:item not taken
    int ans = knapsack(n-1,w);
    //case2:item taken
    if(weight[n]<=w)
        ans = max(ans,knapsack(n-1,w-weight[n])+value[n]);
    return dp[n][w] = ans;

}
int main()
{
    int n,w;
    cin>>n>>w;
    memset(dp,-1,sizeof(dp));
    for ( int i =0 ; i < n ; i++)
    {
        cin>>value[i]>>weight[i];
    }
    cout<<knapsack(n-1,w)<<endl;
}