#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 105
int nodes,edges;
vector<int>adj[N],revadj[N],order;
int vis[N];

void dfs1(int u)
{
    vis[u]=1; 
    
    for(auto v:adj[u])
    {
        if(!vis[v])
            dfs1(v);
    }
    order.push_back(u);
}
void dfs2(int u)
{
    vis[u]=1; 
    cout<<u<<' ';
    for(auto v:revadj[u])
    {
        if(!vis[v])
            dfs2(v);
    }
}

int main()
{
    cin>>nodes>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        revadj[v].push_back(u);
    }
    for(int i=0;i<nodes;i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    reverse(order.begin(), order.end());
    int cnt=0; 
    for(auto i:order)
    {
        if(!vis[i])
        {
            cnt++;
            dfs2(i);
            cout<<endl;
        }
    }
    cout<<"Total number of SCC = "<<cnt<<endl;
    
    return 0;
}
