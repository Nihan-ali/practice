#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)
#define sz 100005
#define inf 1e18

vector<int>adj[sz];
map<pair<int,int>,ll>mp;
ll dis[sz];
int parent[sz];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

void dijkstra(int source)
{
    parent[source]=-1;
    for(int i=0;i<sz;i++)
        dis[i]=inf;
    dis[source]=0;
    pq.push({0,source}); 
    while(!pq.empty())
    {
        ll cost=pq.top().first; 
        int u=pq.top().second;
        pq.pop();
        for(auto v:adj[u])
        {
            if(mp[{u,v}]+cost<dis[v])
            {
                dis[v]=mp[{u,v}]+cost;
                pq.push({dis[v],v});
                parent[v]=u;
            }
        }
    }
}

int main()
{
    int nodes,edges,i,j; 
    cin>>nodes>>edges;
    while(edges--)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}]=w;
        mp[{v,u}]=w;
    }
    int source,des;
    source=1;des=nodes;
    dijkstra(source);
    if(dis[des]>=inf)
    {
        cout<<-1<<endl;
    }
    else
    {
        //cout<<"Minimum distance from "<<source<<" to "<<des<<" is = "<<dis[des]<<endl;
        vector<int>path;
        while(des!=-1)
        {
            path.push_back(des);
            des=parent[des];
            
        }
        reverse(path.begin(), path.end());
            for(auto x:path)
                cout<<x<<' ';
            cout<<endl;
    }
    return 0;
}
