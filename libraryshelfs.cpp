//JAI SHRI RAM
//Library Shelf Problem
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int WIDTH ;
int n;
int dp[1001][1001];
int solve(int i , vector<vector<int>>&books,int remaining_width,int maxH)
{
    if(i>=n)
        return maxH;

        if(dp[i][remaining_width]!=-1)
            return dp[i][remaining_width];
        int keep = INT_MAX;
        int skip = INT_MAX;
    //keep 
    if(remaining_width>=books[i][0])
    {
        keep = solve(i+1,books,remaining_width-books[i][0],max(maxH,books[i][1]));
    }
    //don't keep in current shelf
    skip =maxH + solve(i+1,books,WIDTH-books[i][0],books[i][1]);

    return dp[i][remaining_width] = min(keep,skip);
}
int main() { 
    
    memset(dp,-1,sizeof(dp));
   cout<<"enter number of books:";
   cin>>n;

   cout<<"enter the width of the shelf:";
   int shelf_width;
   cin>>shelf_width;
   WIDTH = shelf_width;
   vector<vector<int>>books(n,vector<int>(2));
   for ( int i = 0 ; i < n ; i++)
   {
    cout<<"enter width and height of book "<<i+1<<": ";
    cin>>books[i][0]>>books[i][1];
   }
   int ans = solve(0,books,shelf_width,0);
   cout<<"Minimum height of the shelf is: "<<ans<<endl;
    return 0;
}