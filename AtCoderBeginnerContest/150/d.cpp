#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 
int f(int x) {
  int res = 0;
  while (x%2 == 0) {
    x /= 2;
    res++;
  }
  return res;
}

// 難しい... https://note.com/tak_nakamori/n/nd8b56f4128ba
//2で割り切れる回数あたりが....
int main() {
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   rep(i,n) cin >> a[i];

   //X = a*(p+0.5)
   //X = a/2 *(2p + 1) →　a/2 = a'
   //X = a' * 奇数　→　a は偶数
   // a -> a'
   rep(i,n) {
      if (a[i]%2 == 1) {
      cout << 0 << endl;
      return 0;
      }
      a[i] /= 2;
   }

   // X = a' * 奇数　
   // a'を何回2(素因数)で割れるかが同じでなければならない(t)
   // 割ったものをa''
   // a' -> a''
   int t = f(a[0]);
   printf("t:%d\n",t);
   rep(i,n) {
      if (f(a[i]) != t) {
      cout << 0 << endl;
      return 0;
      }
      a[i] >>= t; // a[i] /= 2^t
   }
   //mもシフトしないと制約の最大値がわからなくなるので
      m >>= t;
      printf("m >> t:%d\n",m);

   //最小公倍数を求める
   //mを超えちゃうと条件を満たせない(m以下になる数をもとめているので)
   //全ての最小公倍数の　lを求める
   ll l = 1;
   rep(i,n) {
      l = lcm(l, a[i]);
      if (l > m) {
      cout << 0 << endl;
      return 0;
      }
   }
   printf("l:%d\n",l);
   // X' =  a'' * 奇数
   // X' =  L * 奇数  
   // X' != 2L * 奇数
   // mのうちLで割れる数がいくつあるかを求める
   m /= l;
   printf("m /= l:%d\n",m);
   // 最初に2で割った公倍数の数なので２で割らないといけない、奇数の場合は切り捨てられるので先に+1しておく
   int ans = (m+1)/2;
   cout << ans << endl;
   return 0;
}