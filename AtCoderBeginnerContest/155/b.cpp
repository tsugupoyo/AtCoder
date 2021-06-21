#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    //偶数抜き出す
    vector<int> even;
    even.reserve(n);
    rep(i,n) if(a[i]%2 == 0) even.push_back(a[i]);

    //3または5で割り切れるかを見る
    for(int data : even)
    {
        if(data%3 != 0 && data%5 != 0)
        {
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;

}