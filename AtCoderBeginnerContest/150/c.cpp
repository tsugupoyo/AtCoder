#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
   int n;
   cin >> n;
   vector<int> p(n),q(n),a(n);
   rep(i,n) cin >>  p[i];
   rep(i,n) cin >>  q[i];
   rep(i,n) a[i] = i+ 1;

   map<vector<int>,int> mp;

   do{
      mp[a] = mp.size();
   }while(next_permutation(a.begin(), a.end()));

   int ans = abs(mp[p] - mp[q]);

   cout << ans << endl;
}