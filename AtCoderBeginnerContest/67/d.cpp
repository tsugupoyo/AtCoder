#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int dist[2][100000];
bool visit[2][100000];
vector<int> graph[100000];

void dfs(int x, int n, int i){
   visit[i][x] = true;
   
  // printf("dist:%d\n",dist[x]);
   for(auto g :graph[x]){
      if(visit[i][g]) continue;
      dist[i][g] = dist[i][x] + 1;
      dfs(g,n,i);
   }
}

int main()
{   
   int n;
   cin >> n;

   // 5-7-4-1-2 
   //       L3-6
   // 1-4-2-3

   rep(i,n-1){
      int a,b;
      cin >> a >> b;
      --a; --b;
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
   }

   //それぞれからの距離を求める
   //フェネックA
   dfs(0,n,0);
   //スヌケ
   dfs(n-1,n,1);

   int A = 0;
   int B = 0;

   rep(i,n){
      if(dist[0][i] <= dist[1][i]) ++A;
      else ++B;
   }
  // rep(i,n) printf("A:%d B:%d\n",distA[i], distB[i]);

   if(A > B) cout << "Fennec" << endl;
   else cout << "Snuke" << endl;
   return 0;
}