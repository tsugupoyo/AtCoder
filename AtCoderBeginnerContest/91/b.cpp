#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n,m;
   cin >> n;
   map<string, int> mp;
   rep(i,n) 
   {
      string s;
      cin >> s;
      mp[s]++;
   }
   cin >> m;
   rep(i,m)
   {
      string t;
      cin >> t;
      mp[t]--;
   }
   int ans = 0;
   for(auto a : mp)
   {
      ans = max(ans, a.second);
   }
   cout << ans << endl;
}