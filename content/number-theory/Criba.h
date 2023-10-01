/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Criba para hallar numeros primos.
 * Time: O(N)
 * Status: stress-tested
 */
#pragma once

void solve(int n){
    vector<int> prime(n+1, true);
    
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            for(int j = i*2; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
}