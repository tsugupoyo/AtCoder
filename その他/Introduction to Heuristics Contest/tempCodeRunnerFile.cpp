 rep(i,m)
   {
      int day = d[i] -1;
      int type = q[i];
      anslist[day] -= s[day][t[day]];
      anslist[day] -= s[day][type];
      anslist[day] -= c[day] * (day +1 - last[t[day]]);
      anslist[day] += c[day] * (day +1 - last[type]);
      swap(last[t[day]],last[type]);
   }