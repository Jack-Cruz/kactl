/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Query en un array estático.
 * Time: O(N)
 * Status: stress-tested
 */
#pragma once

int main(){
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] += (i-1 >= 0 ? a[i-1] : 0);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        r--;
        ll suma = a[r] - (l-1 >= 0 ? a[l-1] : 0);
        cout << suma << "\n";
    }
    return 0;
}