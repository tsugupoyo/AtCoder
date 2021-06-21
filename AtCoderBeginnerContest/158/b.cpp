#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
   ll n, a, b;
   cin >> n >> a >> b;
   ll ret =0;
   ll sum = a + b;
   ll cnt = n / sum;
   ll rem = n%sum;
   ret += cnt * a;
   if(rem < a) ret += rem;
   else ret += a;

   cout << ret << endl;
}