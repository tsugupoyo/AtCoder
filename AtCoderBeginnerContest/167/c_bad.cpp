#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,vector<int>>;

int main(void) 
{
    int n, m, x;
    cin >> n >> m >> x;
    map<int, vector<int>, greater<int>> CA;
    ll ans = 0;
    vector<int> tb(m);
    vector<int> C(n);
   rep(i,n){
        int c;
        cin >> c;
        vector<int> tmp;
        rep(j,m){
            int aa = 0;
            cin >> aa;
            tmp.push_back(aa);
            tb[j] += aa;
        }
        CA[c] = tmp;
        C[i] = c;
        ans += c;
   }
   sort(C.rbegin(), C.rend());

   rep(k,n){
       vector<int> tmpTB = tb;
       bool ok = true;
       rep(i,m){
           tmpTB[i] - CA[C[k]][i];
           if(tmpTB[i] -CA[C[k]][i] < x) 
           {
               ok = false;
               break;
           }
       }
       if(ok) {
            tb = tmpTB;
            ans -= C[k];
           // cout << ans << endl;
       }
    }

    cout << ans  <<endl;
}