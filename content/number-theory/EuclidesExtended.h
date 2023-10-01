/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Euclides extendido ax + by = gcd(a, b)
 * Time: O(log N)
 * Status: stress-tested
 */
#pragma once

int gcdExtended(int a, int b, int *x, int *y){
    // Base case
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b/a)*x1;
    *y = x1;
    return gcd;
}

int main(){
    int x, y;
    int gcd = gcdExtended(a, b, &x, &y);
    cout << x << y << gcd;
}