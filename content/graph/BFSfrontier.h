/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: Folklore
 * Description: Encuentra el camino màs corto de un nodo hacia los demas. Todas las aristas tienen el mismo peso.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

const int inf = 1e9 + 10;
const int N = 1e5 + 5;

vector<int> G[N];
bool vis[N];
int dis[N];

void bfs(int s){
    for(int i = 0; i < n; i++) dis[s] = inf;
    vector<int> front = {s};
    dis[s] = 0;
    vis[s] = 1;

    while (!front.empty()){
        vector<int> cur;
        for(int u : front){
            for(int v : G[u]){
                if(vis[v]) continue;
                dis[v] = dis[u] + 1;
                vis[v] = 1;
                cur.push_back(v);
            }
        }
        swap(cur, front);
    }
}