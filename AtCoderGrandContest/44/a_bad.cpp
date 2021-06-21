#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main()
{
   int t;
   cin >> t;
   rep(num,t)
   {
      ll n, a, b, c, d;
      cin >> n >> a >> b >> c >> d;
      ll x = 1;
      ll ans = d;
      while(1)
      {
         ll A = abs(n - (2*x));
         ll B = abs(n -(3*x));
         ll C = abs(n - (5*x));
         ll D = min(abs(n- x -1),abs(n - x + 1));
         ll target = min(A*a,B*b);
         target = min(target, C*c);
         target = min(target,D*d);
         if(target == A*a)
         {
            x = 2*x;
            ans += a;
         }
         else if(target == B*b)
         {
            x = 3*x;
            ans += b;
         }
         else if(target == C*c)
         {
            x = 5*x;
            ans += c;
         }
         else if(target == D*d)
         {
            if(n > x) x++;
            if(n < x) x--;
            ans += d;
         }
        // printf("x:%ld A:%ld B:%ld C:%ld C:%ld\n",x,A*a,B+b,C*c,D*d);
         if(n == x) break;
      }
      cout << ans << endl;
   }
}