/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Find the path.
 * Time: O(N^2)
 * Status: stress-tested
 */
#pragma once

const int N = 100, M = 100, inf = 1e9;
int memo[N][N];

string solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int cur = 0;
            // Cuidado con memo [-1]
            if(s[i-1] == t[j-1]) cur = max(cur, 1 + memo[i-1][j-1]);
            else  cur = max(memo[i-1][j], memo[i][j-1]);
            
            memo[i][j] = cur;
        }
    }

    string ans = "";
    int i = n, j = m;
    while(i > 0 and j > 0){
        if(s[i-1] == t[j-1]){
            ans.push_back(s[i-1]);
            i -= 1;
            j -= 1;
        } else {
            if(memo[i-1][j] > memo[i][j-1]){
                i -= 1;
            } else {
                j -= 1;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
