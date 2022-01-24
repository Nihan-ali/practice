#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define output(x) cout << x << endl
#define print(x) cout << #x << " = " << x << endl
#define pi acos(-1)

int bigmod(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod; 
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int main()
{
    ll n,k,mod;
    cin>>n>>k>>mod;
    int ans=bigmod(n,k,mod);
    cout<<ans<<endl;
    return 0;
}
