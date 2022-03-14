#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000
int indeg[N+5]= {0};
vector<int>adj[N+5];
vector<int>ans;

void TopoSort(int n)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(!indeg[i]) q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(auto v:adj[u])
        {
            if(--indeg[v]==0) q.push(v);
        }
    }
    if(ans.size()!=n) 
    {
        cout<<"No TopoSort exits\n";
        return;
    }
    for(auto i:ans)
    {
        cout<<i<<' ';
    }
    cout<<endl;
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;

    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        ++indeg[v];
    }
    TopoSort(n);
    return 0;
}

