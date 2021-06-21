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
   vector<string>c(h);
   vector<vector<int>> memo(h,vector<int>(w,INF));
   rep(i,h) cin >> c[i];
   P s;
   P g;
   rep(i,h)rep(j,w) 
   {
      if(c[i][j] == 's') s = P(i,j);
      if(c[i][j] == 'g') g = P(i,j);
   }

   deque<P> que;
   que.push_front(s);
   memo[s.first][s.second] = 0;
   while(!que.empty())
   {
      P p = que.front(); que.pop_front();
      rep(i,4)
      {
         int nx, ny;
         nx = p.second + dx[i];
         ny = p.first + dy[i];
         if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
         int dist = 0;
         bool wall = c[p.first][p.second] == '#';
         if(wall) 
         {
            dist =memo[p.first][p.second] + 1;
         }
         else {
            dist =memo[p.first][p.second];
         }

         // 暫定距離より短い経路が得られた場合は更新して、+1なら後ろに、+0なら前に付ける
         if(memo[ny][nx] > dist){
            memo[ny][nx] = dist;
            if(wall){
               que.push_back({ny, nx});
            }else{
               que.push_front({ny, nx});
            }
         }
      }
   } 
   cout << (memo[g.first][g.second] <= 2 ? "YES" : "NO") << endl; 
}