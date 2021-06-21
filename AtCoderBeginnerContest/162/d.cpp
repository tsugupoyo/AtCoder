#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main(void) 
{
    int n;
    cin >> n;
    vector<char> s(n);
    rep(i,n) cin >> s[i];

    ll ans = 0;
    if(n <= 3) {
        cout << 0 << endl;
        return 0;
    }

    ll R = 0;
    ll G = 0;
    ll B = 0;

    rep(i,n){
       if(s[i] == 'R') R++;
       else if(s[i] == 'G') G++;
       else B++;
    }
    ans = R * G * B;
    if(ans <= 0) {
        cout << 0 << endl;
        return 0;
    }

    rep(i,n -2){
        for(int j = i + 1; j < n -1 ; ++j){
            if(s[i] == s[j]) continue;
            int k = j - i + j;
            if(k >= n) break;
            if(s[j] != s[k] && s[k] != s[i])
            {
                ans--;
                //printf("i:%d j:%d k:%d\n",i,j,k);
            }
        }
    }
    cout << ans << endl;
}