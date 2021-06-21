#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    // x ^ x = 0  ➡️　奇数なら x 偶数なら 0 ......①
    // x1 ^ x2 ^ x3 ^ x4 に x2 ^ x3 ^ x4 をxorすると x1だけ取り出せる
    // a1 = x2 ^ x3 ^ x4  ↓
    // a2 = x1 ^ x3 ^ x4  ↓
    // a3 = x1 ^ x2 ^ x4  ↓
    // a4 = x1 ^ x2 ^ x3  ↓
    // この場合全て3つずつ(nは偶数なので、どのパターンでも奇数になる　①より無視できる)
    // x1 ^ x2 ^ x3 ^ x4と同値になる = sとする
    // sにそれぞれのaをxorするとそれぞれのxを取り出せる

    int s = 0;
    rep(i,n) s ^= a[i];
    rep(i,n) a[i] ^= s;
    rep(i,n) cout << a[i] << " ";
    cout << endl;
    return 0;

}
     