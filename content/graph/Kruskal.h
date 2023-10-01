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

const int N = 200000 + 5;
int n, m;
int comp[N];
vector<int> nodes[N];

void init() {
	for(int i = 1; i <= n; i++) {
		nodes[i].push_back(i);
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

int get_component(int x) {
	return comp[x];
}

int main() {
    cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	for(int i = 0; i < m; i++) {
		int u, v, w;
        cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}
	sort(edges.begin(), edges.end());
	init();
	int ans = 0;
	vector<pair<int, int>> mst;
	for(auto e : edges) {
		int w, u, v;
		tie(w, u, v) = e;
		if(get_component(u) != get_component(v)) {
			ans += w;
			mst.emplace_back(u, v);
			join(u, v);
		}
	}
    cout << ans << "\n";
    cout << n-1 << "\n";
	for(auto e : mst) {
		cout << e.first << " " << e.second << "\n";
	}
	return 0;
}