#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const ll INF =1001001001001001001;

ll r, b, x, y;

bool Check(ll k)
{
   ll remr = (r-k)/(x-1);
   ll remb = (b-k)/(y-1);
   if(r-k < 0 || b-k < 0) return false;
   if(remr + remb >= k) return true;
   else return false;
}

int main()
{
   cin >> r >> b >> x >> y;
   ll left = 0, right = INF;
   while(right -left > 1)
   {
      ll mid = (left + right) /2;
      if(Check(mid)) left = mid;
      else right = mid;
   }
   cout << left << endl;
}