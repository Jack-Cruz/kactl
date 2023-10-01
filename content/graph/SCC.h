/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: Czech graph algorithms book, by Demel. (Tarjan's algorithm)
 * Description: Encuentra las componentes fuertemente conectadas. Cabe resaltar que el algoritmos encuentra los componentes ordenados topologicamente.
 * Time: O(E + V)
 * Status: stress test
 */
#pragma once

vector<int> G[2][N];
bool vis[N];
stack<int> S;
vector<int> comp;

void dfs(int u, int id){
    vis[u] = 1;
    for(int v : G[id][u]){
        if(vis[v]) continue;
        dfs(v, id);
    }
    if(id == 0) S.push(u);
    else comp.push_back(u);
}

void get_scc(){
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        dfs(i, 0);
    }
    for(int i = 0; i < n; i++) vis[i] = 0;

    vector<vector<int>> res;
    while(!S.empty()){
        int i = S.top();
        S.pop();
        comp.clear();
        if(vis[i]) continue;
        dfs(i, 1);
        res.push_back(comp);        
    }
    cout << res.size() << "\n";
    for(auto grupo : res){
        cout << grupo.size() << " ";
        for(int x : grupo) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main(){
    G[0][u].push_back(v);
    G[1][v].push_back(u);
}