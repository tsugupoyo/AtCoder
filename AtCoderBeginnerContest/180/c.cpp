#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    long n;
    cin >> n;
    set<long> ans;

    for(long i = 1; i*i <= n; i++)
    {
        if(n%i == 0) 
        {
            ans.insert(i);
            ans.insert(n/i);
        }
    }

    for(auto a : ans) cout << a << endl;
    return 0;
}