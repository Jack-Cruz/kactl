/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Diferencia de prfijos
 * Time: O(N)
 * Status: stress-tested
 */
#pragma once

// S[i] = a[1] + ... + a[i]
// suma(l, r) = S[r] - S[l-1]

// F[i]: Maxima suma de arreglo que termina en pos 'i'
// F[i]: max(S[r] - S[l-1]) donde 0 <= l < r
// F[i]: S[r] + max(-S[l-1]) donde S[r] se itera y max(-S[l-1]) se procesa en marcha

// S[r]: prefix
// S[l-1]: bestprefix
const int N = 1e5 + 5;
const int inf = 1e9;

int n;
int a[N];
int memo[N];

int solve(){
    ll prefix = 0;
    ll mini = 0;
    ll ans = -inf;
    for(int i = 0; i < n; i++){
        prefix += a[i];
        if(ans < prefix - mini){
            ans = prefix - mini;
        }
        if(mini > prefix){   // bestprefix para i+1
            mini = prefix;
        }
    }
    return ans;
}