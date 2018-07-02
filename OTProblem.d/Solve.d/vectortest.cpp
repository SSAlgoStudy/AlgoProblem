#include <iostream>
#include <vector>

using namespace std;

int main (void){
	int cnt = 0;

	vector<vector<int> > a(10, vector<int>(20));
	for( int j = 0; j < 10; j++){
		for( int i = 0; i < 20; i++){
			a[j][i] = 1;
		}
	}

	for( int j = 0; j < 10; j++){
		for( int i = 0; i < 20; i++){
		cout << a[j][i]; 
		}
		cout << endl;
	}
 
}
