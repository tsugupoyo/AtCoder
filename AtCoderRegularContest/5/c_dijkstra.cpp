#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;
using T = tuple<int,int,int,int>;
using vvvi = vector<vector<vector<int>>>;
using vvi = vector<vector<int>>;
using vi = vector<int>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

//ダイクストラ法で解く

int main()
{
   int h, w;
   cin >> h >> w;
   vector<string>c(h);

   rep(i,h) cin >> c[i];
   P s;
   P g;
   rep(i,h)rep(j,w) 
   {
      if(c[i][j] == 's') s = P(i,j);
      if(c[i][j] == 'g') g = P(i,j);
   }

   vvvi dp(h,vvi(w,vi(3, INF)));
   priority_queue<T, vector<T>, greater<T>> que;
   que.push(make_tuple(0, s.first, s.second, 0));

   while(!que.empty())
   {
      auto q = que.top(); que.pop();
      int cost = get<0>(q);
      int y =  get<1>(q);
      int x = get<2>(q);
      int state = get<3>(q);

      if(dp[y][x][state] < cost) continue;
      rep(i,4)
      {
         int nx = x + dx[i];
         int ny = y + dy[i];

         if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
         if(c[ny][nx] == '#') 
         {
            if(state == 2) continue;
            if(cost + 1 < dp[ny][nx][state+1])
            {
               dp[ny][nx][state+1] = cost +1;
               que.push(T(cost +1, ny,nx,state+1));
            }
         }
         else
         {
            if(cost + 1 < dp[ny][nx][state])
            {
               dp[ny][nx][state] = cost +1;
               que.push(T(cost +1, ny, nx, state));
            }
         }
      }
   }
   bool ok = false;
   rep(i,3) if(dp[g.first][g.second][i] < INF) ok = true;
   cout << (ok ? "YES" : "NO") << endl;

}