#include <bits/stdc++.h>

using namespace std;

int main(){
 
  double chave;
  string entrada;
  int entradaInt = 0;
  
  cin >> chave;
  cin >> entrada;
  
  for(int i = 0 ; i < entrada.size(); i++){
	  if(entrada[i] == '1')
		entradaInt += 1 << (entrada.size()-i-1);
  }
  
  //cout << "Entrada" << entradaInt << endl;
  
  double d = chave * 3;
  
  int bin = (int) d;
  double d2 = d - bin;
  d2 *= 3.0;
  //int cripto = ((int)d2) ^ entrada;
  int d2int = (int)d2;
  int size = entrada.size();
  for(int i = 0 ; i < size; i++){
	  int bb = ((d2int >> (size-i-1) ) & 0x01 );
	if( entrada[i] == '0' && bb ){
		cout << '1';
	}else{
		if( entrada[i] == '1' && bb ){
			cout << '0';
		}else{
			cout << entrada[i];
		}
	}
  }
  cout << endl;
  
  
  
}