/**
 * Author: chilli, pajenegod
 * Date: 2023-09-30
 * License: CC0
 * Source: Folklore
 * Description: Estructura de datos que calcula el lowest common ancestor en un arbol (raiz en 0). Usa sparse table.
 * Time: $O(N \log N + Q)$
 * Status: stress-tested
 */
#pragma once

const int N = 1e4 + 5;
const int LOG = 14;
int n, q;
int a[N];
int h[N];
vector<int> G[N];
int ST[N][LOG];

void compute(int u, int p){
    ST[u][0] = p;
    for(int d = 1; 1 << d <= h[u]; d++){
        int y = ST[u][d-1];
        ST[u][d] = ST[y][d-1];
    }
}
void dfs(int u, int p = -1){
    compute(u, p);
    for(int v : G[u]){
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}
void go_up(int &a, int d){
    while(d){
        int k = __builtin_ctz(d);
        a = ST[a][k];
        d &= d - 1;
    }
}
int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    // h[u] >= h[v]
    go_up(u, h[u] - h[v]);  // Nos movemos h[u] - h[v] aristas hacia arriba
    if(u == v) return u;
    for(int i = 31 - __builtin_clz(h[u]); i >= 0; i--){
        if((1 << i) > h[u]) continue;
        if(ST[u][i] != ST[v][i]){
            u = ST[u][i];
            v = ST[v][i];
        }
    }
    return ST[u][0];
}

int main(){
    // input
    G[u].push_back(v);
    // preprocess
    dfs(0);
    // querys
    while(q--){
        lca(u, v);
    }
}