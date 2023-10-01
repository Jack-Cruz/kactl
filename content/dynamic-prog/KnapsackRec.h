/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Knapsack recursivo.
 * Time: O(N*C)
 * Status: stress-tested
 */
#pragma once

const int N = 1e2 + 5;  // Limite de "n"
const int W = 1e4 + 5;   // Limite de capacidad
int n, C;
int v[N];
int w[N];

// Memoria O(N*C)
int dp[N][W];
bool vis[N][W];

int solve(int pos, int left){
    if(pos == n) return 0;
    if(vis[pos][left]) return dp[pos][left];

    int ans = solve(pos+1, left);
    if(left >= w[pos]) {
        ans = max(ans, v[pos] + solve(pos+1, left-w[pos]));
    }
    
    vis[pos][left] = 1;
    return dp[pos][left] = ans;
}

int main(){
    solve(0, C);
}