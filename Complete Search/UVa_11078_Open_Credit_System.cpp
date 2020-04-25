/*
 * UVa-11078 Open Credit System
 * 
 */
#include <bits/stdc++.h>

#define ALL(v) v.begin() , v.end()
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define pb push_back
#define mp make_pair

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

int TC = 0 , n = 0;
vi v;

int main(int argc, char **argv) {
	int x = 0;
	scanf("%d" , &TC);
	while(TC--) {
		scanf("%d" , &n);
		for(int i = 0 ; i < n ; ++i) {
			scanf("%d" , &x); v.pb(x); 
		}
	    reverse(ALL(v));
	    int mx = v[1] - v[0] , mn = v[0];
	    for(int i = 1 ; i < n ; ++i) { // Checking by Subracting minimum from the taken number v[i]
			mx = max(mx , v[i] - mn);
			mn = min(v[i] , mn);
		}
		printf("%d\n" , mx);
		v.clear();
	}
	return 0;
}

