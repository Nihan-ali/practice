#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)

double a[15][15];
vector<pair<double,double>>v,vv;

void solve(double x[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            double cur=a[j][i]/a[i][i];
            a[j][i]=0;
            for(int k=i+1;k<=n+1;k++)
            {
                a[j][k]-=cur*a[i][k];
            }
        }
    }
    for(i=n;i>=1;i--)
    {
        x[i]=a[i][n+1]/a[i][i];
        for(j=i-1;j>=1;j--)
        {
            a[j][n+1]-=a[j][i]*x[i];
        }
    }
}



void direct(int n,double t)
{
    int i,j;
        double x[n+5];
        for(i=0;i<=n;i++)
        {
            double tt=vv[i].first,vt=vv[i].second,cur=1;
            for(j=1;j<=n+1;j++)
            {
                a[i+1][j]=cur;
                cur*=tt;
            }
            a[i+1][j]=vt;
        }
        solve(x,n+1);
        double res=0,cur=1;
        for(i=1;i<=n+1;i++)
        {
            res+=cur*x[i];
            cur*=t;
        }
        print(res);
}

void lagrange(int n,double T)
{
    double t[5],vt[5];
    for(int i=0;i<=n;i++)
    {
        t[i]=vv[i].first;
        vt[i]=vv[i].second;
    }
    double res=0;
    for(int i=0;i<=n;i++)
    {
        double cur=1;
        for(int j=0;j<=n;j++)
        {
            if(j!=i)
            {
                cur*=((T-t[j])/(t[i]-t[j]));
            }
        }
        cur*=vt[i];
        res+=cur;
    }
    print(res);
}

double val_b(double t[],double vt[],int l,int r)
{
    if(l==r)
        return vt[l];
    return (val_b(t,vt,l+1,r)-val_b(t,vt,l,r-1))/(t[r]-t[l]);
}

void newtonsdiv(double n,double T)
{
    double t[5],vt[5];

    for(int i=0;i<=n;i++)
    {
        t[i]=vv[i].first;
        vt[i]=vv[i].second;
    }
    double res=0;
    double b[5];
    b[0]=vt[0];
    int i,j;
    for(i=0;i<=n;i++)
    {
        b[i]=val_b(t,vt,0,i);
        //cout<<"b["<<i<<" ] = "<<b[i]<<endl;
    }
    double ans=0;
    for(i=0;i<=n;i++)
    {
        double cur=1;
        for(j=0;j<i;j++)
            cur*=(T-t[j]);
        ans+=b[i]*cur;
    }
    printf("ans = %.2lf\n",ans);
}

int main()
{
    int n,m,T;
    cin>>m>>T;
    int i,j;
    vector<pair<double,int>>dif;
    double t;
    for(i=0;i<m;i++)
    {
        double t,vt;
        cin>>t>>vt;
        v.push_back({t,vt});
        dif.push_back({fabs(T-t),i});
    }
    //sort(v.begin(), v.end());
    sort(dif.begin(), dif.end());
    ///for linear 
    cin>>t;
    for(n=1;n<=3;n++)
    {
        
        for(i=0;i<=n;i++)
        {
            vv.push_back(v[dif[i].second]);
        }
        sort(vv.begin(), vv.end());
        for(auto [x,y]:vv)
            cout<<x<<endl;
        cout<<endl;
        direct(n,T);
        //lagrange(n,T);
        //newtonsdiv(n,T);
        vv.clear();
        
    }


    return 0;
}
