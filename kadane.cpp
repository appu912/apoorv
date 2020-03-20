#include <bits/stdc++.h>
#define MAX 1000006

typedef unsigned long long int ll;

using namespace std;

int x[MAX];

int maximum_subarray_sum(int *a , int n) {
	int current_max = a[0];
	int global_max = current_max;
	for(int i = 1 ; i < n ; ++i) {
		current_max = max(a[i] , current_max + a[i]);
		if(current_max > global_max) global_max = current_max;
	}
	return global_max;
}

int main(int arg , char **argc) {
	int TC = 0 , n = 0;
	cin >> TC;
	while(TC--) {
		cin >> n;
		for(int i = 0 ; i < n ; ++i) cin >> x[i];
		cout << maximum_subarray_sum(x , n) << endl;
	}
	return 0;
} 
