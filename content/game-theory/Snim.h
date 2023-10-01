/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: h
 * Description: Suma de juegos con grundy.
 * Time: $O(?)$
 * Status: stress-tested
 */
#pragma once

int grundy(int n, vector<int> moves){
    if(n == 0) return 0;
    vector<bool> used(100);
    for(int i = 0; i < moves.size(); i++){
        int x = moves[i];
        if(n - x >= 0){
            used[grundy(n - x, moves)] = 1;  
        }
    }
    int ret = 0;
    for(int i = 0; i < 1e4 + 5; i++){
        if(!used[i]) {
            ret = i;
            break;
        }
    }
    return ret;
}

void solve(int k){
    vector<int> S(k);
    for(int i = 0; i < k; i++){
        cin >> S[i];
    }
    
    int m;
    cin >> m;
    while(m--){
        int l;
        cin >> l;
        int ans;
        for(int i = 0; i < l; i++){
            int heap;
            cin >> heap;
            if(i == 0){
                ans = grundy(heap, S);
            } else {
                ans ^= grundy(heap, S);
            }
        }
        cout << (ans == 0 ? 'L' : 'W');  
    }
    cout << "\n";
}