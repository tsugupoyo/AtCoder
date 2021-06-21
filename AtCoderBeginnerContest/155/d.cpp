#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF = ll(1e18)+1;

int main() {
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());

  //左を-∞　右を∞にする
  ll l = -INF, r = INF;
  
  //左右が重なったら探索終了
  while (l+1 < r) {
    //二部探索なので２で割る
    ll x = (l+r)/2;

    bool ok = [&]{
      ll tot = 0;

      rep(i,n) {
        if (a[i] < 0) {
          //負の時はrがOK側
          int l = -1, r = n;
          //入力した配列内でも2分探索
          while (l+1<r) {
            int c = (l+r)/2;
            //OKの場合はOK側を更新
            if (a[c]*a[i] < x) r = c; else l = c;
          }
          tot += n-r;
        } else {
          //正の時はlがOK側
          int l = -1, r = n;
          while (l+1<r) {
            int c = (l+r)/2;
            //OKの場合はOK側を更新
            if (a[c]*a[i] < x) l = c; else r = c;
          }
          //探索した場所の合計を入れる　l+1 でもよい　
          tot += r;
        }
        //自分自身を余計に計算しているので減らしておく
        if (a[i]*a[i] < x) tot--;
      }
      tot /= 2;
      return tot < k;
    }();

    //範囲内であれば左(ans候補)範囲外であれば右(ans候補ではなく右側を更新する)
    if (ok) l = x; else r = x;
  }
  cout << l << endl;
  return 0;
}
