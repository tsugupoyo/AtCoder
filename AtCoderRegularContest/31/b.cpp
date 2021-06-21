#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
bool graph[10][10];
bool visit[10][10];

void dfs(int w, int h)
{
   visit[h][w] = true;

   rep(i,4){
      int nx = w + dx[i];
      int ny = h + dy[i];
      if(nx < 0 || ny < 0 || nx >=10 || ny >= 10) continue;
      if(graph[ny][nx] == false) continue;
      if(visit[ny][nx]) continue;
      dfs(nx, ny);
   }

}

int main()
{
   rep(i,10)rep(j,10){
      char c;
      cin >> c;
      if(c == 'o') graph[i][j]= true;
   }

   //埋める位置をh、wとして全探索
   rep(h,10){
      rep(w,10){
         if(graph[h][w]) continue;
         graph[h][w] = true;
         int sh, sw;
         rep(i,10)rep(j,10) {
            if(graph[i][j]) 
            {
               sh =i; sw =j;
               break;
            }
         }
         rep(i,10)rep(j,10) visit[i][j] = false;
         dfs(sw,sh);
         bool ok = true;
         rep(i,10) rep(j,10){
            if(graph[i][j] && !visit[i][j])
            {
               ok = false;
               break;
            }
         }
         if(ok)
         {
            cout << "YES" << endl;
            return 0;
         }
         graph[h][w] = false;
      }
   }
   cout << "NO" << endl;

}