#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
	//cout << l << " " << r << endl;
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
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
		mergeSort(arr, 0, n - 1);
	    double time = (double(clock() - t0)/CLOCKS_PER_SEC);
	    cout << time << endl;
	    i++;
	}
	delete[] arr;		
	return 0;
}
