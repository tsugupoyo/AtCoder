#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   ll n, k;
   cin >> n >> k;
   vector<ll> a(n);
   vector<bool> visit(n);
   rep(i,n) {
       ll tmp;
       cin >> tmp;
       a[i] = tmp - 1;
   }

   ll pos = 0;
   ll ans = 0;
    ll cntA = 0;
   rep(i,n){
       if(visit[pos]) 
       {
           break;
       }
       visit[pos] = true;
       ans = a[pos];
       pos = ans;
       cntA++;
      //cout << ans + 1 << endl;
   }
   if(cntA == n) 
   {
       cout << ans + 1<< endl;
       return 0;
   }
   ll cntb = 0;
   vector<ll> ansT;
    rep(i,n) visit[i] = false;
    rep(i,n){
        if(visit[pos]) 
       {
           break;
       }
       visit[pos] = true;
       ans = a[pos];
       pos = ans;
       ansT.push_back(pos);
       cntb++;
    }
    k = k - (cntA - cntb)-1;
    int mo = k%cntb;
    //reverse(ansT.begin(), ansT.end());
    // cout << mo << " " << n << " "<< cntA << "" << endl;
    // rep(i, cntb) cout << ansT[i] + 1;
    // cout << endl;
    cout << ansT[mo] + 1<< endl;
}