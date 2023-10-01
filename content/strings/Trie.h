/**
 * Author: Rodolfo Mercado
 * License: CC0
 * Description: Estructura Trie natural.
 * Time: O(N*D)
 * Status: stress-tested
 */
#pragma once

const int N = 1e5 + 1; // Number * size of words
const int D = 26;

int nodo;
int trie[N][D];
bool fin[N];
int cnt[N];

void init(){
	nodo = 1;
	for(int i = 0; i < N; i++){
		fin[i] = 0;
        cnt[i] = 0;
		for(int j = 0; j < D; j++){
			trie[i][j] = 0; // nodo no existe
		}
	}
}

void addWord(string s){
	int cur = 0;	// nodo raiz
	for(char ch : s){
		int c = ch - 'a';
		if(!trie[cur][c]){
			trie[cur][c] = nodo++;
		}
		cur = trie[cur][c];
        cnt[cur]++;
	}
	fin[cur] = 1;
}

bool isPrefix(string s){
	int cur = 0;
	for(char ch : s){
		int c = ch - 'a';
		if(!trie[cur][c]) return 0;
		cur = trie[cur][c];
	}
	return 1;
}

bool isWord(string s){
	int cur = 0;
	for(char ch : s){
		int c = ch - 'a';
		if(!trie[cur][c]) return 0;
		cur = trie[cur][c];
	}
	return fin[cur];
}
