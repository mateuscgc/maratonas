#include <bits/stdc++.h>

using namespace std;

int tickets[3][3];
int tickets2[3][3];

int diagonais(){
	int total = 0;
	int max_d = min(tickets[0][0], min(tickets[1][1], tickets[2][2]));
	total += max_d;
	for(int i = 0; i < 3; i++){
		tickets[i][i] -= max_d;
	}
	// segunda diagonal
	max_d = min(tickets[0][1], min(tickets[1][2], tickets[2][0]));
	total += max_d;
	tickets[0][1] -= max_d;
	tickets[1][2] -= max_d;
	tickets[2][0] -= max_d;
	//terceira 
	max_d = min(tickets[0][2], min(tickets[1][0], tickets[2][1]));
	total += max_d;
	tickets[0][2] -= max_d;
	tickets[1][0] -= max_d;
	tickets[2][1] -= max_d;
	//quarta
	max_d = min(tickets[2][0], min(tickets[1][1], tickets[0][2]));
	total += max_d;
	tickets[2][0] -= max_d;
	tickets[1][1] -= max_d;
	tickets[0][2] -= max_d;
	//quinta
	max_d = min(tickets[2][1], min(tickets[1][2], tickets[0][0]));
	total += max_d;
	tickets[2][1] -= max_d;
	tickets[1][2] -= max_d;
	tickets[0][0] -= max_d;
	//sexta
	max_d = min(tickets[2][2], min(tickets[1][0], tickets[0][1]));
	total += max_d;
	tickets[2][2] -= max_d;
	tickets[1][0] -= max_d;
	tickets[0][1] -= max_d;	
	return total;
}

int linhas(){
	int total = 0;
	//linhas
	int max_ac = min(tickets[0][0], min(tickets[0][1], tickets[0][2]));
	int max_ab = min(tickets[1][0], min(tickets[1][1], tickets[1][2]));
	int max_co = min(tickets[2][0], min(tickets[2][1], tickets[2][2]));
	total += max_ac;
	total += max_ab;
	total += max_co;
	for(int i = 0; i < 3; i++){
		tickets[0][i] -= max_ac;
		tickets[1][i] -= max_ab;
		tickets[2][i] -= max_co;
	}
	//colunas
	int max_r0 = min(tickets[0][0], min(tickets[1][0], tickets[2][0]));
	int max_r1 = min(tickets[0][1], min(tickets[1][1], tickets[2][1]));
	int max_r2 = min(tickets[0][2], min(tickets[1][2], tickets[2][2]));
	total += max_r0;
	total += max_r1;
	total += max_r2;
	for(int i = 0; i < 3; i++){
		tickets[i][0] -= max_r0;
		tickets[i][1] -= max_r1;
		tickets[i][2] -= max_r2;
	}
	
	int max_cell = 0;
	for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				max_cell = tickets[i][j] / 3;
				tickets[i][j] -= max_cell;
				total += max_cell;
			}
	}
	return total;
}

int main(){

	int n;
	int cod;
	int rest;
	string food;
	cin >> n;
	
	int total = 0;
	
	for(int i = 0; i < n; i++){
			cin >> cod >> food;
			rest = cod % 3;
			if(food == "ACARAJE"){
				tickets[0][rest]++;
				tickets2[0][rest]++;
			}else if(food == "ABARA"){
				tickets[1][rest]++;
				tickets2[1][rest]++;
			}else if(food == "COCADA"){
				tickets[2][rest]++;
				tickets2[0][rest]++;
			}
	}
	
	total += diagonais();
	total += linhas();	
	
	
	cout << total << endl;
		
}