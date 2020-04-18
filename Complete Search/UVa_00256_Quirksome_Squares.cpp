/*
 * UVa-00256 Quirksome Squares
 * 
 */
#include <bits/stdc++.h>
#define ALL(v) v.begin() , v.end() 
#define TRv(v) for(auto it = v.begin() ; it != v.end() ; ++it)
#define INF 1000000005
#define PB push_back
#define SIZE 4

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

vector<vs> v(SIZE , vs());
int N = 0;

void generate() {
	v[0].PB("00"); v[0].PB("01"); // N = 2
	for(int i = 4 ; i * i < 100 ; ++i) // 6 times
		if(i * i == (((i * i / 10) + (i * i % 10)) * ((i * i / 10) + (i * i % 10)))) 
			v[0].PB(to_string(i * i));
	v[1].PB("0000"); v[1].PB("0001"); // N = 4
	for(int i = 11 ; i * i < 10000 ; ++i) { // 81 times
		if(i * i == (((i * i / 100) + (i * i % 100)) * ((i * i / 100) + (i * i % 100)))) {
			if((int)(floor(log10(i * i)) + 1) == 3) { string s = "0"; s.append(to_string(i * i)); v[1].PB(s); }
			else v[1].PB(to_string(i * i));
		}
	}
	v[2].PB("000000"); v[2].PB("000001"); // N = 6
	for(int i = 32 ; i * i < 1000000 ; ++i) { // nearly 1000 times
		if(i * i == (((i * i / 1000) + (i * i % 1000)) * ((i * i / 1000) + (i * i % 1000)))) {
			if((int)(floor(log10(i * i)) + 1) == 4) { string s = "00"; s.append(to_string(i * i)); v[2].PB(s); }
			else if((int)(floor(log10(i * i)) + 1) == 5) { string s = "0"; s.append(to_string(i * i)); v[2].PB(s); }
			else v[2].PB(to_string(i * i));
		}
	}
	v[3].PB("00000000"); v[3].PB("00000001"); // N = 8
	for(int i = 101 ; i * i < 100000000 ; ++i) { // nearly 10000 times
		if(i * i == (((i * i / 10000) + (i * i % 10000)) * ((i * i / 10000) + (i * i % 10000)))) {
			if((int)(floor(log10(i * i)) + 1) == 5) { string s = "000"; s.append(to_string(i * i)); v[3].PB(s); }
			else if((int)(floor(log10(i * i)) + 1) == 6) { string s = "00"; s.append(to_string(i * i)); v[3].PB(s); }
			else if((int)(floor(log10(i * i)) + 1) == 7) { string s = "0"; s.append(to_string(i * i)); v[3].PB(s); }
			else v[3].PB(to_string(i * i));
		}
	}
}

int main(int argc, char **argv) {
	generate();
	while(scanf("%d" , &N) != EOF) {
		if(N == 2) {
			TRv(v[0]) { printf("%s\n" , (*it).c_str()); }
		}
		else if(N == 4) {
			TRv(v[1]) { printf("%s\n" , (*it).c_str()); }
		}
		else if(N == 6) {
			TRv(v[2]) { printf("%s\n" , (*it).c_str()); }
		}
		else {
			TRv(v[3]) { printf("%s\n" , (*it).c_str()); }
		}
	}
	return 0;
}

