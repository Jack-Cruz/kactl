/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Longest Common Subsequence
 * Time: O(N*C)
 * Status: stress-tested
 */
#pragma once

int solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int ans = 0;
            // Cuidado con memo [-1]
            if(s[i-1] == t[j-1]) ans = max(ans, 1 + memo[i-1][j-1]);
            else  ans = max(memo[i-1][j], memo[i][j-1]);
            memo[i][j] = ans;
        }
    }
    return memo[n][m];
}
