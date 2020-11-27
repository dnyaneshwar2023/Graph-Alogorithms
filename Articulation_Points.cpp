#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,vector<int>>g;
map<int,int>vis;
int low[100001];
int in[100001];
int timer;
set<int> points;
void dfs(int node,int parent = -1)
{
    vis[node] = 1;
    in[node] = low[node] =  ++timer;
    int children=0;
    for(auto child:g[node])
    {
        if(child == parent)
        continue;
        if(vis[child] == 1)
        {
            low[node] = min(low[node],in[child]);
        }
        else
        {
            dfs(child,node);
            low[node] = min(low[node],low[child]);
            if(low[child] >= in[node] && parent!=-1)
            {
                points.insert(node);
            }

            ++children;
        }
    }
    if(parent == -1 && children > 1)
    points.insert(node);
}
signed main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    for(int i=1;i<=100000;i++)
    low[i] = in[i] = 100000000;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    cout << points.size() << '\n';
    for(auto it:points) cout << it << ' ';


}
