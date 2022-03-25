#include <bits/stdc++.h>
using namespace std;

void perform_test() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	// separate the elements from odd indices and even indices (1-based)
	vector<long long> odd, even;
	for(int i = 0; i < n; i++) {
		if((i + 1) & 1) {
			odd.push_back(abs(vec[i]));
		} else {
			even.push_back(abs(vec[i]));
		}
	}
	// calculate the sum of the elements in each sequence (1-based indexing)
	// let s0 = a[1] + a[3] + a[5] + ... + a[n], where n is odd
	long long s0 = 0, s1 = 0;
	long long a = LLONG_MAX, b = LLONG_MIN;
	for(auto& x : odd) {
		s0 += x;
		a = min(a, x);
	}
	// let s1 = -a[2] - a[4] - a[6] - ... - a[m], where m is even
	for(auto& x : even) {
		s1 += x;
		b = max(b, x);
	}
	// initial sum = s0 - s1
	// initial sum = (a[1] + a[3] + a[5] + ... + a[n]) - (-a[2] - a[4] - a[6] - ... - a[m])
	// initial sum = a[1] + a[3] + a[5] + ... + a[n] - a[2] + a[4] + a[6] + ... + a[m]
	
	// since we can only do the operation at most once, it's either we try swapping the
	// smallest value in the odd sequence from the largest value in the even sequence
	// by doing so,
	
	// let a = element in odd sequence, b = element in the even sequence
	// s0 = s0 - a + b
	// s1 = s1 - b + a
	
	// initial sum = s0 + s1
	// initial sum = (s0 - a + b) - (s1 - b + a)
	// initial sum = s0 - a + b - s1 + b - a
	// initial sum = s0 - s1 + 2b - 2a
	// initial sum = s0 - s1 + 2(b - a)
	long long s = s0 - s1;
	cout << max(s, s + 2 * (b - a)) << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}
