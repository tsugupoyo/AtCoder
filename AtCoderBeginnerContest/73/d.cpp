#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int N, M, R;
int dist[201][201];
bool visit[8];
int ans = INF;
vector<int> r(9);

//rのインデックス、前回のインデックス、合計
void dfs(int v, int prev, int d){

   if(v == R + 1){
      //終了
      if(ans > d) ans = d;
      return;
   }

   for ( int i =1; i <= R ; i ++) if (! visit [ i ])
   {
      visit[i]= true;
      if ( prev == -1) dfs ( v +1 ,i ,0);
      else dfs ( v +1 ,i , d + dist[r[prev]][r[i]]);
      visit[i]= false;
   }
}

int main()
{
   cin >> N >> M >> R;

   rep(i,R) {
       cin >> r[i+1];
   }
   rep(i,8) visit[i] = false;
   rep(i,N)rep(j,N) if(i != j)dist[i+1][j+1] = INF;
   //rの最短距離を求める
   rep(i,M){
      int a, b, c;
      cin >> a >> b >> c;
      if(dist[a][b] > c) dist[a][b] = dist[b][a] = c;
   }

   //200なのでワーシャルフロイドを使う
   rep(k,N) rep(i,N) rep(j,N) dist[i+1][j+1] = min(dist[i+1][j+1], dist[i+1][k+1] + dist[k+1][j+1]);

   dfs(1,-1,0);
   cout << ans << endl;
}