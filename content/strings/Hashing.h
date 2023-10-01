/**
 * Author: Luis
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: 
 * Status: stress-tested
 */
#pragma once

ll m0 = 1e9+7, m1=1e9+9; 
ll base = 37; 
const int LIM = 1e5+5; 
int n; 
char a[LIM]; 
char b[LIM]; 
ll ha [LIM][2], hb[LIM][2], pot[LIM][2]; 

struct hashingiunc {
    size_t operator()(const pair<11,11>& x) coast { return x.first;//this is good enough
    }
}; 

ll subhash(11 hashtab[LIM][2], it i, int k, int part, ll mod){ 
    return ((hashtab[i+k-1][part]-hashtab[i-l][part]*pot[k][part])%mod+mod)%mod;
}

int check(int k){ 
    if(k==0) return true; 
    unordered_set<pair<ll, ll>, hashing_func> sa(n-k+1);
    for(int i=1; i+k-1<=n; ++i){
        sa.emplace(subhash(ha, i, k, 0, m0),
                    subhash(ha, i, k, 1, m1));
    } 
    for(int i=1; i+k-1<=n; ++i){ 
        if(sa.count(make_pair(subhash(hb,i,k,0,m0), 
                            subhash(hb,i,k,1,m1)))){ 
                                return i;
        }
    } 
    return -1;
} 
void chash(char* str, ll hashtab[LIM][2]){ 
    hashtab[0][0] = hashtab[0][1] = 0;
    for(int i=1; i<=n; ++i){ 
        hashtab[i][0] = (hashtab[i-1][0]*base+(str[i-1]-'A'))%m0;
        hashtab[i][1] = (hashtab[i-1][1]*base+(str[i-1]-'A'))%m1;
    }
}
int main() { 
    scanf("%d", &n);
    scanf("%s%s", a, b);
    pot[0][0] = pot[0][1] = 1;
    
    for(int i=1;i<LIM;++i){ 
        pot[i][0] = pot[i-1][0]*base%m0;
        pot[i][1] = pot[i-1][1]*base%m1;
    }
    chash(a, ha);
    chash(b, hb);

    int lo = 0, hi = n;
    int pos = 0, len =0;
    while(lo<=hi){ 
        int mid = (lo+hi)/2; 
        int res = check(mid); 
        if(res>=0){ 
            pos = res-1;
            len = mid;
            lo = mid+1;
        } else { 
            hi = mid-1;
        }
    }
    b[pos+len]=0; 
    printf("%s\n", b+pos);
} 
