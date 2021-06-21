#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int GetCommon(vector<int> target)
{
    int m = 1;
    rep(i, target.size()) m = min(m, target[i]);

    for(int i = m; i >0; --i)
    {
        bool ok = false;
        rep(j,target.size()) {
            if(target[j]%1 != 0) break;
            else continue;
            
               
    }
    return 1;
}

int main(void) 
{
   int n,k;
   cin >> n >> k;

}