#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){
	int n = 1000000;
	ofstream fout;
	fout.open("tamanho.txt");
	fout << n;
	fout.close();	
	
	fout.open("aleatorio.txt"); //aleatorio
	
	for(int i = 1; i <= n; i++){
		int num = rand() %n;
		fout << num << "\n";
	}
	
	fout.close();
	
	fout.open("crescente.txt"); //crescente
	
	for(int i = 1; i <= n; i++){
		fout << i << " ";
	}
	
	fout.close();
	
	fout.open("decrescente.txt"); //decrescente
	
	for(int i = n; i > 0; i--){
		fout << i << "\n";
	}
	
	fout.close();
	
	return 0;
}
