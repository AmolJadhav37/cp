//JAI SHRI RAM
//weighted interval scheduling

/*
Should i be 
grateful or 
regretful for 
still being in 
love with those 
eyes which
gifted me tears
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 10e5+1;
int dp[N];
struct job
{
    int start;
    int finish;
    int weight;
};

int solve(vector<job>&jobs,int n)
{
    if(n == 0)
        return 0;
    
     if(dp[n] != -1) 
        return dp[n];
    int incl = jobs[n-1].weight;
    int nonconflict = -1;
    for(int j = n-2; j >= 0 ;j--)
    {
        if(jobs[j].finish <= jobs[n-1].start)
        {
            nonconflict = j;
            break;
        }
    }
    if(nonconflict != -1)
        incl += solve(jobs,nonconflict+1);
    int excl = solve(jobs,n-1);
    dp[n]=max(incl,excl);
    return dp[n];
}
int main()
{
    vector<job>jobs;
    memset(dp,-1,sizeof(dp));
    int n;
    cout<<"enter the number of jobs:"<<endl;
    cin>>n;
    for(int i = 0 ; i < n; i++)
    {
        int s,f,w;
        cout<<"enter start,finish,weight of job "<<i+1<<endl;
        cin>>s>>f>>w;
        jobs.push_back({s,f,w});
    }
    sort(jobs.begin(),jobs.end(),[](job &a,job &b)
    {
        return a.finish < b.finish;
    });

    int ans = solve(jobs,n);
    cout<<"the maximum weight of the jobs is:"<<ans<<endl;
    
}