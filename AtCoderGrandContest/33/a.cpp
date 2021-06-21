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
   vector<string> a(h);
   rep(i,h) cin >> a[i];
   int ans = 0;
   queue<P> que;
      if(que.empty()){
         //＃を探す
         rep(i,h)rep(j,w){
            if(a[i][j] =='#')
            que.push(P(i,j));
         }
      }

   while(1)
   {
      bool end = true;
      rep(i,h){
         rep(j,w){
            if(a[i][j] =='.')
            {
               end = false;
               break;
            }
         }
         if(!end) break;
      }

      if(end) break;     
      queue<P> next;
      while(!que.empty())
      {
         P p = que.front(); que.pop();
         rep(i,4){
            int nx, ny;
            nx = p.second + dx[i];
            ny = p.first + dy[i];
            if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if(a[ny][nx] =='#')continue;
            a[ny][nx] = '#';
            next.push(P(ny,nx));
         }
      }
      ans ++;
      que = next;
   }

   cout << ans << endl;
}