#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n, m;
   cin >> n >> m;
   bool table[n][n];
   rep(i,n) rep(j,n) table[i][j] = false;
   rep(i,m){
      int x, y;
      cin >> x >> y;
      --x; --y;
      table[x][y] = true;
      table[y][x] = true;
   }
   int ans = 0;
   
   rep(i, 1 << n){
      vector<int> group;
      rep(j, n){
         if(i >> j&1)
         {
            group.push_back(j);
         }
      }
      bool ok = true;
      for(int a : group)
      {
         ok = true;
         for(int b : group)
         {
            if(a == b) continue;
            if(!table[a][b])
            {
                  ok = false;
                  break;
            }
            
            if(!ok) break;
         }
         if(!ok) break;
      }
      int size = group.size();
      if(ok)  ans = max(ans, size);
   }

   cout << ans << endl;
}