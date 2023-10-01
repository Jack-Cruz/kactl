/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Suma en rangos.
 * Time: O(N)
 * Status: stress-tested
 */
#pragma once

int a[N];
int dif[N];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dif[i] = a[i] - a[i-1];
    }
    
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        dif[l] += x;
        dif[r+1] -= x;
    }
    for(int i = 1; i <= n; i++) a[i] = dif[i] + a[i-1];
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    return 0;
}