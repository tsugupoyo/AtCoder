#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

struct edge {
    int to;
    int cost;
};

int main()
{
   int n;
   cin >> n;
   vector<int> p(n*n);
   rep(i,n*n) cin >> p[i];

   //1    2  3 .......n
   //n+1 n+2 .....    2n 
   //1 2 3
   //4 5 6
   //7 8 9
   vector<vector<bool>> dist(n,vector<bool>(n,false));
   ll ans = 0;
   for(int target: p)
   {
      queue<P> que;
      int x = target%n - 1; if(x == -1) x = n-1;
      int y = (target-1)/n;
      que.push(P(x,y));
      vector<vector<int>> dist2(n,vector<int>(n, INF));
      dist2[x][y] = 0;
      while(!que.empty())
      {
         int x = que.front().first;
         int y = que.front().second; que.pop();
         rep(i,4)
         {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
            int nn = 0;
            if(!dist[nx][ny]) nn = dist2[x][y] + 1;
            else nn = dist2[x][y];
            if(dist2[nx][ny] <= nn)continue;
            dist2[nx][ny] = nn;
            que.push(P(nx,ny));
         }
      }
      int tmp = INF;
      rep(i,n) tmp = min(tmp, dist2[0][i]);
      rep(i,n) tmp = min(tmp, dist2[n-1][i]);
      rep(i,n) tmp = min(tmp, dist2[i][0]);
      rep(i,n) tmp = min(tmp, dist2[i][n-1]);

      ans += tmp;
      dist[x][y] = true;
   }
   cout << ans << endl;
   return 0;
}