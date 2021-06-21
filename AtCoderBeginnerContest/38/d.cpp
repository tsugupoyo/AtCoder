#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int n;
   cin >> n;
   vector<P> p(n);
   rep(i,n){
      int w, h;
      cin >> w >> h;
      p.push_back(P(h,w));
   }
   //高さが高い順にソート
   sort(p.rbegin(), p.rend());

   vector<int> dp(n,INF);
   int ans = 0;

   rep(i,n){
      dp[i] = 1;
      rep(j,i) if(p[j].first > p[i].first && p[j].second > p[i].second)
      {
         dp[i] = max(dp[i], dp[j]+ 1);
      }
      ans = max(ans, dp[i]);
   }
   cout << ans << endl;
}

//部分点
int other (void) 
{
   int n;
   cin >> n;
   vector<P> p(n);
   rep(i,n){
      int w, h;
      cin >> w >> h;
      p.push_back(P(h,w));
   }
   //高さが高い順にソート
   sort(p.rbegin(), p.rend());

   vector<int> dp(n,INF);
   int ans = 0;

   rep(i,n){
      dp[i] = 1;
      rep(j,i) if(p[j].first > p[i].first && p[j].second > p[i].second)
      {
         dp[i] = max(dp[i], dp[j]+ 1);
      }
      ans = max(ans, dp[i]);
   }
   cout << ans << endl;
}