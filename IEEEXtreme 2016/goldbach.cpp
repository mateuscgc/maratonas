#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
bitset<10000010> bs;
long long _sieve_size;


void sieve(long long upeperbound) {
	_sieve_size = upeperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;

	for(long long i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for(long long j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

bool is_prime(long long n) {
	if(n <= _sieve_size) return bs[n];
	for(int i = 0; i < primes.size(); i++)
		if(n % primes[i] == 0) return false;
	return true;
}

int main() {
	sieve(10000000);

	long long n;
	cin >> n;

	
	for(int i = 0; i < primes.size(); i++) {
		// cout << primes[i] << endl;
		long long aux = n - primes[i];
		for(int j = i+1; j < primes.size(); j++) {
			long long aux2 = aux - primes[j];
			if(is_prime(aux2)) {
				cout << primes[i] << " " << primes[j] << " " << aux2 << endl;
				return 0;
			}
		}
	}
}