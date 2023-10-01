/**
 * Author: Luis
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: 
 * Status: stress-tested
 */
 
const int MAXPATLEN = 30 + 5;
const int MAXTEXLEN = 100000 + 5;

int z[MAXPATLEN + MAXTEXLEN + 5];

void Z(string &s){
    int n = s.size();
    int L = 0, R = 0;
    for(int i = 0; i < n; i++){
        if(i > R){
            L = R = i;
            while(R < n && s[R-L] == s[R]) R++;
            z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if(z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while(R < n && s[R - L] == s[R]) R++;
                z[i] = R - L;
                R--;
            }
        }
    }
}

int main(){
    string text, pat;
    cin >> text >> pat;
    string concat = pat + "$" + text;
    Z(concat);
    
    int cnt = 0;
    int at = pat.size() + 1;
    while(at < concat.size()){
        if(z[at] == pat.size()){
            cnt++;
            at += pat.size() - 1;
        }
        at++;
    }
    cout << cnt << "\n";
    return 0;
}