#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vvi = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n, m, p, q, r;
   cin >> n >> m >> p >> q >> r;
   vvi d(n,vector<int>(m));
   rep(i,r)
   {
      int x,y,z;
      cin >> x >> y >> z;
      d[x-1][y-1] = z;

   }  
   int ans = 0;
   //女子だけ全列挙する
   rep(i, 1 << n)
   {
      vector<int>sum(m);
      if(__builtin_popcount(i) != p) continue;
      rep(j,n) if(i >>j & 1)
      {
         rep(k,m) sum[k] += d[j][k];
      }
      sort(sum.rbegin(), sum.rend());
      int tmp = 0;
      rep(j,q) tmp += sum[j];
      ans = max(ans, tmp);
   }
   cout << ans << endl;
}