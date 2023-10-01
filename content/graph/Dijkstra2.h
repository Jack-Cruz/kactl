/**
 * Author: Racsó Galván
 * Date: 2023-06-30
 * License: CC0
 * Source: 
 * Description: Distancia más corta de un nodo hacia los demas. No acepta aristas negativas. Es preferible cuando E se aproxima a V^2.
 * Time: $O(V^2)$
 * Status: slightly tested
 */
#pragma once

const ll inf = 1e18 + 10;
const int N = 100;
int n, m;
vector<pair<int, int>> G[N];

void Dijsktra(int s){
    vector<bool> vis(n, false);
    vector<ll> d(n, inf);
    d[s] = 0;

    for(int step = 1; step < n; step++){
        int u = -1;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            if(u == -1 or d[u] > d[i]) u = i;
        }
        if(d[u] == inf) break;

        vis[u] = true;
        for(auto pair : G[u]){
            int v;
            ll w;
            tie(v, w) = pair;
            
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
            }        
        }
    }
    for(int i = 0; i < n; i++){
        printf("%lld%c", d[i], " \n"[i+1 == n]);
    }
}

int main(){
    // Inout
    G[u].emplace_back(make_pair(v, w));
    G[v].emplace_back(make_pair(u, w));
    // Process
    Dijsktra(0);
}