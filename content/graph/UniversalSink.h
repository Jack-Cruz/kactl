/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * Source: predates tinyKACTL
 * Description: Find universal sink interactivo.
 * Time: $O(3*N)$
 * Status: stress-tested
 */
#pragma once

int main(){
    int n;
    cin >> n;

    int j = 0;
    for(int i = 1; i < n; i++){
        cout << "? " << i+1 << " " << j+1 << "\n";
        fflush(stdout);
        bool e;
        cin >> e;
        if(e){
            continue;
        } else {
            j = i;
        }
    }
    int row = 0;
    for(int i = 0; i < n; i++){
        cout << "? " << i+1 << " " << j+1 << "\n";
        fflush(stdout);

        bool e;
        cin >> e;
        row += e;
    }
    int col = 0;
    for(int i = 0; i < n; i++){
        cout << "? " << j+1 << " " << i+1 << "\n";
        fflush(stdout);

        bool e;
        cin >> e;
        col += e;
    }
    if(row == n-1 && col == 0){
        cout << "! " << j+1 << "\n";
        fflush(stdout);
    } else {
        cout << "! " << -1 << "\n";
        fflush(stdout);
    }
    return 0;
}