/*
 * UVa-00471 Magic Numbers
 * 
 */
#include <bits/stdc++.h>

#define ALL(v) v.begin() , v.end()
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define pb push_back
#define mp make_pair
#define nDigits(N) ((int)floor(log10(N) + 1))
#define uniqueDigits(N) 
#define isEven(N) ((!(N & 1)) ? 1 : 0)

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

typedef pair<int , int> ii;
typedef pair<int , ii> iii;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef unordered_map<string , int> umsi;
typedef unordered_map<int , int> umii;

int TC = 0;
ll N = 0;

int main() {
    scanf("%d" , &TC);
    ll temp1 , temp2;
    int used = 0;
    while(TC--) {
        scanf("%lld" , &N);
        for(ll s2 = 1ll ; s2 <= 9876543210ll / N ; ++s2) {
            temp2 = s2; used = 0; while(temp2 != 0) { used |= (1 << (temp2 % 10)); temp2 /= 10; }
            if(__builtin_popcount(used) == nDigits(s2)) {
                ll s1 = s2 * N;
                temp1 = s1; used = 0; while(temp1 != 0) { used |= (1 << (temp1 % 10)); temp1 /= 10; }
                if(__builtin_popcount(used) == nDigits(s1)) printf("%lld / %lld = %lld\n" , s1 , s2 , N);
            }
            else continue;
        }
        if(TC != 0) printf("\n");
    }
	return 0;
}
