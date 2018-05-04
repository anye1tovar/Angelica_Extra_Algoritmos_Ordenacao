#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high); //ERROR ENT 4187 CRESCENTE
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
	//int* arr = new int[n];	
	int i = 1;
	while(i <= 13){
		int* arr = new int[n];
		inicializarArray(arr);
		t0 = clock();
		quickSort(arr, 0, n-1);
	    double time = (double(clock() - t0)/CLOCKS_PER_SEC);
	    cout << time << endl;
	    i++;
	    delete[] arr;
	}
	//delete[] arr;	
	return 0;
}
