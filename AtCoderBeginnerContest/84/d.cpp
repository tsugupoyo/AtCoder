#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int q;
   cin >> q;
   vector<int> l(q), r(q);
   int m = 0;
   rep(i,q)
   {
      cin >> l[i] >> r[i];
      m = max(m, r[i]);
   }
   //mまでの素数をエラトステネスの篩で解く
   vector<bool> isprime(m+1, true);
   vector<ll> sum(m+1,0);
   isprime[0] = isprime[1] = false;
   int cnt = 0;
   for(int i = 2; i <= m; i++)
   {
      if(isprime[i])
      {
         for(int j =2*i; j <= m ;j+=i) isprime[j] = false;
      }
      if(isprime[i] && isprime[(i+1)/2]) sum[i] = sum[i-1] +1;
      else sum[i] = sum[i-1];
   }
  // rep(i,sum.size()) cout << sum[i] << endl;
   rep(k,q)
   {
      cout << sum[r[k]] - sum[l[k]-1] << endl;
   }
}