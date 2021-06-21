#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

bool graph[100][100];
bool visit[100];
int n, m;
bool ok;

void dfs(int v, int prev)
{
   visit[v] = true;
   if(prev != -1){

   }
   rep(i,n)
   {
      if(graph[v][i] == false) continue;
      if(visit[i])
      {
         if(i != prev) ok = false;
         continue;
      }
      dfs(i,v);
   }
}

int main()
{
   cin >> n >> m;
   rep(i, m) 
   {
      int a, b;
      cin >> a >> b;
      --a;--b;
      graph[a][b] = true;
      graph[b][a] = true;
   }

   int ans =0;
   rep(i,n)
   {
      if(visit[i]) continue;
      ok = true;
      dfs(i, -1);
      if(ok) ans++;
   }
   cout << ans << endl;
}