/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Estructura de consulta y actualizacion en raices.
 * Time: O(\sqrt{N})
 * Status: stress-tested
 */
#pragma once

// N,Q <= 1e5
const int N = 1e5 + 5;
const int SQRT = 450;

int n, q;
int a[N];
int bsize;
ll sum[SQRT];

void build(){
    for(int i = 0; i < n; i++){
        sum[i / bsize] += a[i];
    }
}
ll query(int l, int r) {
    ll res = 0;

    while(l % bsize != 0 and l <= r){
        res += a[l];
        l += 1;
    }
    // l + bsize - 1 <= r
    while(l + bsize - 1 <= r){
        res += sum[l/bsize];
        l += bsize;
    }
    while(l <= r){
        res += a[l];
        l += 1;
    }
    return res;
}
void update(int pos, int val){
    int idx = pos / bsize;
    sum[idx] -= a[pos];
    sum[idx] += val;
    a[pos] = val;
}
