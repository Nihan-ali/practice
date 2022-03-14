#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000
int indeg[N+5]= {0},vis[N+5]={};
int n,m,u,v;
vector<int>adj[N+5];
vector<int>ans;

void AllPosTopoSort()
{
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(indeg[i]==0&&!vis[i])
		{
			for(auto v:adj[i])
				indeg[v]--;

			ans.push_back(i);
			vis[i]=1;
			AllPosTopoSort();
			vis[i]=0;
			ans.erase(ans.end() - 1);
			for(auto v:adj[i])
				indeg[v]++;
			flag=true;
		}
	}
	if(!flag)
	{
		for(auto i:ans)
			cout<<i<<' ';
		cout<<endl;
	}
}

int main()
{
    
    cin>>n>>m;

    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        ++indeg[v];
    }
    AllPosTopoSort();
    return 0;
}