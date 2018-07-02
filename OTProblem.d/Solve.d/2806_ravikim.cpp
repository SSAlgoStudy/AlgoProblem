////////////////////////////////////////////////////////
// <Description>
// Solve SwExpert  no. 2806
// 
// <Input>
// 2 (Test Case)
// 1
// 2
//
// <Output>
// #1 1
// #2 0
//
// <Return Value>
// none
//
// <Update Info> ver Date 		Comment Owner
//				-------------------------------
//				1.0 2018/06/20	create HSKim
////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void){
/////////////////////////////////////////////////////
// <Define>
// int TestCase   input Param (roop)
// int N	 	  set BoardSize.
// int NBoard[N][N]	  N*N Array	
/////////////////////////////////////////////////////

	int TestCase = 0; 
	int N = 0;
	int NBoard[N][N] = {0,};
	cin >> TestCase;

	for( int i = 0; i < TestCase; i++){
		cin >> N;
		int NBoard[N][N] = {0,};
	}

	for(int i = 0; i <N;i++){
		for(int j = 0; j< N; j++){
		cout << NBoard[i][j] << " ";
		}
		cout << endl;
	}

}
