/**
 * Author: Racsó Galván
 * Date: 2023-09-30
 * License: CC0
 * Source: folklore
 * Description: Longest Increasing Subsequence
 * Time: O(N*logN)
 * Status: stress-tested
 */
#pragma once
const int N = 100;
int n;
int a[N];
vector<int> vec;

void add(int left, int right, int val){
    if(left == right){
        if(vec[left] >= val){
            vec[left] = val;
        } else {
            vec.emplace_back(val);
        }
        return;
    }
    int mid = (right - left)/2;

    if(val <= vec[mid]){
        add(left, mid, val);
    } else {
        add(mid+1, right, val);
    }
}
void imprime_vector(){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vec.push_back(a[0]);    // inicial

    for(int i = 1; i < n; i++){
        add(0, vec.size()-1, a[i]);
        imprime_vector();
    }

    cout << vec.size() << "\n";
    return 0;
}