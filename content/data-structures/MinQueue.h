/**
 * Author: Racso Galván
 * Date: 2023-09-29
 * License: CC0
 * Source: folklore
 * Description: Estructura de consulta en O(1) amortizado y actualización O(1).
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

struct MinStack {
    stack<pair<int, int>> S;
    void push(int x){
        S.push(make_pair(x, min(x, S.empty() ? INT_MAX : S.top().second)));
    }
    void pop(){
        if(!S.empty()){
            S.pop();
        }
    }
    bool empty(){
        return S.empty();
    }
    int top(){
        return S.empty() ? -1 : S.top().first;
    }
    int get_min(){
        return S.empty() ? -1 : S.top().second;    
    }
};

struct MinQueue{
    MinStack in, out;
    void push(int x){
        in.push(x);
    }
    void pop(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        if(!out.empty()){
            out.pop();
        }
    }
    bool empty(){
        return in.empty() and out.empty();
    }
    int front(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.empty() ? -1 : out.top();
    }
    int get_min(){
        return min(in.empty() ? INT_MAX : in.get_min(),
                out.empty() ? INT_MAX : out.get_min());
    }
} minqueue;