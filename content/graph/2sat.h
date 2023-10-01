/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Calcula una expresión booleana a variabels a, b, c,... de un 2SAT problem, tal que la expresión es verdadera, o que la expresión no tiene solución.
 * Usage:
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 * Status: stress-tested
 */
#pragma once

struct SATSolver {
    // Assumes that nodes are 0 indexed
    int n, m;
    vector<bool> vis;
    vector<int> comp;
    vector<int> order;
    vector<int> component;
    vector<vector<int>> G, Gt;

    SATSolver(int n, int m) : n(n), m(m){
        // x_i = 2i
        // ~x_i = 2i+1
        comp.resize(2*n);
        vis.resize(2*n, false);
        G.resize(2*n, vector<int>());
        Gt.resize(2*n, vector<int>());        
    }

    void add_edge(int u, int v){
        // u or v
        G[u^1].push_back(v);
        G[v^1].push_back(u);
        Gt[v].push_back(u^1);
        Gt[u].push_back(v^1);
    }

    void dfs1(int u){
        vis[u] = 1;
        for(int v : G[u]){
            if(!vis[v]){
                dfs1(v);
            }
        }
        order.push_back(u);
    }
    void dfs2(int u){
        vis[u] = 1;
        for(int v : Gt[u]){
            if(!vis[v]){
                dfs2(v);
            }
        }
        component.push_back(u);
    }
    void get_scc(){
        for(int i = 0; i < 2*n; i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        reverse(order.begin(), order.end());
        fill(vis.begin(), vis.end(), false);

        int id = 0;
        for(int u : order){
            if(!vis[u]){
                component.clear();
                dfs2(u);
                for(int x : component){
                    comp[x] = id;
                }
                id++;
            }
        }
    }
    vector<int> solve(){
        vector<int> res(n);
        get_scc();
        for(int i = 0; i < n; i++){
            int val = 2*i;
            if(comp[val] == comp[val^1]) return vector<int>();
            if(comp[val] < comp[val^1]) res[i] = 0;
            else res[i] = 1;
        }
        return res;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    SATSolver Solver(n, m);
    for(int i = 0; i < m; i++){
        // Leemos nodos 1-indexed
        // x_i = i
        // ~x_i = -i
        int u, v;
        cin >> u >> v;
        if(u < 0){
            u = -u;
            u--;
            u = 2*u+1;
        }
        else {
            u--;
            u = 2*u;
        }
        if(v < 0){
            v = -v;
            v--;
            v = 2*v+1;
        }
        else {
            v--;
            v = 2*v;
        }
        Solver.add_edge(u, v);
    }
    vector<int> res = Solver.solve();
    if(res.empty()){
        cout << "There is no solution" << "\n";
    } else {
        cout << "One possible solution is: " << "\n";
        for(int x : res){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
