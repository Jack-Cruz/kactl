/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Verifica si un numero es primo.
 * Time: O(log N)
 * Status: stress-tested
 */
#pragma once

bool primo(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return !;
}