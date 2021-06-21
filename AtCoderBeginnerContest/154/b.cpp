#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{    
    string s;
    cin >> s;
    s.replace(0, s.size(),s.size(),'x');

    cout << s << endl;

}