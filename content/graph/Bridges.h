/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: Folklore
 * Description: Encuentra las aristas puente o bridges, es decir, si se elimina la arista el grafo se divide.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

int n, m;
vector<int> G[N];
bool vis[N];

int timer;
int in[N];
int low[N];
vector<pair<int, int>> bridges;

void dfs(int u, int p){
    vis[u] = 1;
    in[u] = timer++;
    low[u] = n+1;
    for(int v : G[u]){
        if(v == p) continue;
        if(vis[v] == 1){
            low[u] = min(low[u], in[v]);
        }
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > in[u]){
                if(u < v) bridges.push_back({u, v});
                else bridges.push_back({v, u});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    sort(bridges.begin(), bridges.end());
    for(auto e : bridges){
        cout << e.first << " " << e.second << "\n";
    }
    return 0;
}