/////////////////////////////////////////////////////////////////////////////////////
// <<HomeWork - Make queue >>
//
// <Description>	Make queue DataStructure
// <Function List> 
//
//
// <Issue>			ver			issue
// 					----------------------------------------------------------------
// 					1.0.0		Make queue's Basic Design Foundation.
//					1.0.1		Optimization 
//
//
//
// <History Info> 	Ver 		Date			Comment				Owner			
//					----------------------------------------------------------------
//					1.0.0		18.07.27		Create				RaviKim
//					1.0.1		18.07.27		Optimize			RaviKim
//
//
/////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char command[10];	// CommandLine Input Array

void PrintCommand();
void SwitchCommand(int Command);
void Push(int inputNum);
void Pop();
void Empty();
void Delete();
void Printqueue();
int Size();
void SearchNum(int SearchNum);

int CommandNum = 0;
int ArraySize = 0;
int * queueArray = new int[100];


int main(void){
	while(1){
		PrintCommand();
		cin >>CommandNum;
		SwitchCommand(CommandNum);
	}
	delete[] queueArray;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// [[ Print ]]
//
// <Description>	A Function to Print CommandLine List
// <Return>		    None
// <Parameter>		None
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//
/////////////////////////////////////////////////////////////////////////////////////

void PrintCommand(){
	cout << endl;
	cout << "-----------------------------" << endl;
	cout << "Chose Num What you want to do" << endl;
	cout << "-----------------------------" << endl;
	cout << "1. Push" 				<< endl;
	cout << "2. Pop"				<< endl;
	cout << "3. Empty_Check"		<< endl;
	cout << "4. queue_Clear"		<< endl;
	cout << "5. queue_Size"			<< endl;
	cout << "6. SearchNum"			<< endl;
	cout << "7. Printqueue"			<< endl;
	cout << "-----------------------------" << endl;
	cout << "Input Command Number : ";
}

////////////////////////////////////////////////////////////////////////////////////
// [[ SwitchCommand ]]
//
// <Description>	A Function to Choose Function
// <Return>		    None
// <Parameter>		None
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//
/////////////////////////////////////////////////////////////////////////////////////

void SwitchCommand(int Command){
	switch(Command){
		case 1: 
			int pushNum;
			cout << "Input what you want to inputData  : ";
			cin >> pushNum;
			Push(pushNum);
			break;

		case 2: 
			Pop();
			break;

		case 3:
			Empty();
			break;

		case 4:
			Delete();
			break;

		case 5:
			cout << "Array size is : "<< Size() << endl;
			break;

		case 6:
			cout << "Input What you want to Searching Number : ";
			int FiNum;
			cin >> FiNum;
			SearchNum(FiNum);
			break;

		case 7:
			Printqueue();
			break;

		default:
			cout << " Input right Number" << endl;
			break;
	}



}


////////////////////////////////////////////////////////////////////////////////////
// [[ Push ]]
//
// <Description>	A Function to input Number in queueArray
// <Return>		    None
// <Parameter>		inputNum	: That is input parameter to Array
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.27		Create				RaviKim
/////////////////////////////////////////////////////////////////////////////////////

void Push(int inputNum){
	int pushCount	=	Size();
	(Size() == 0) ? queueArray[0] = inputNum : queueArray[pushCount] = inputNum;
}

////////////////////////////////////////////////////////////////////////////////////
// [[ Pop ]]
//
// <Description>	A Function to Pop Number in queueArray
// <Return>		    None
// <Parameter>	    None
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//					1.0.1		18.07.27		Modify				RaviKim
/////////////////////////////////////////////////////////////////////////////////////

void Pop(){
	int popCount = Size();
	if(queueArray[0] != 0)
		for(int i = 0; i < popCount; i++){
			queueArray[i] = queueArray[i+1];
		}
	queueArray[popCount] = 0;
}

////////////////////////////////////////////////////////////////////////////////////
// [[ Delete ]]
//
// <Description>	A Function to queue Mem Clear
// <Return>		    None
// <Parameter>	    None
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//
/////////////////////////////////////////////////////////////////////////////////////

void Delete(){

}

////////////////////////////////////////////////////////////////////////////////////
// [[ SearchNum ]]
//
// <Description>	A Function to Searching number
// <Return>		    None. Only Out SearchNum's position in Array
// <Parameter>	    int SearchNum
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//
/////////////////////////////////////////////////////////////////////////////////////
void SearchNum(int SearchNum){
	int SearchCheckCnt = 0;
	for(int i = 0; i < Size(); i++){
		if(queueArray[i] == SearchNum){
			cout << "Find SearchNum in " << i+1 << " position" << endl;
			SearchCheckCnt++;
		}
	}
	if(SearchCheckCnt == 0) cout << "Can't Find Number What you want " << endl;

}

////////////////////////////////////////////////////////////////////////////////////
// [[ Empty ]]
//
// <Description>	Check queue Array Null 
// <Return>		   	None
// <Parameter>	    None
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//
/////////////////////////////////////////////////////////////////////////////////////

void Empty(){
	int	EmptyCount = Size();
	if(queueArray[0] == 0 && queueArray[EmptyCount] == 0){
		cout << "queue Array is Empty" << endl;
	}
	else
		cout << "queue Array is not Empty"<< endl;
	cout << "queue have : " << EmptyCount<< endl;
}

////////////////////////////////////////////////////////////////////////////////////
// [[ Size ]]
//
// <Description>	Check queue Array Size. 
// <Return>		   	queue Size
// <Parameter>	    None
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//
/////////////////////////////////////////////////////////////////////////////////////

int Size(){
	ArraySize = 0;
	for(int i = 0; i < 100; i++){
		if(queueArray[i] !=0)	ArraySize++;
	}
	return ArraySize;
}

////////////////////////////////////////////////////////////////////////////////////
// [[ Printqueue ]]
//
// <Description>	Print present queue Array.
// <Return>		   	None. Only Print queue Array.
// <Parameter>	    None.
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//					1.0.1		18.07.27		Modify				RaviKim
/////////////////////////////////////////////////////////////////////////////////////

void Printqueue(){
	int ArrayCount = Size();

	for( int i = 0; i < ArrayCount; i++){	// RaviKim Modify 0727."<=" -> "<"
		cout << queueArray[i] << "|";
	}

	cout << endl;
}
