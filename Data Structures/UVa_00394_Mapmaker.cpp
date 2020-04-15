/*
 *  UVa - 394 Mapmaker  
 *  O(N) Solution.
 *
 */
#include <bits/stdc++.h>
#define INF 1000000000

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

//To store the data of each array.
struct Array {
	int B;
	int size;
	int D;
	int C[11];
	int L[11];
	int U[11];
};

vector<Array> arrays; // To store N inputted arrays
umsi umap; // To map N array_names to the respective array in 'arrays'.
	
int main(int argc, char **argv) {
	int N = 0 , R = 0 , x = 0;
	char name[20];
	scanf("%d%d" , &N , &R);
	struct Array arr = {};
  	// This loop will take O(N) time. 
	for(int i = 0 ; i < N ; i++) { // O(N)
		scanf("%s%d%d%d" , name , &(arr.B) , &(arr.size) , &(arr.D));
		for(int d = 1 ; d <= arr.D ; d++) { // O(D) = O(1)
			scanf("%d%d" , &(arr.L[d]) , &(arr.U[d]));
		}
		arr.C[arr.D] = arr.size;
		for(int d = arr.D - 1 ; d >= 1 ; d--) { // O(D) = O(1) as Max value of D = 10
			arr.C[d] = arr.C[d + 1] *(arr.U[d + 1] - arr.L[d + 1] + 1);
		} 
		arr.C[0] = arr.B;
		for(int d = 1 ; d <= arr.D ; d++) {
			arr.C[0] -= (arr.C[d] * arr.L[d]);
		}
		umap[name] = i; //O(1)
		arrays.push_back(arr); // O(1)
	}
	memset(name , 0 , sizeof name); // O(10) = O(1)
	ll address = 0;
  	// This loop will take O(N) time.
	for(int i = 0 ; i < R ; i++) { // O(R) = O(N) if R = N
		scanf("%s" , name);
		int index = umap[name]; // O(1)
		arr = arrays[index];
		address = arr.C[0];
		printf("%s[" , name);
		for(int d = 1 ; d <= arr.D ; d++) { // O(D) = O(1)
			scanf("%d" , &x);
			if(d != arr.D) printf("%d, " , x);
			else printf("%d]" , x);
			address += (x * arr.C[d]);
		}
		printf(" = %lld\n" , address);
	}
	return 0;
}

