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
    vector<int> x(n),y(n);

    rep(i,n)
    {
        cin >> x[i] >> y[i];
    }

    rep(i,n)
    {
        for(int j = i+1; j<n; j++)
        {
             for(int k = j+1; k<n; k++)
             {
                 if((y[k] - y[j]) * (x[k] -x[i]) == (y[k] - y[i]) * (x[k] -x[j]))
                 {
                     cout << "Yes" << endl;
                     //cout << i << " " << j << " " << k << endl;
                     return 0;
                 }
             }
        }
    }
     cout << "No" << endl;
     return 0;
}