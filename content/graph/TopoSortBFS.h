/**
 * Author: Unknown
 * Date: 2023-09-30
 * Source: predates tinyKACTL
 * Description: Ordena los vertices de manera que las arista van de izquierda a derecha. Si existen ciclos retorna un vector vacio.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

int n, m;
int in[N];
vector<int> G[N];

vector<int> toposort(){
    queue<int> Q;
    vector<int> order;

    for(int u = 0; u < n; u++){
        if(in[u] == 0){
            Q.push(u);
        }
    }
    while(!Q.empty()){
        int u = Q.front(); 
        Q.pop();
        order.push_back(u);
        for(int v : G[u]){
            in[v]--;
            if(in[v] == 0){
                Q.push(v);
            }
        }
    }

    // deteccion de un ciclo
    return order.size() < n ? vector<int>() : order;
}

int main(){
    // input
    in[v]++;
}