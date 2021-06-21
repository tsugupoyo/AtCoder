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

    ll money = 1000;
    ll store = 0;
    bool isbuy = true;
    //買うなら全買い売るなら全売り
  
    for(int i = 0; i < n-1 ; i++)
    {
        bool ok = false;

        for(int j = i+1; j < n; j++)
        {
            if(isbuy)
            {
                if(a[i] < a[j])
                {
                    ok = true;
                    break;
                }
                else if(a[i] > a[j])
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if(a[i] > a[j])
                {
                    ok = true;
                    break;
                }
                else if(a[i] < a[j])
                {
                    ok = false;
                    break;
                }
            }
        }
        if(isbuy)
        {
            if(ok) 
            {
                store = money / a[i];
                money = money %a[i];
                isbuy = false;
              //  cout <<  "buy " << a[i] << endl;
            }
        } else {
            if(ok) 
            {
                money += store * a[i]; 
                store = 0;
                isbuy = true;
               //cout << "sell " << a[i] << endl;
            }
        }
    }

    if(!isbuy)
    {
        money += store * a[n-1]; 
    }
    if(money > 1000) cout << money << endl;
    else cout << "1000" << endl;
}
