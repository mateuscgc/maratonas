#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	
	int result = 0;
	
	int max, min;
	scanf("%d", &min);
	max = min;
	for (int i = 1; i < n; i++) {
		int now;
		scanf("%d", &now);
		if (max - now > c){
			if (max > (min + c)) {
				result += max - (min + c);
			}
			max = min = now;
		} else {
			if (now > max)
				max = now;
			else if (now < min)
				min = now;
		}
	}
	if (max > (min + c)) {
		result += max - (min + c);
		
	}
	
	printf("%d\n", result);
		
	return 0;
}
