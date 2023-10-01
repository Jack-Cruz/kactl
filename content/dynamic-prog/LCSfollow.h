/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Follow the path.
 * Time: O(N^2)
 * Status: stress-tested
 */
#pragma once

const int N = 100, M = 100, inf = 1e9;

int memo[N][N];
int choice[N][N];

string solve(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // Cuidado con memo [-1]
            if(s[i-1] == t[j-1]) {
                memo[i][j] = 1 + memo[i-1][j-1];
                choice[i][j] = 0;  
            }
            else {
                if(memo[i-1][j] > memo[i][j-1]){
                    memo[i][j] = memo[i-1][j];
                    choice[i][j] = 1;
                } else {
                    memo[i][j] = memo[i][j-1];
                    choice[i][j] = 2;
                }
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while(i > 0 and j > 0){
        if(choice[i][j] == 0){
            ans.push_back(s[i-1]);
            i -= 1;
            j -= 1;
        } else if(choice[i][j] == 1){
            i -= 1;
        } else {
            j -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}