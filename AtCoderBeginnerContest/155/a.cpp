#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    if((a == b) && (a == c) && (b == c)
    || (a != b) && (a != c) && (b !=c))
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
    }
        
}