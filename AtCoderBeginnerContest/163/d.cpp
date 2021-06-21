#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
const int MOD = 1000000007;

//mint
#pragma region 
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

ll sum(ll l, ll r) {
  return (l+r)*(r-l+1)/2;
}
 
int main() {
  int n, k;
  cin >> n >> k;
  mint ans;
  //10^100 = Bとする
  //Bは限りなく大きな数なので、選ぶ個数が異なればかぶる事はない
  for (int i = k; i <= n+1; ++i) {
    //和(S) = 0 + 1 + 2 + .....i  最小値
    //S = 1 + 2 + 3 +........i+1　一つずらした時
    //S = x + x+1 + x+2 ......x+i　x個ずらした時
    //S = n-i+1 + n-i +2.......n  最大値
    //i個選ぶうち最小の和をl 最大の和をrとする
    ll l = sum(0,i-1), r = sum(n-i+1,n);
    //0 1 2 3　から2つ選ぶ時
    //(0,1) (0,2) (0,3) (1,2) (1,3) (2,3)　の6通り考えられる
    //(0,3)と(1,2)は被るので実際は5通り
    //和のパターンは S = 2,3,4,5,6....(n-1 + n)まである
    //すなわち S = l, l +1 ,l+2, .....rに置き換えられる
    //よってパターン数は r -l + 1個となる
    ans += r-l+1;
  }
  cout << ans << endl;
  return 0;
}