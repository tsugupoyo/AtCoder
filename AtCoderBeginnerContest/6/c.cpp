#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{    
   int n, m;
   cin >> n >> m;

   //赤ちゃん(4本)で全て埋めて超えない場合は不可能
   if(n * 4 < m) {
      cout << "-1 -1 -1" << endl;
      return 0;
   }

   vector<int> ans(3);

   int tot = 3* n;
   ans[1] = n;
   rep(i,n){
      if(tot < m){
         tot -= 3;
         ans[1]--;
         tot += 4;
         ans[2]++;
      }
      else if( tot > m){
         tot -= 3;
         ans[1]--;
         tot += 2;
         ans[0]++;
      }
      else{
         break;
      }
   }
   if(tot != m){
      cout << "-1 -1 -1" << endl;
      return 0;
   }
   rep(i,3) cout << ans[i] << " ";
   cout << endl;
}