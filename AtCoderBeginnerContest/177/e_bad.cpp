#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main(void) 
{
  int n;
  cin >> n;
  vector<ll> a(n);

  rep(i,n) cin >> a[i];

  rep(i, n)
  {
    ll ret = 1;
    for(int j= i+1; j < n; j++)
    {
      ret = gcd(a[i], a[j]);
      if(ret != 1) break;
    }
    if(ret == 1) continue;
    ll tmp = a[0];
    rep(j,n-1)
    {
      tmp = gcd(tmp, a[j+1]);
    }
    if(tmp == 1)
    {
      cout << "setwise coprime" << endl;
      return 0;
    }
    else
    {
      cout << "not coprime" << endl;
      return 0;
    }
  }

  cout << "pairwise coprime" << endl;
}