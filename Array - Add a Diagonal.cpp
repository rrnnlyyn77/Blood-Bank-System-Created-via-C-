#include<iostream>
using namespace std;

int main()
{
	int A[3][3], diaSum = 0, i, j;

	//this loop is for entering the elements to print the matrix
	cout << "\nEnter each element per row:\n";
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; ++j){
			cin >> A[i][j];
		}
	}
	//this loop is for calculating the sum of the diagonal
	for (i = 0; i < 3; ++i){
		for (j = 0; j < 3; ++j){
			if (i == j)
				diaSum += A[i][j];
		}
	}
	cout << "\nSum of diagonal is " << diaSum;
	return 0;
}
