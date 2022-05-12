#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)
vector<pair<int,int>>points;
vector<pair<int,int>>hull;
int n;

bool isAnticolck(int p,int q,int r)
{
	int a1=hull[p].first,a2=hull[q].first,a3=points[r].first;
    int b1=hull[p].second,b2=hull[q].second,b3=points[r].second;
    return (b2-b1)*(a3-a2)-(a2-a1)*(b3-b2)<0;
}

void convexHull()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(hull.size()<2)
		{
			hull.push_back(points[i]);
			continue;
		}
		int p=hull.size()-2,q=hull.size()-1,r=i;
		if(isAnticolck(p,q,r))
        {
        	hull.push_back(points[i]);
        }
        else
        {
        	hull.pop_back();
        	i--;
        }

	}
	hull.pop_back();
	for(auto [x,y]:hull)
	{
		cout<<x<<' '<<y<<endl;
	}

}

int main()
{
	int i,j;
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		points.push_back({x,y});
	}
	sort(points.begin(), points.end());

	convexHull();
	
	hull.clear();

	reverse(points.begin(), points.end());

	convexHull();
	
	hull.clear();

	return 0;

}
/*
72 0 0 1 2 -2 1 -1 -1 3 4 4 3 -5 4 6 5 7 7 7 -7 -7 -7 -7 7 9 0 -9 0 0 9 0 -9 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 0 0 -8 0 8 0 -7 0 7 0 -6 0 6 0 -5 0 5 0 -4 0 4 0 -3 0 3 0 -2 0 2 0 -1 0 1 1 1 2 2 3 3 4 4 5 5 6 6 1 -1 2 -2 3 -3 4 -4 5 -5 6 -6 -1 1 -2 2 -3 3 -4 4 -5 5 -6 6 -1 -1 -2 -2 -3 -3 -4 -4 -5 -5 -6 -6
*/
