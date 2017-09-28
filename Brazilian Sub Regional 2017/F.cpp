#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin >> n >> k;

	int nums[n];
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums+n);
	reverse(nums, nums+n);
	int i;
	for(i = k; i < n && nums[i] == nums[k-1]; i++);

	cout << i << endl;
}

