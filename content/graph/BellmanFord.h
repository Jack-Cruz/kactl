/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: h
 * Description: Calcula el camino más corto de $s$ en un grafo, este puede tener aristas negativas, pero no puede tener ciclos negativos.
 * Time: $O(V*E)$
 * Status: stress-tested
 */
#pragma once

const int N = 100000 + 5;
const long long  inf = 1e18 + 10;
int n, m;
long long d[N];
vector<tuple <int, int, int>> edges;

bool Bellman(int s){
    for(int i = 0; i < n; i++) d[i] = inf * (i != s);
    int last = 0;

    for(int i = 1; i <= n; i++){
        bool relaxed = false;
        for(auto e : edges){
            int u, v, w;
            tie(u, v, w) = e;
            if(d[u] < inf and d[v] > d[u] + w){
                d[v] = d[u] + w;
                relaxed = true;
            }
        }
        if(not relaxed) break;
        last = i;
    }
    
    return last < n;
}

int main(){
    edges.emplace_back(make_tuple(u, v, w));
    Bellman(0);
    return 0;
}