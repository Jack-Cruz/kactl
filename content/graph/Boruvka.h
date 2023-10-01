/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: 
 * Description: Calcula el árbol de expansión minima (MST), usa la optimización en rango (DSU).
 * Time: O(E*logE)
 * Status: slightly tested
 */
#pragma once

int n, m;
int comp[N];
vector<pair<int, int>> G[N];
vector<int> nodes[N];

void init() {
	for(int i = 1; i <= n; i++) {
		nodes[i].emplace_back(i);
		comp[i] = i;
	}
}

void join(int u, int v) {
	u = comp[u];
	v = comp[v];
	if(nodes[u].size() > nodes[v].size()) swap(u, v);
	while(!nodes[u].empty()) {
		int x = nodes[u].back();
		nodes[u].pop_back();
		nodes[v].emplace_back(x);
		comp[x] = v;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	init();
	int ans = 0;
	vector<pair<int, int>> mst;
	int comps = n;
	while(comps > 1) {
		vector<tuple<int, int, int>> L;
		for(int i = 1; i <= n; i++) {
			if(nodes[i].empty()) continue;
			int best_cost = INT_MAX;
			tuple<int, int, int> light_edge;
			for(auto u : nodes[i]) {
				for(auto e : G[u]) {
					int v, w;
					tie(v, w) = e;
					if(comp[u] == comp[v]) continue;
					if(w < best_cost) {
						best_cost = w;
						light_edge = make_tuple(u, v, w);
					}
				}
			}
			L.emplace_back(light_edge);
		}
		for(auto e : L) {
			int u, v, w;
			tie(u, v, w) = e;
			if(comp[u] == comp[v]) continue;
			comps -= 1;
			join(u, v);
			ans += w;
			mst.emplace_back(u, v);
		}
	}
	printf("%d\n", ans);
	printf("%d\n", n - 1);
	for(auto e : mst) {
		printf("%d %d\n", e.first, e.second);
	}
	return 0;
}