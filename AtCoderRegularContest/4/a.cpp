#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n;
   cin >> n;
   vector<P> p(n);
   rep(i,n) {
      cin >> p[i].first; 
      cin >> p[i].second;
   }
   double ans = 0;

   rep(i,n -1){
      for(int j = i+1; j < n; j++){
         int dx = abs(p[i].first -p[j].first);
         int dy = abs(p[i].second -p[j].second);
         ans = max(ans, sqrt(pow(dx,2) + pow(dy,2)));
      }
   }
   cout << ans << endl;
}