/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Encuentra los factores primos.
 * Time: O(\sqrt{N})
 * Status: stress-tested
 */
#pragma once

void solve(){
    for(int i = 2; 1ll*i*i <= n; i++){
        if(n % i == 0){
            while(n % i == 0){
                cout << i << " ";
                n /= i;
            }
        }
    }
    if(n > 1){
        cout << n << "\n";
    }
}