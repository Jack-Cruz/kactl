/**
 * Author: Racso
 * Date: 2023-09-30
 * License: CC0
 * Source: own work
 * Description: Merge Sort
 * Status: stress-tested
 */
#pragma once

vector<int> merge(vector<int> &L, vector<int> &R) {
	vector<int> res;
	int at = 0;
	for(auto x : L) {
		while(at < R.size() and R[at] < x) res.emplace_back(R[at++]);
		res.emplace_back(x);
	}
	while(at < R.size()) res.emplace_back(R[at++]);
	return res;
}

vector<int> merge_sort(vector<int> &a) {
	if(a.size() <= 1) return a;
	int n = a.size();
    int mid = n/2;
	vector<int> L(a.begin(), a.begin() + mid);
    vector<int> R(a.begin() + mid, a.end());
	
    L = merge_sort(L);
	R = merge_sort(R);
	return merge(L, R);
}