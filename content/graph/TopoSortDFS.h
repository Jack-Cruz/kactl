/**
 * Author: Unknown
 * Date: 2023-09-30
 * Source: predates tinyKACTL
 * Description: Ordena los vertices de manera que las arista van de izquierda a derecha. Si existen ciclos retorna un vector vacio.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

bool cycle;
int vis[N];
vector<int> G[N];
vector<int> order;

void DFS(int u){
    vis[u] = 1;
    // in[u] = timer++;
    for(int v : G[u]){
        if(vis[v] == 2) continue;
        if(vis[v] == 1) {
            cycle = true;
            continue;
        }
        DFS(v);
    }

    vis[u] = 2;
    order.emplace_back(u);
}

vector<int> topological_sort(){
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        DFS(i);
    }
    if(cycle) order.clear();
    reverse(order.begin(), order.end());
    return order;
}