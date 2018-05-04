#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void inicializarArray(int arr[]){
	ifstream fin;
	fin.open("crescente.txt", ios::in);
	
	if(!fin.fail()){ //verificacao de erro no arquivo
	
		int num = 0;
		int i = 0;
		while(fin >> num){
			arr[i] = num;
			i++;
		}		
		fin.close();
	}
	else {
		cout << "Error ao abrir o arquivo" << endl;
		system("pause");
	}
}
int main(int argc, char *argv[]){
	
	int n = 0; //tamanho
	ifstream fin;
	unsigned t0;
	
	fin.open("tamanho.txt", ios::in);
	if(!fin.fail()){
		fin >> n;
		fin.close();
	}
	else{
		cout << "Error ao abrir o arquivo tamanho" << endl;
		return 0;
	}
	int* arr = new int[n];
	
	int i = 1;
	while(i <= 13){
		inicializarArray(arr);
		t0 = clock();
		insertionSort(arr, n);
	    double time = (double(clock() - t0)/CLOCKS_PER_SEC);
	    cout << time << endl;
	    i++;
	}
	delete[] arr;		
	return 0;
}
