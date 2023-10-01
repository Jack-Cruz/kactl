/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Estructura de consulta y actualizacion en rangos. ST indexado en 0, pero 'pos' inicia en 1. 
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

const int N = 1e5 + 5;
const int MAX = 4*N;
ll st[MAX];

void build(int pos=1, int l=0, int r=n-1){
    if(l == r){
        st[pos] = a[l];
    }
    int mi = (l+r)/2;
    build(2*pos, l, mi);
    build(2*pos+1, mi+1, r);
    st[pos] = st[2*pos] + st[2*pos+1];
}

// x, y (query)
// l, r (subarray)
ll query(int x, int y, int pos, int l, int r){
    if(y < l or x > r) return 0;
    if(l >= x and r <= y) return st[pos];
    int mi = (l+r)/2;
    ll left = query(x, y, 2*pos, l, mi);
    ll right = query(x, y, 2*pos+1, mi+1, r);
    return left + right;
}

void update(int x, int y, int pos, int l, int r){
    if(l == r){
        st[pos] = y;
        return;
    }   
    int mi = (l+r)/2;
    if(x <= mi) update(x, y, 2*pos, l, mi);
    else update(x, y, 2*pos+1, mi+1, r);
    st[pos] = st[2*pos] + st[2*pos+1];
}