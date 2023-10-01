/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Estructura de prefijo que permite modificaciones y consulta en O(log N).
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

const int N = 1000000 + 5;
ll ft[N];

void update(int pos, int val){
    while(pos <= MAXI){
        ft[pos] += val;
        pos += (pos & -pos);
    }
}

ll query(int pos){
    ll res = 0;
    while(pos > 0){
        res += ft[pos];
        pos -= (pos & -pos);
    }
    return res;
}

