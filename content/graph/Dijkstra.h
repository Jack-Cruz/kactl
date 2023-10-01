/**
 * Author: Racsó Galván
 * Date: 2023-06-30
 * License: CC0
 * Source: 
 * Description: Distancia más corta de un nodo hacia los demas. No acepta aristas negativas.
 * Time: $O(E*logE)$
 * Status: slightly tested
 */
#pragma once

int n, m;
vector<pair<int, int>> G[N];

void Dijsktra(int s){
    // O(ElogE)
    vector<ll> d(n, inf);
    d[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.emplace(make_pair(0, s));
    
    while(!Q.empty()){
        int u;
        ll dis;
        tie(dis, u) = Q.top();
        Q.pop();
        if(dis != d[u]) continue;
        
        //for(auto [v, w] : G[u]){ // Feature in C++ 17
        for(auto pair : G[u]){
            int v;
            ll w;
            tie(v, w) = pair;
               
            if(d[v] > d[u]+  w){
                d[v] = d[u] + w;
                Q.emplace(make_pair(d[v], v));
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