#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int a, b, h, m;
   cin >> a >> b >> h >> m;

   double hh = (h * 30) + 0.5 * m;
   double mm = m * 6;
   double angle = hh - mm;

   double rad = (angle * M_PI /180);

   double ans = a*a + b*b - 2 * a * b *  cos(rad);
   ans = sqrt(ans);
   printf("%.20f", ans);
}