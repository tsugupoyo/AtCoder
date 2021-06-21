#include <bits/stdc++.h>
#include <string.h>
using namespace std;
using ll=long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
   ll n, m;
   cin >> n >> m;
   vector<ll> sushi(m);
   vector<ll> child(n, 0);
   vector<ll> ans(m, -1);
   rep(i,m) cin >> sushi[i];
   ll mini = INF;
   ll maxx = 0;
   ll use = 0;
   ll index = 0;
   rep(i,m)
   {
       if(sushi[i] < mini)
       {
           for(int j = use; j < n; j++)
           {
                if(sushi[i] > child[j])
                {
                    ans[i] = j+1;
                    child[j] = sushi[i];
                    if(mini > sushi[i])
                    {
                        mini = sushi[i];
                        index = j;
                    }
                    use++;
                    
                    break;
                }
           }
       }
       else
        {
            rep(j,n)
            {
                if(sushi[i] > child[j])
                {
                    ans[i] = j+1;
                    child[j] = sushi[i];
                    if(mini > sushi[i])
                    {
                        mini = sushi[i];
                        index = j;
                    }
                    use++;
                    break;
                }
            }
       }
      // cout << ans[i] << endl;
   }
   rep(i,m) cout << ans[i] <<endl;
}