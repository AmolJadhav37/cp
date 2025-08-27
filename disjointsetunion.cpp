//JAI SHRI RAM
//disjoint set union
#include <bits/stdc++.h>
using namespace std;
vector<int> dfus;
int find(int v)
{
    if(dfus[v] == -1)
        return v;
    return find(dfus[v]);
}
void unioun(int from,int to)
{
    from = find(from);
    to = find(to);
    dfus[from] = to;
}
bool iscylic(vector<pair<int,int>>&edges)
{
    for(auto edge:edges)
    {
        int from = edge.first;
        int to = edge.second;
        int root1 = find(from);
        int root2 = find(to);
        if(root1 ==root2)
            return true;
        unioun(root1,root2);
    }
    return false;
}

int main()
{
    int v,e;
    cin>>v>>e;
    dfus.resize(v,-1);
    vector<pair<int,int>>edges;
    for(int i = 0; i < e; i++)
    {
        int from,to;
        cout<<"ente edge {from,to}:";
        cin>>from>>to;
        edges.push_back({from,to});
    }

    if(iscylic(edges))
        cout<<"graph is cyclic"<<endl;
    else
        cout<<"graph is acyclic"<<endl;
    return 0;
}