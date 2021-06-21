#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> hash(pow(10,9)+1);

    for(ll data : a)
    {
        if(hash[data] != false)
        {
            cout << "NO" <<endl;
            return 0;
        }
        hash[data] = true;
    }
    cout << "YES" << endl;

}