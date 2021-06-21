#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main(void) 
{
    ll n,k;
    cin >> n >> k;
    ll mini = n;

    mini = mini % k;
    while(true)
    {
        ll tmp = llabs(mini - k);

        if(tmp < mini) 
        {
            mini = tmp;
            continue;
        }
        else
           break;
    }
    cout << mini << endl;
}