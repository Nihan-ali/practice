#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)

double x[100],y[100];

void linear_reg(int n)
{
    int i,j;
    double sumofxy=0,sumofx=0,sumofy=0,sumofx2=0;
    for(i=1;i<=n;i++)
    {
        sumofxy+=x[i]*y[i];
        sumofx+=x[i];
        sumofy+=y[i];
        sumofx2+=x[i]*x[i];
    }
    double a1=(n*sumofxy-sumofx*sumofy)/(n*sumofx2-sumofx*sumofx);
    double a0=sumofy/n-a1*sumofx/n;
    cout<<a0<<" + "<<a1<<" x\n";
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
    }
    linear_reg(n);
    return 0;
}
