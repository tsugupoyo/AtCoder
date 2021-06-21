#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const int dx[6] = {-1,0,1,-1,1,0};
const int dy[6] = {1,1,1,0,0,-1};
int main()
{
   int n, x, y;
   cin >> n >> x >> y;
   vector<vector<int>> table(403,vector<int>(403, INF));
   //スタート
   table[201][201] = 0;
   rep(i, n)
   {
      int xi, yi;
      cin >> xi >> yi;
      xi +=201; yi += 201;
      //壁
      table[xi][yi] = -1;
   }
   queue<P> que;
   que.push(P(201,201));
   while (!que.empty())
   {
      int xx = que.front().first;
      int yy = que.front().second; que.pop();

      //金の動きをする
      rep(i,6)
      {
         int nx = xx + dx[i];
         int ny = yy + dy[i];

         if(nx < 0 || ny < 0|| nx > 402 || ny > 402) continue;
         if(table[nx][ny] == -1) continue;
         if(table[nx][ny] <= table[xx][yy] + 1)continue;
         //最小を更新する
         table[nx][ny] = table[xx][yy] + 1;
         que.push(P(nx,ny));
      }
   }

   if(table[x+201][y+ 201] != INF) cout << table[x+201][y+ 201] << endl;
   else cout << -1 << endl;
}
