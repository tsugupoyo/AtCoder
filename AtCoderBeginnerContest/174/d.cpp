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
    string c;
    cin >> c;

    ll ans = 0;
    int index = 0;
    rep(i,n){
        if(c[n-i-1] == 'R') 
        {
            for(int j = index; j < n-i-1; j++)
            {
                if(c[j] == 'W')
                {
                    c[j] = 'R';
                    c[n-i-1] = 'W';
                    ans++;
                    break;
                }
                index++;
            }
            if(c[n-i-1] == 'R') break;
            continue;
        }
    }

   cout << ans << endl;
}