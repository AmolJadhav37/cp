//JAI SHREE RAM
//largest monochromatic square
#include <bits/stdc++.h>
#define v vector<int>
#define vv vector<vector<int>>
#define s set<int>
#define vp vector<pair<int,int>>

using namespace std;
const int N = 10e5+1;

int solve(int n, vv & square)
{
    vv dp(n,v(n,0));
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(square[i][j] == 1)
               {
                dp[i][j] = 1;
                if(i>0 && j>0)
                {
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;
                }
               }
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main ()
{
    int n;
    cin>>n;
    vv square(n,v(n));
    for(int i = 0 ; i < n ;  i++)
    {
        for(int j =0 ; j < n ; j++)
            cin>>square[i][j];
    }
    int ans = solve(n,square);
    cout<<ans<<endl;
}
