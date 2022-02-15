#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int mod = 1e9 + 7;
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}

int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}

int nCk(int n, int k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}
int main()
{
  int n,k,mod;
  cin>>n>>k>>mod;
  cout<<nCk(n,k)<<endl;
  return 0;
}
