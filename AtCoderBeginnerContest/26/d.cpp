#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const ll INF =110000000000000;
using P = pair<int,int>;
long double pi = acos(-1.0);
long double a, b, c;

//100以上ならtrue
double check(long double t)
{
   //f(t)=A*t +B* sin(C* t* π) == 100
   return a*t + b* sin(c*t*M_PI
);

}

int main()
{
   cin >> a >> b >> c;
   long double left = 0, right = 200;
   rep(i,100)
   {
      long double mid = (right + left) /2;
      if(check(mid) < 100) left = mid;
      else right = mid;
   }
   cout << std::fixed << std::setprecision(20);
   cout << left << endl;
}