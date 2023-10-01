/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * Source: predates tinyKACTL
 * Description: Encuentra el número de caminos con longitud l, para ello usa binary exponentation.
 * Time: $O(N*N*logN)$
 * Status: stress-tested
 */
#pragma once

const int MOD = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi multiply(vvi a, vvi b, int n){
    vvi c (n, vi(n));
    // multiply
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j]) % MOD; 
            }
        }
    }
    return c;
}

vvi exp_power(vvi a, int n, int l){
    vvi result (n, vi(n));
    // identity matrix
    for(int i = 0; i < n; i++)  result[i][i] = 1;

    while(l > 0){
        if(l & 1){
            result = multiply(result, a, n);
        }
        l /= 2;
        a = multiply(a, a, n);
    }
    return result;
}

int main(){
    int n, l;
    cin >> n >> l;
    vvi a(n, vi(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vvi al = exp_power(a, n, l);
    // cout << "result matrix \n";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << al[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << al[0][n-1];
    return 0;
}