#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
 
     if (swapped == false)
        break;
   }
}

void inicializarArray(int arr[]){
	ifstream fin;
	fin.open("decrescente.txt", ios::in);
	
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
		bubbleSort(arr, n);
	    double time = (double(clock() - t0)/CLOCKS_PER_SEC);
	    cout << time << endl;
	    i++;
	}
	delete[] arr;		
	return 0;
}
