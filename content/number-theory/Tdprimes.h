/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Encuentra los factores primos.
 * Time: O(log N)
 * Status: stress-tested
 */
#pragma once

const int N = 100000000 + 1;

vector<int> primes;
bitset<N> composite;

int main() {
	for(int i = 2; i < N; i++) {
		if(not composite[i]) primes.emplace_back(i);
		for(int p : primes) {
			if(i * p >= N) break;
			composite[i * p] = true;
			if(i % p == 0) break;
		}
	}
	for(int i = 0; i < primes.size(); i += 100) printf("%d\n", primes[i]);
	return 0;
}