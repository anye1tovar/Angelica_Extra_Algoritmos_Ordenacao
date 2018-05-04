#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
 
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            arr[j] = temp;
        }
    }
    return 0;
}
void inicializarArray(int arr[]){
	ifstream fin;
	fin.open("aleatorio.txt", ios::in);
	
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
		shellSort(arr, n);
	    double time = (double(clock() - t0)/CLOCKS_PER_SEC);
	    cout << time << endl;
	    i++;
	}
	delete[] arr;		
	return 0;
}
