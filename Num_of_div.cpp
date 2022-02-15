//Numbwe of divisors up to 10e12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define pi acos(-1)
#define N 1000000
ll siv[N+5];
vector<ll>primes;

void sieve()
{
  long long int i, j;
    for (i=3; i<N; i+=2)
        if(!siv[i])
            for (j=i*i; j<N; j+=i+i)
                siv[j]=1;
  primes.push_back(2);
  for(i=3;i<=N;i+=2)
    if(!siv[i]) primes.push_back(i);
  return;

}

ll num_of_divisors(ll n)
{
    
    ll i,j,k,divisors=1;
    for(i=0;i<primes.size()&&primes[i]*primes[i]<=n;i++)
    {
        ll cnt=0;
        while(n>1&&n%primes[i]==0)
        {
          n/=primes[i];
          cnt++;
        }
        divisors*=cnt+1;
    }
    if(n!=1) divisors*=2;
    return divisors;
}

int main()
{
    sieve();
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<cas++<<": ";
        ll n,m,i,k;
        cin>>n;
        ll ans=num_of_divisors(n);
        cout<<ans<<endl;

    }
    return 0;
}
