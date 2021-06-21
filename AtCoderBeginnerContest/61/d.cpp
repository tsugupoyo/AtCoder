#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const ll INF =1001001001001001001;

int main()
{
   int n, m;
   cin >> n >> m;
   int a[m], b[m];
   ll c[m], dist[n];
   rep(i,m)
   {
      cin >> a[i] >> b[i] >> c[i];
      c[i] = - c[i];
   }
   rep(i,n) dist[i] = INF;
   dist[0] = 0;
   for(int i = 0; i < n-1; i++)
   {
      for(int j =0; j < m;j++)
      {
         if(dist[a[j]-1] == INF) continue;
         //printf("d[b]: %ld  d[a]: %ld c: %ld\n", dist[b[j] -1], dist[a[j] -1], c[j]);
         if (dist[b[j] - 1] > dist[a[j] - 1] + c[j]) 
         {
            dist[b[j] - 1] = dist[a[j] - 1] + c[j];
         }
      }
   }
   ll ans = dist[n-1];

   bool negative[n];
   rep(i,n) negative[i] = false;

   rep(i,n)
   {
      rep(j,m)
      {
         if(dist[a[j] -1] == INF) continue;
         if(dist[b[j] -1] > dist[a[j] - 1] + c[j])
         {
            dist[b[j] -1] = dist[a[j] - 1] + c[j];
            negative[b[j]-1] = true;
         }
         if(negative[a[j] -1])
         {
            negative[b[j] -1] = true;
         }
         //printf("d[b]: %ld  d[a]: %ld c: %ld\n", dist[b[j] -1], dist[a[j] -1], c[j]);
      }
   }

   if(negative[n-1]) cout << "inf" << endl;
   else cout << -ans << endl;
}