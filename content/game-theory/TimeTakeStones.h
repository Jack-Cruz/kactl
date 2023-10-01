/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: h
 * Description: Juego de nim con movimientos especificos (moves).
 * Time: $O(N)$
 * Status: stress-tested
 */
#pragma once

const int N = 1e4 + 5;

vector<int> moves;
vector<int> dp(N, 0);

bool isWinning(int n){
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int x : moves){
            if(n - x >= 0 and !dp[n-x]) dp[n] = 1;
        }
    }
    return dp[n];
}