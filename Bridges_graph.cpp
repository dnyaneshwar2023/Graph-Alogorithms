#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,vector<int>>g;
map<int,int>vis;
int low[100001];
int in[100001];
int timer;
void dfs(int node,int parent)
{
    vis[node] = 1;
    in[node] = low[node] =  ++timer;

    for(auto v:g[node])
    {
        if(v == parent)
        continue;
        if(vis[v] == 1)
        {
            low[node] = min(low[node],in[v]);
        }
        else
        {
            dfs(v,node);

            if(low[v] > in[node])
            {
                cout << "Bridge : " << node << ' ' << v << '\n';
            }

            low[node] = min(low[node],low[v]);
        }
    }
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
    for(int i=1;i<=n;i++)
    low[i] = in[i] = 100000000;

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1);
        }
    }


}
