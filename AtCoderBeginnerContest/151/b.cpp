#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
   int n,k,m;
   cin >> n >> k >> m;
   vector<int> a(n -1);
   rep(i,n-1) cin >> a[i];

   int need = n * m;
   int current =0;
   rep(i,n-1) current += a[i];

   int ans = need - current;

   if(ans > k) cout << -1 << endl;
   else if(ans <= 0) cout << 0 << endl;
   else cout << ans << endl;
}