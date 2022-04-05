#include<iostream>
#include<stdlib.h>

using namespace std;

double visibilitas[5][5] = {
0,	0.071,	0.125,	0.83,	0.0625,
0.071,	0,	0.1,	0.143,	0.111,
0.125,	0.1,	0,	0.77,	0.67,
0.83,	0.143,	0.77,	0,	0.0625,
0.0625,	0.111,	0.67,	0.0625,	0
};

double feromon[5][5] = {
0.125,	0.125,	0.125,	0.125,	0.125,
0.125,	0.125,	0.125,	0.125,	0.125,
0.125,	0.125,	0.125,	0.125,	0.125,
0.125,	0.125,	0.125,	0.125,	0.125,
0.125,	0.125,	0.125,	0.125,	0.125
};

/*
double visibilitas[5][5] = {
0,	0.026,	0.012,	0.027,	0.028,
0.026,	0,	0.01,	0.037,	0.04,
0.012,	0.01,	0,	0.012,	0.012,
0.027,	0.037,	0.012,	0,	0.25,
0.028,	0.04,	0.012,	0.25,	0
};

double feromon[5][5] = {
0.021,	0.021,	0.021,	0.021,	0.021,
0.021,	0.021,	0.021,	0.021,	0.021,
0.021,	0.021,	0.021,	0.021,	0.021,
0.021,	0.021,	0.021,	0.021,	0.021,
0.021,	0.021,	0.021,	0.021,	0.021
};
*/
double probabilitas[5][5] =  {
0,	0,	0,	0,	0,
0,	0,	0,	0,	0,
0,	0,	0,	0,	0,
0,	0,	0,	0,	0,
0,	0,	0,	0,	0
};

void table_data(char *judul, double data[5][5]){
	cout<<judul<<endl;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			printf("%.3f\t",data[i][j]);
		}
		cout<<endl;
	}
}

double hitung_probabilitas(int x, int y){
	double pemb = 0, peny = 0;
	pemb = feromon[x][y]*visibilitas[x][y];
	for(int i = 0; i < 5; i++){
		peny += feromon[x][i]*visibilitas[x][i];
	}
	return pemb/peny;
}

int main(){
	table_data("tabel visibilitas", visibilitas);
	table_data("tabel feromon", feromon);
	cout<<endl;
	for(int x = 0; x < 5; x++){
		for(int y = 0; y < 5; y++){
			probabilitas[x][y] = hitung_probabilitas(x,y);
		}
	}
	table_data("tabel Probabilitas", probabilitas);
	return 0;
}
