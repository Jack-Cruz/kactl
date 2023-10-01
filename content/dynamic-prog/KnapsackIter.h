/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Knapsack iterativo.
 * Time: O(N*C)
 * Status: stress-tested
 */
#pragma once
int n, C;
int v[N];
int w[N];

// Memoria O(N)
int solve(){
    vector<int> last(C+1);
    vector<int> dp(C+1);
    for(int pos = n-1; pos >= 0; pos--){
        for(int left = 0; left <= C; left++){
            
            int ans = last[left];
            if(left >= w[pos]){
                ans = max(ans, v[pos] + last[left - w[pos]]);
            }
            dp[left] = ans;
        }
        last = dp;
    }
    return last[C];
}
int main(){
    solve();
}