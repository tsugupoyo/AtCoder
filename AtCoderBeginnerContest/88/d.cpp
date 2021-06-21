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
   int h, w;
   cin >> h >> w;
   vector<string> s(h);
   rep(i,h) cin >> s[i];
   queue<P> que;
   vector<vector<int>> memo(h, vector<int>(w,INF));
   que.push(P(0,0));
   memo[0][0] = 0;
   int sum = -1;
   while(!que.empty())
   {
      P p = que.front(); que.pop();
      int nx, ny;
      rep(i,4){
         nx = p.second + dx[i];
         ny = p.first + dy[i];
         if(nx < 0 || ny < 0 || nx >= w || ny >= h ) continue;
        // cout << nx << " " << ny << endl;
         if(s[ny][nx] == '#') continue;
         if(memo[ny][nx] != INF) continue;
         memo[ny][nx] = memo[p.first][p.second] + 1;
         que.push(P(ny,nx));
         if(ny == h-1 && nx == w-1) 
         {
            sum = memo[ny][nx];
            break;
         }
      }
   }
   if(sum == -1)
   {
      cout << -1 << endl;
      return 0;
   }
   int black =0;
   rep(i,h)rep(j,w) if(s[i][j] == '#') ++black;
   int ans = h*w - black -sum -1;
   cout << ans << endl;

}