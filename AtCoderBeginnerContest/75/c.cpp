#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

bool visit[50];
bool graph[50][50];

void dfs(int v, int n){
   if(visit[v]) return;
   visit[v] = true;

   rep(i,n){
      if(graph[v][i] == false) continue;
      if(visit[i] == true) continue;
      dfs(i,n);
   }
}

int main()
{
   int n, m;
   cin >> n >> m;

   vector<int> a(m);
   vector<int> b(m);
   rep(i,m)
   {
      cin >> a[i] >> b[i];
      a[i]--; b[i]--;
      graph[a[i]][b[i]] = true;
      graph[b[i]][a[i]] = true;
   }
   int ans = 0;
   rep(i,m){
      //切り取る
      graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
      rep(j,n) visit[j] = false;

      //dfs
      dfs(0,n);
      
      bool bridge = false;
      //辿れない　＝　橋
      rep(j,n) if(visit[j] == false) bridge = true;
      if(bridge) {
         ++ans;
      }

      //元に戻す
      graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
   }

   cout << ans << endl;
   return 0;
}