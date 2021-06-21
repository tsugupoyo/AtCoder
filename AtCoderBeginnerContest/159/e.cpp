#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF =1001001001;

int main()
{
    //チョコレートの最大サイズ分の配列　5つくらい余裕を持っておく
    int c[10][1005];

    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    //答え(小さいものを選ぶので無限にする)
    int ans = INF;

    // 1 << h-1 = 2^(h-1)
    //線を引くor引かないの２通り
    rep(div, 1 << (h-1))
    {
         //2進数でビットが立っているところで分ける(div)
        int group =0;
        vector<int> id(h);
        rep(i,h)
        {
            id[i] = group;
            //シフトして１(線を引く)なら次からのグループをインクリする
            if(div >> i&1) group++;
        }
        //グループ数を表す為にインクリ
        group++;

        //縦グループ数分、横全て初期化
        rep(i,group)rep(j,w) c[i][j] = 0;
        //ホワイトチョコレートの箇所をインクリ
        rep(i,h)rep(j,w) {
            //１(文字コード49)と0(文字コード48)を足し引きすると1のみインクリできる
            //グループ内にあるホワイトチョコレートの数を入れる
            c[id[i]][j] += (s[i][j] -'0');
        }
        //縦に切っていく
        //答えの候補　グループの数-1が線の数
        int num = group - 1;
        vector<int> now(group);
        //指定した列を現在の数に追加する
        auto add = [&](int j)
        {
            //各グループの現在の数を格納
            rep(i,group) now[i] += c[i][j];
            //超えた場合はfalse;
            rep(i,group) if(now[i] > k) return false;           
            return true;
        };

        rep(j,w)
        {
            //列の数だけ横に増やしていき、超える時にnumをインクリする
            if(!add(j))
            {
                num++;
                //初期化
                now = vector<int>(group);
                if(!add(j))
                {
                    //1回目で失敗したら対象外にする
                    num = INF;
                    break;
                }                
            }         
        }
        //小さい方を洗濯
        ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}