/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: F[i][j]: Suma hasta fila i de la columna j-
 * Time: O(N^3)
 * Status: stress-tested
 */
#pragma once

ll F[N][N];

void solve(){
    // preprocesar
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            F[i][j] = a[i][j];
            if(i) F[i][j] += F[i-1][j];         
        }
    }
    // suma en 2D
    int ans = INT_MIN;
    for(int r1 = 0; r1 < n; r1++){
        for(int r2 = r1; r2 < n; r2++){
            int prefix = 0, mini = 0;
            for(int i = 0; i < n; i++){
                int col = F[r2][i];
                if(r1){
                    col -= F[r1-1][i];
                }
                prefix += col;
                if(ans < prefix - mini) ans = prefix - mini;
                if(mini > prefix) mini = prefix;
            }
        }
    }
    cout << ans;
}