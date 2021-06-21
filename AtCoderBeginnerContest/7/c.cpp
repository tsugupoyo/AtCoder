#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

int main()
{
   int r, c, sx , sy, gx, gy;
   cin >> r >> c >> sy >> sx >> gy >> gx;

   vector<string> s(r);
   rep(i,r) cin >> s[i];

   queue<P> que;
   vector<vector<int>> memo(r, vector<int>(c));
   rep(i,r) rep(j,c) memo[i][j] = INF;
   que.push(P(sx-1,sy-1));
   memo[sy-1][sx -1] = 0;
   while(!que.empty())
   {
      P p = que.front(); que.pop();
      rep(i,4){
         int nx, ny;
         nx = p.first + dx[i];
         ny = p.second + dy[i];
        // cout << nx << " " << ny << endl;
         if(nx < 0 || ny < 0 || nx > c || ny > r) continue;
         if(s[ny][nx] == '#') continue;
         if(memo[ny][nx] != INF) continue;
         memo[ny][nx] = memo[p.second][p.first] + 1;
         if(ny == gy -1 && nx == gx -1)
         {
            cout << memo[ny][nx] << endl;
            return 0;
         }
         que.push(P(nx,ny));
      }
   }

   cout << -1 << endl;
}