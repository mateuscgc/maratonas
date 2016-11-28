#include <bits/stdc++.h>
using namespace std;

struct CHO{
	unsigned long long c, h, o;
};

struct elements{
	unsigned long long agua, gas, diabetes;
};

int main(){
	ios_base::sync_with_stdio(false);

	CHO aux, leitura;
	elements maxi = {0,0,0}, atual;
	cin >> leitura.c >> leitura.h >> leitura.o;
	aux = leitura;

	unsigned long long att = aux.c/6;
	att = min(att, aux.h/12);
	att = min(att, aux.o/6);

	aux.c -= att*6;
	aux.h -= att*12;
	aux.o -= att*6;
	maxi.diabetes = att;

	att = min(aux.c,aux.o/2);

	aux.c -= att;
	aux.o -= att*2;

	maxi.gas = att;

	att = min(aux.o,aux.h/2);

	aux.h -= att*2;
	aux.o -= att;

	maxi.agua = att;

	if( aux.c || aux.o || aux.h){
		aux = leitura;

		att = aux.c/6;
		att = min(att, aux.h/12);
		att = min(att, aux.o/6);

		aux.c -= att*6;
		aux.h -= att*12;
		aux.o -= att*6;
		maxi.diabetes = att;

		att = min(aux.o,aux.h/2);

		aux.h -= att*2;
		aux.o -= att;

		maxi.agua = att;

		att = min(aux.c,aux.o/2);

		aux.c -= att;
		aux.o -= att*2;

		maxi.gas = att;

		if( aux.c || aux.o || aux.h ){
			aux = leitura;
			att = min(aux.c,aux.o/2);

			aux.c -= att;
			aux.o -= att*2;

			maxi.gas = att;

			att = min(aux.o,aux.h/2);

			aux.h -= att*2;
			aux.o -= att;

			maxi.agua = att;

			att = aux.c/6;
			att = min(att, aux.h/12);
			att = min(att, aux.o/6);

			aux.c -= att*6;
			aux.h -= att*12;
			aux.o -= att*6;
			maxi.diabetes = att;

			if(aux.c || aux.o || aux.h ){
				aux = leitura;
				att = min(aux.c,aux.o/2);

				aux.c -= att;
				aux.o -= att*2;

				maxi.gas = att;

				att = aux.c/6;
				att = min(att, aux.h/12);
				att = min(att, aux.o/6);

				aux.c -= att*6;
				aux.h -= att*12;
				aux.o -= att*6;
				maxi.diabetes = att;

				att = min(aux.o,aux.h/2);

				aux.h -= att*2;
				aux.o -= att;

				maxi.agua = att;

				if(aux.c || aux.o || aux.h ){
					aux = leitura;
					att = min(aux.o,aux.h/2);

					aux.h -= att*2;
					aux.o -= att;

					maxi.agua = att;

					att = min(aux.c,aux.o/2);

					aux.c -= att;
					aux.o -= att*2;

					maxi.gas = att;

					att = aux.c/6;
					att = min(att, aux.h/12);
					att = min(att, aux.o/6);

					aux.c -= att*6;
					aux.h -= att*12;
					aux.o -= att*6;
					maxi.diabetes = att;

					if(aux.c || aux.o || aux.h ){
						aux = leitura;
						att = min(aux.o,aux.h/2);

						aux.h -= att*2;
						aux.o -= att;

						maxi.agua = att;

						att = aux.c/6;
						att = min(att, aux.h/12);
						att = min(att, aux.o/6);

						aux.c -= att*6;
						aux.h -= att*12;
						aux.o -= att*6;
						maxi.diabetes = att;

						att = min(aux.c,aux.o/2);

						aux.c -= att;
						aux.o -= att*2;

						maxi.gas = att;

						if(aux.c || aux.o || aux.h ){
							cout << "Error\n";
							return 0;
						}
					}
				}
			}
		}

	}
	
	cout << maxi.agua << " " << maxi.gas << " " << maxi.diabetes << endl;

	return 0;
}