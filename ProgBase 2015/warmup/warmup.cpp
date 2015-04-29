#include <bits/stdc++.h>

using namespace std;

int a[(int)1e5];
int main(){
		int n, l;
		
		cin >> n >> l;
		
		for (int i = 0; i < l; i++) {
			cin >> a[i];
		}
		int ans = 0x3f3f3f3f;
		int ini, end;
		for (int i = 0 ; i < l; i++) {
			int num = a[i]+n-1;
			ini = 0; end = l-1;
			while (ini < end) {
				int center = (ini+end)/2;
				if (a[center] > num) {
					end = center;
				}
				else ini = center+1;
			}
			
			if(a[ini] <= num) ini = l;
			
			int disp = ini-i;
			int need = n-disp;
			if(need <= l-disp) ans = min(ans, need); 
		}
		
		cout << ans << endl;
}
