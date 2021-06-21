#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    //数字を配列として扱うので、1減らしておく
    x--;
    y--;
    //結果用配列
    vector<int> k(n -1,0);

    //K = 1,2,3,4...nそれぞれの時点での最短距離を求める
    for(int i =0; i<n -1; i++){
        //重複は見なくていいので現在+1時点から開始する
        for(int j = i + 1; j < n;j++ ){
            //通常とxy経由のどちらか短い方
            int dis = min( abs(i-j), abs(x-i) + abs(y-j) + 1);
            k[dis -1]++;  
        } 
    }   
    rep(i,n -1) cout << k[i] << endl;
}