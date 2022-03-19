#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)

int vis[100];
vector<int>order;

void combination(int n,int r,int j)
{
    if(order.size()==r)
    {
        for(auto i:order)
            cout<<i<<' ';
        cout<<endl;
        return;
    }
    for(int i=j;i<=n;i++)
    {
        if(!vis[i])
        {
            order.push_back(i);
            vis[i]=1; 
            combination(n,r,i+1);
            order.pop_back();
            vis[i]=0;
        }

    }
}
void permutation(int n,int r)
{
    if(order.size()==r)
    {
        for(auto i:order)
            cout<<i<<' ';
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            order.push_back(i);
            vis[i]=1; 
            permutation(n,r);
            order.pop_back();
            vis[i]=0;
        }

    }
}

int main()
{
    int n,i,j,r;
    cin>>n>>r;
    //For nCr
    cout<<"ways to take r numbers from n numbers: \n";
    combination(n,r,1);
    //For nPr
    cout<<"ways to sit r students at n seats: \n";
    memset(vis,0,sizeof(vis));
    order.clear();
    permutation(n,r);
    return 0;
}
