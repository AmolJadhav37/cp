//JAI SHRI RAM
//interval scheduling
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> intervals;
vector<int>finish_time;
vector<int>start_time;
void sort_by_finish_time()
{
    sort(intervals.begin(),intervals.end(),[](pair<int,int>&a,pair<int,int>&b)
{
    return a.second < b.second;
});
}

int main()
{
    int n;
    cin >>n;
    for(int i =0 ; i < n; i++)
    {
        int start,finish;
        cin>>start>>finish;
        intervals.push_back({start,finish});
    }
    sort_by_finish_time();
    int count = 0;
    int last_picked = INT_MIN;
    for(auto &it:intervals)
    {
        if(it.first>=last_picked)
        {
            count++;
            last_picked = it.second;
        }
    }
   cout<<count<<endl;
    return 0;

}