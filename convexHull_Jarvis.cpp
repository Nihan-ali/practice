#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)
#define mod 1000000007

vector<pair<int,int>>points,hull;
int n;

bool isAnticolck(int p,int q,int r)
{
    int a1=points[p].first,a2=points[q].first,a3=points[r].first;
    int b1=points[p].second,b2=points[q].second,b3=points[r].second;
    return (b2-b1)*(a3-a2)-(a2-a1)*(b3-b2)<0;
}

void convexHull()
{
    int left=0;
    for(int i=1;i<n;i++)
    {
        if(points[i].first<points[left].first)
            left=i;
    }
    int p=left,q,i;
    do
    {
        hull.push_back(points[p]);
        q=(p+1)%n;
        for(i=0;i<n;i++)
        {
            if(isAnticolck(p,i,q))
                q=i;
        }
        p=q;
    }while(p!=left);
    for(auto [x,y]:hull)
    {
        cout<<x<<' '<<y<<endl;
    }
}

int main()
{
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        points.push_back({x,y});
    }
    convexHull();

    return 0;
}
/*
16 
7 7 
7 -7 
-7 -7 
-7 7 
9 0 
-9 0 
0 9 
0 -9 
0 0 
1 2 
-2 1 
-1 -1 
3 4 
4 3 
-5 4 
6 5
*/
