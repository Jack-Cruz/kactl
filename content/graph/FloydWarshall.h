/**
 * Author: Racsó Galván
 * Date: 2023-06-30
 * License: CC0
 * Source: 
 * Description: Calcula todos los caminos más cortos en un grafo dirigido que puede tener aristas de peso negativo.
    La entrada es una matriz $n*n$ donde indica los pesos de las aristas, por otro lado, sino existe tiene valor inf.
 * Time: O(N^3)
 * Status: slightly tested
 */
#pragma once

const int N = 1e2 + 5;
const int inf = 2e9 + 10;
int n, m;
int d[N][N];

int main(){
    cin >> n >> m;
    // preprocess
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = i == j ? 0 : inf;
        }
    }
    // input
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
    }
    // Floyd warshall
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] == inf or d[k][j] == inf) continue;
                if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    // Find negative cycle
    for(int i = 0; i < n; i++){
        if(d[i][i] < 0){
            cout << "NEGATIVE CYCLE";
            return 0;
        }
    }
    return 0;
}