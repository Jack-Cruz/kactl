/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: Folklore
 * Description: Encuentra los nodos o cutpoints, es decir, si se elimina el nodo el grafo se divide.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

const int N = 1e5;

int n, m;
vector<int> G[N];
bool vis[N];

int timer;
int in[N];
int low[N];

void is_cutpoint(int u){
    cout << u << "\n";
}

void dfs(int u, int p = -1){
    vis[u] = 1;
    in[u] = timer++;
    low[u] = n + 1;
    int children = 0;

    for(int v : G[u]){
        if(v == p) continue; // procesado or ignorar el padre
                                            // (u, v) -> (v, u)
        if(vis[v] == 1){    
            // si es backedge, aporta a low[u]
            low[u] = min(low[u], in[v]);
        }
        else{
            // aun no procesado (tree edge)
            // verificar si u es cut point
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            // Verificar para nodos diferentes a la raiz
            if(p != -1 and low[v] >= in[u]){
                is_cutpoint(u);
            } 
            children++;
        }
    }

    // Si 'u' es raiz, es articulacion si tiene 2 hijos a mas
    if(p == -1 and children > 1) is_cutpoint(u);
}

void dfs_visit(){
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            dfs(i, -1);
        }
    }
}

int main(){
    // input
    G[u].push_back(v);
    G[v].push_back(u);

    // process
    dfs_visit();
}