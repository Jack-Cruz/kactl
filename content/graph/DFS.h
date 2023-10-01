/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: Folklore
 * Description: 
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */

 #pragma once
 const int N = 1e5 + 5;

int n, m;
vector<int> G[N];
int dis[N];
int vis[N];
int par[N];

int timer = 1;
int in[N], out[N];

void dfs_visit(int u, int p){
    vis[u] = 1;
    par[u] = p;
    in[u] = timer++;

    for(int v : G[u]){
        if(vis[v] == 2) continue;
        else if(vis[v] == 1){
            // hay un ciclo en el grafo, no llamar al dfs_visit(v)
            continue;
        } else {
            dfs_visit(v, u);
        }
    }
    out[u] = timer++;
    vis[u] = 2;
}

void dfs(){
    for(int u = 0; u < n; u++){
        if(vis[u]) continue;
        dfs_visit(u, -1);
    }
}
