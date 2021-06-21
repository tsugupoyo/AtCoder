#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int n;
   cin >> n;
   vector<int> a(n);
   rep(i,n) cin >> a[i];

   int ans = 1;
   vector<int> cnt(100005);
   int l = 0;
   rep(r,n)
   {
      while(cnt[a[r]] >= 1)
      {
         --cnt[a[l]];
         l++;
      }
      cnt[a[r]]++;
      while(1)
      {
         if(cnt[a[l]] == 1) break;
         --cnt[a[l]];
         l++;
      }
      //cout << l << " " << r << endl;
      ans = max(ans, r-l+1);
   }
   cout << ans << endl;
}