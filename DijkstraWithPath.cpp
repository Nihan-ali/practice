#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)
#define sz 100000
vector<int>adj[sz+5];
map<pair<int,int>,ll>mp;
priority_queue<int>pq;
ll dis[sz+5],inf=1e18;
int parent[sz+5];
int n,m;

void dijkstra(int source)
{
    parent[source]=-1;
    for(int i=0;i<=n;i++)
        dis[i]=inf;
    dis[source]=0;
    pq.push(source);
    while(!pq.empty())
    {
        int u=pq.top();
        pq.pop();
        for(auto v:adj[u])
        {
            ll cost = mp[{u,v}];
            if(dis[u]+cost<dis[v])
            {
                dis[v]=dis[u]+cost;
                pq.push(v);
                parent[v]=u;
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    int i,j;
    for(i=1;i<=m;i++)
    {
        int u,v;
        ll weight;
        cin>>u>>v>>weight;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}]=weight;
        mp[{v,u}]=weight;
    }
    int source=1,des=n;
    dijkstra(source);
    for(i=1;i<n;i++)
    {
        cout<<"dis from "<<source<<" to v = "<<i<<" is "<<dis[i]<<endl;
    }
    
    if(dis[n]==inf)
    {
        cout<<-1<<endl;
    }
    else
    {
        vector<int>path;
        while(parent[des]!=-1)
        {
            path.push_back(des);
            des=parent[des];
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
        for(auto node:path)
        {
            cout<<node<<' ';
        }cout<<endl;
   }
    return 0;
}
