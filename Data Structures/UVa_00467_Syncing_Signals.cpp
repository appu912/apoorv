/*
 * UVa-00467 Syncing Signals
 * 
 */
#include <bits/stdc++.h>
#define ALL(v) v.begin() , v.end() 
#define INF 1000000005

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

bool table[95][3610]= {};
vi v;
char str[35];

void generate() {
	int x = 0 , i = 0 , k = 0;
	for(x = 10 ; x <= 90 ; x++) {
		for(i = 0 ; i <= 3600 ; i += (x + x)) {
			for(k = i ; k <= (i + (x - 6)) ; k++) {
				table[x][k] = true;
			}
		}
	}
}

int main(int argc, char **argv) {

	int time = 0 , set = 1;
	string n = ""; bool flag;
	generate();
	while(scanf(" %[^\n]" , str) != EOF) { 
		stringstream ss(str); int x = 0; 
		while(ss >> x) v.push_back(x); 
		int i , len = v.size();
		int min = *min_element(ALL(v));
		for(time = min - 4 ; time <= 3600 ; ++time) {
			flag = table[v[0]][time];
			for(i = 1 ; (i < len) && (flag) ; ++i) {
				flag &= table[v[i]][time];
			}
			if(i == len && flag) break;
		}
		if(time <= 3600)
			printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n" , set++ , time / 60 , time % 60);
		else
			printf("Set %d is unable to synch after one hour.\n" , set++);
		v.clear();
	}
	return 0;
}

