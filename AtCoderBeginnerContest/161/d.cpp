#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

/* ルンルン数の作り方
1,2,3,4,5,6,7,8,9,10,11,12,21,22,23,32,33,34,43,44,45,.....98,99,100,101,110,111,112.......

1. キューから数を取り出す
2. 10で割ったあまりを求める(末尾の値が取れる)
3. あまりに-1,0,1を足したものを求める(ルンルン数は隣の-1〜1の間にある)
4. 1〜9の間に収まれば　1で取り出した数字を10倍し3で求めた値を足し　キューに入れる
5. 繰り返す
*/

int main(void) 
{
    int k;
    cin >> k;

    //ルンルン数を入れる配列
    vector<ll> a;

    //1から9まではルンルン数
    for(int i = 1; i < 10; i++) a.push_back(i);

    while(1)
    {
        if(k <= a.size())
        {
            cout << a[k-1] << endl;
            return 0;
        }
        //kを更新
        k -= a.size();
        vector<ll> old;
        swap(old, a);
        
        //順に取り出す
        for(ll x : old)
        {
            //-1, 0, 1を末尾に付け足すとルンルン数
            for(int i = -1; i <= 1; i++)
            {
                int d = x%10 + i;
                if((d < 0) || (d > 9)) continue;
                ll target = 10 * x +d;
                a.push_back(target);
            }
        }
    }
    return 0;
}