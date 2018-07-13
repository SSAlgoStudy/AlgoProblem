#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include"LinkedList.h"

using namespace std;

int main()
{
	freopen("/Users/sangdolee/Desktop/Algorithm/StudyAlone/AlgorithmStudy/Text.txt", "r", stdin);
	
	List li;
	int n;
	scanf("%d\n", &n);

	while (n--) {
		int in;
		scanf("%d \n", &in);
		li.insert(in);
	}

	li.setCursor();
	int in;
	while ((in = li.next()) != -1) {
		printf("%d\n", in);
	}

	return 0;
}
