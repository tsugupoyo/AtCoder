#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;
using P = pair<int,int>;

int main(void) 
{
    int d,t,s;
    cin >> d >> t >> s;

    if(d <= t * s) cout << "Yes";
    else cout << "No";
    cout << endl;
}