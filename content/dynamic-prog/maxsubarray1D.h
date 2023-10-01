/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Terminando en 'i'.
 * Time: O(N)
 * Status: stress-tested
 */
#pragma once

// memo[i]: Maxima suma de arreglo que termina en la posicion 'i'. 
// memo[i]: Toma solo a[i] o (..., a[i-1], a[i])
// memo[i]: max(a[i], a[i] + memo[i-1])
// memo[i]: a[i] + max(0, memo[i-1])
const int N = 1e5 + 5;
const int inf = 1e9;

int n;
int a[N];
int memo[N];

int solve(){
    for(int i = 0; i < n; i++){
        if(i == 0) {
            memo[i] = a[i];
        } else {
            memo[i] = max(a[i], a[i] + memo[i-1]);
        }
    }
    return *max_element(memo, memo+n);
}