#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int n,k;
vector<ll>w,p;

bool Check(double x)
{
   //w1*p1 + w2*p2.....wk*pk / w1 + w2 +.....wk = x
   //y = Σ w * p - x * Σ w　が0以上ならxを満たす
   vector<double>y(n);
   rep(i,n) y[i] = w[i] * p[i] - x *w[i];
   sort(y.rbegin(), y.rend());
   double sum = 0;
   rep(i,k) sum += y[i];

   return sum >= 0;
}

int main()
{
   cin >> n >> k;
   w.resize(n);
   p.resize(n);
   rep(i,n) cin >> w[i] >> p[i];

   double left = 0; double right = 100;

   rep(i,100)
   {
      double mid = (left + right)/2;
      if(Check(mid)) left = mid;
      else right = mid;
   }

   printf("%.10f\n", left);
}