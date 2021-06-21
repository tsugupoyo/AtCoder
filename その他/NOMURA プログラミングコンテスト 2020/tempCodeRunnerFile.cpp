 // rep(i,n+1)
    // {
    //     if(i == n) 
    //     {
    //         //最後
    //         if(par * 2 != a[i])
    //         {
    //             cout << -1 << par*2 << " " << a[i] <<endl;
    //             return 0;
    //         }
    //     }
    //     else if(i == 0)
    //     {
    //         if(a[i] != 0)
    //         {
    //             cout << -1 << endl;
    //             return 0;
    //         }
    //         par = 1;
    //         ans++;
    //         continue;
    //     }
    //     else if(par * 2 <= a[i])
    //     {
    //         cout << -1 << endl;
    //         return 0;
    //     }
    //     par = 2 * par -a[i];
    //     ans += a[i];
    //     ans += par;
    //     cout << ans << " " << par << endl;
    // }