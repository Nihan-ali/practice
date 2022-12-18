#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)

double a=8,b=30;

string s="300*x/(2+expm1(x))";
string s1="2000.*logl(140000./(140000-2100.*x))-9.8*x";

double f(double x)
{
    return 2000.*logl(140000./(140000-2100.*x))-9.8*x;
}

double trapi_single(double a ,double b)
{
    return (b-a)*(f(a)+f(b))*.5;
}

double trapi_multi(double a,double b, int n)
{
    double ans=f(a)+f(b);
    double h=(b-a)/n,cur=0;
    for(int i=1;i<n;i++)
    {
        cur+=2*f(a+i*h);
    }
    ans=(b-a)*(ans+cur)/(2.*n);
    return ans;
}

double simpson(double a, double b)
{
    double ans=(b-a)*(f(a)+4*f((a+b)/2)+f(b))/6;
    return ans;
}

double simpsonmulti(double a, double b, int n)
{
    double sum=f(a)+f(b),h=(b-a)/n;
    for(int i=1;i<n;i++)
    {
        double cur=f(a+i*h);
        if(i%2)
            sum+=4*cur;
        else
            sum+=2*cur;
    }
    return (b-a)*sum/(3*n);
}



int main()
{
    //print(trapi_single(8,30));
    print(simpson(a,b));
    for(int i=2;i<=10;i+=2)
    {
        printf("%.2lf\n",simpsonmulti(a,b,i));
    }
    return  0;

}
