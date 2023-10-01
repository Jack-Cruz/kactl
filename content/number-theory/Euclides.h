/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Euclides para hallar mcd (gcd).
 * Time: O(log N)
 * Status: stress-tested
 */
#pragma once

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b % a, a);
}