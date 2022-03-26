#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 105
int nodes,edges;
vector<int>adj[N];
int disc[N],low[N],vis[N];
stack<int>st;
void tarjan(int u)
{
    static int time=0;

    disc[u]=low[u]=++time;
    
    st.push(u);
    vis[u]=1; 
    for(auto v:adj[u])
    {
        if(disc[v]==-1)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
        {
            low[u]=min(low[u],disc[v]);
        }
    }
    int w=0;
    if(low[u]==disc[u])
    {
        while(st.top()!=u)
        {
            w= st.top();
            cout<<w<<' ';
            vis[w]=0;
            st.pop();
        }
        w= st.top();
        cout<<w<<endl;
        vis[w]=0;
        st.pop();
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
    }
    memset(vis,0,sizeof(vis));
    memset(disc,-1,sizeof(disc));
    memset(low,-1,sizeof(low));
    for(int i=0;i<nodes;i++)
    {
        if(disc[i]==-1)
            tarjan(i);

    }
    
    return 0;
}
