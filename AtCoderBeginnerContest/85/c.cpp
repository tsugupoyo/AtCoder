#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int n, y;
   cin >> n >> y;

   if(n * 10000 < y){
      printf("%d %d %d\n",-1,-1,-1);
      return 0;
   }

   rep(i,n + 1) for(int j = 0; j <= n -i; j++){
     int sum = y - i* 10000 - j * 5000;
     int rem = n - i - j;
     sum -= rem * 1000;
     if(sum == 0){
         printf("%d %d %d\n",i,j,rem);
         return 0;
     }
   }
   printf("%d %d %d\n",-1,-1,-1);
   return 0;

}