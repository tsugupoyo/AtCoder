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
    map<string,int> mp;
    rep(i,n) {
        string key;
        cin >> key;
        mp[key]++;
    }

    cout << mp.size() << endl;

}