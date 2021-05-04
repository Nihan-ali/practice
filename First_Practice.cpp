#include<bits/stdc++.h>

using namespace std;
#define print(x) cout << #x << " = " << x << endl

int main()
{int t;
    cin>>t;
    while(t--)
    {
        ll n,i,j,k,m,sum1=0,mx=0,x;
        cin>>n;
        ll a[n+5];
        vector<ll>v1;
        vector< ll > v[n+5];
        vector<ll>sum[n+5];
        vector<ll>ans[n+5];
        map<ll,ll>mp;
        for (int i = 0; i < n; ++i)
        {
            cin>>x;
            if(!mp[x]) v1.push_back(x),mp[x]++;a[i]=x;
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>k;sum1+=k;
            v[a[i]].push_back(k);
        }
        for (int i = 0; i <v1.size(); ++i)
        {
            j=v1[i];
            sort(v[j].rbegin(),v[j].rend());
        }
        for(i=1; i<=n; i++)
        {

            m=v[i].size();mx=max(mx,m);
        }
        for(k=0; k<v1.size(); k++)
        {
            i=v1[k];
            m=v[i].size();mx=max(mx,m);
            //ll ans=0;
           sum[i].push_back(0);
            for(j=1; j<=v[i].size(); j++)
            {
                sum[i].push_back(sum[i][j-1]+v[i][j-1]);
               cout<<"sum[ "<<i<<" ][ "<<j<<" ] = "<<sum[i][j]<<endl;
            }
//            for(j=1; j<=v[i].size(); j++)
//            {
//                ans[i][j]=sum[i][m]-sum[i][j];
//            }

        }
        for(i=1;i<=mx;i++)
        {ll ans1=sum1;if(i!=n)
            {for(k=0;k<v1.size();k++)
            {//print(sum[j][m%i]);
                j=v1[k];
            m=v[j].size();//cout<<" m = "<<m<<" j = "<<j<<" m%i = "<<m%i<<" sum "<<sum[j][m%i]<<endl;
                ans1-=sum[j][m%i];
            }}cout<<ans1<<' ';
        }for(i=mx+1;i<=n;i++)
        cout<<"0 ";
        cout<<endl;
    }
      return 0;
}
