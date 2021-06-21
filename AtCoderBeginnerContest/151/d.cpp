#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using P = pair<int,int>;

const int INF =1001001001;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0 ,1};

int main()
{    
   int h,w;
   cin >> h >> w;
   char s[h][w];
   rep(i,h) rep(j,w) cin >> s[i][j];
   int ans =0;
   //BFS(幅優先探索)を使う

   //全ての位置をスタートにする
   rep(i,h) rep(j,w){
      //#だったら飛ばす
      if(s[i][j] == '#') continue;
      //キューと記録用配列を用意
      queue<P> q;
      //全てINFで埋めた記憶用配列
      vector<vector<int>> dist(h,vector<int>(w, INF));
      //INFでなければ更新し、キューに入れる関数
      auto update = [&](int i, int j, int x){
         if(dist[i][j] != INF) return;
         dist[i][j] = x;
         q.emplace(P(i,j));
      };
      //一つ目のキューに今位置を初期位置として入れる
      update(i,j,0);
      //全て移動するとキューが空になる
      while(!q.empty()){
         //キューから取り出す
         int i = q.front().first;
         int j = q.front().second; q.pop();

         //上下左右を順に見る
         rep(dir,4){
            int ni = i + di[dir];
            int nj = j + dj[dir];

            //はみ出た場合を考慮
            if(ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            //壁検出
            if(s[ni][nj] == '#') continue;
            //突破したら1足して(移動して)更新
            update(ni,nj,dist[i][j] + 1);
         }
      }

      //最後に今回の位置スタートで一番遠かった位置==移動距離の最大なので今までの最大値と比較する
      rep(i,h) rep(j,w){
         if(dist[i][j] == INF)continue;
         ans = max(ans, dist[i][j]);
      }
   }

   cout << ans << endl;
   return 0;
}