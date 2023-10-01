/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: Folklore
 * Description: Encuentra el camino màs corto de un nodo hacia los demas. Todas las aristas tienen el mismo peso..
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

const int N = 1e2 + 5;
const int inf = 1e9 + 5;

int n;
vector<int> G[N];
int dis[N];
bool vis[N];

void bfs(int s){
    for(int u = 0; u < n; u++) dis[u] = inf;
    queue<int> Q;
    dis[s] = 0;
    vis[s] = 1;
    Q.push(s);
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int v : G[u]){
            if(vis[v]) continue;
            dis[v] = dis[u] + 1;
            vis[v] = 1;
            Q.push(v);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int u, k;
        cin >> u >> k;
        u--;
        for(int j = 0; j < k; j++){
            int v;
            cin >> v;
            v--;
            G[u].push_back(v);
        }
    }
    bfs(0);
    for(int i = 0; i < n; i++){
        cout << i+1 << " " << (dis[i] == inf ? -1 : dis[i]) << "\n";
    }
    return 0;
}