#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int h, w;
int gx, gy;
bool graph[500][500];
bool visit[500][500];
bool ans;
bool finish;

void dfs(int x, int y)
{
   if(finish) return;
   visit[x][y] = true;
   if(gx == x && gy == y)
   {
      ans = true;
      finish = true;
      return;
   }
   rep(i,4){
      int nx, ny;
      nx = x + dx[i]; ny = y + dy[i];
      if((nx < 0 || ny < 0 || nx >= w || ny >= h) || (graph[nx][ny] == false) || visit[nx][ny]) continue;
      dfs(nx,ny);
   }
}

int main()
{
   cin >> h >> w;
   int sx, sy;

   rep(i,h) {
      rep(j,w) {
         char c;
         cin >> c;
         if(c == 's') { sx = j; sy = i; graph[j][i] = true;}
         else if(c == 'g') {gx = j; gy = i; graph[j][i] = true;}
         else if (c == '#') graph[j][i] = false;
         else graph[j][i] = true;
      }
   }

   dfs(sx, sy);
   if(ans) cout << "Yes" << endl;
   else cout << "No" << endl; 
}
