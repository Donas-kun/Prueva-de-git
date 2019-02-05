#include <bits/stdc++.h>
using namespace std;

int diaI[8]={100,100,100,100,100,100,100,100};
int diaD[8]={100,100,100,100,100,100,100,100};
int array[8]={100,100,100,100,100,100,100,100};
int tablero[8][8]={{0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0},
				   {0,0,0,0,0,0,0,0}};
				   
bool Acabado(){
	for(int i=0;i<8;i++){
		if(array[i]==100){
			return false;
		}
	}
	return true;
}

bool Valido(int x, int num){
	diaI[x]=x-array[x];
	diaD[x]=x+array[x];
	for(int i=0;i<x;i++){
		if(array[i]==num) return false;
	}
	for(int i=0;i<x;i++){
		diaI[i]=i-array[i];
		if(diaI[i]==diaI[x]) return false;
	}
	for(int i=0;i<x;i++){
		diaD[i]=i+array[i];
		if(diaD[i]==diaD[x]) return false;
	}
	return true;
}
int contador=0;
void Resolver(int x){
	if(Acabado()){
		for(int i=0;i<8;i++){
			tablero[i][array[i]]=1;
		}
		contador++;
		cout<<"Terminado "<<contador<<" "<<endl;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout<<tablero[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<endl<<"----------------------------------------------------------"<<endl<<endl;
		for(int i=0;i<8;i++){
			tablero[i][array[i]]=0;
		}
	}else{
		for(int cont=0;cont<8;cont++){
			array[x]=cont;
			if(Valido(x,cont)){
				Resolver(x+1);
			}
		}
		array[x]=100;
	}
}
// edicion mamalona xddd
int main(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<tablero[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<endl<<"----------------------------------------------------------"<<endl<<endl;

	Resolver(0);
}

