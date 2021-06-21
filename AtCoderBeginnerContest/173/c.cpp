#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
   int h, w, k;
   cin >> h >> w >> k;

   vector<string> c(h);
   rep(i,h) cin >> c[i];

   int ans = 0;
   rep(hi, 1 << h)
   {
        vector<string> target = c;
        rep(hj, h){
            if(hi >> hj & 1)
            {
                //選択
                target[hj] ="------";
            }
        }
        rep(wi, 1 << w)
        {
            vector<string>target2 = target;
            int sum = 0;
            rep(wj, w)
            {
                if(wi >> wj & 1)
                {
                    rep(x,h) target2[x][wj] = '-';
                }
            }
             rep(ii, h) rep(jj, w) 
            {
            if(target2[ii][jj] == '#') sum++;
            }
            if(sum == k) ans ++;
        }
    }
    cout << ans << endl;
}