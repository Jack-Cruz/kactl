/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: S[i][j]: Suma hasta fila i, columna j.
 * Time: O(N)
 * Status: stress-tested
 */
#pragma once

ll S[N][N];

void solve(){
    // preprocesar
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int suma = a[i][j];
            if(i) suma += S[i-1][j];
            if(j) suma += S[i][j-1];
            if(i and j) suma -= S[i-1][j-1];
            S[i][j] = suma;
        }
    }
    // suma en 2D
    int ans = INT_MIN;
    for(int r1 = 0; r1 < n; r1++){
        for(int r2 = r1; r2 < n; r2++){
            for(int c1 = 0; c1 < n; c1++){
                for(int c2 = c1; c2 < n; c2++){
                    int suma = S[r2][c2];
                    if(r1) suma -= S[r1-1][c2]; 
                    if(c1) suma -= S[r2][c1-1];
                    if(r1 and c1) suma += S[r1-1][c1-1];
                    ans = max(ans, suma);
                }
            }
        }
    }
    cout << ans;
}