#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   int k, s;
   cin >> k >> s;
   int ans = 0;
   rep(x,k+1)
      rep(y,k+1)
      {
         int z = s-x-y;
         if(z < 0 || z > k ) continue;
         else ++ans;
      }
   
   cout << ans << endl;

}