/////////////////////////////////////////////////////////////////////////////////////
// <<HomeWork - Make Stack >>
//
// <Description>	Make Stack DataStructure
// <Function List> 
//
//
// <Issue>			ver			issue
// 					----------------------------------------------------------------
// 					1.0.0		Make Stack's Basic Design Foundation.
// 								Must To Fix Array Parameter '0' when PrintStack() 
// 
//
//
//
// <History Info> 	Ver 		Date			Comment				Owner			
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//					1.0.1		18.07.27		Modify PrintStack	RaviKim
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
void PrintStack();
int Size();
void SearchNum(int SearchNum);

int CommandNum = 0;
int ArraySize = 0;
int * StackArray = new int[100];


int main(void){
while(1){
	PrintCommand();
	cin >>CommandNum;
	SwitchCommand(CommandNum);
}
delete[] StackArray;
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
	cout << "4. Stack_Clear"		<< endl;
	cout << "5. Stack_Size"			<< endl;
	cout << "6. SearchNum"			<< endl;
	cout << "7. PrintStack"			<< endl;
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
			PrintStack();
			break;

		default:
			cout << " Input right Number" << endl;
			break;
	}



}


////////////////////////////////////////////////////////////////////////////////////
// [[ Push ]]
//
// <Description>	A Function to input Number in StackArray
// <Return>		    None
// <Parameter>		inputNum	: That is input parameter to Array
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//					1.0.1		18.07.27		Modify				RaviKim
/////////////////////////////////////////////////////////////////////////////////////

void Push(int inputNum){
	if(Size() ==0){
		StackArray[0] = inputNum;
//		StackArray[1] = NULL;	//180727 RaviKim Make wall
	}
	else if(Size() > 0){	
	int pushCount = Size();
	StackArray[pushCount] = inputNum;// 0727 ing...
}
}

////////////////////////////////////////////////////////////////////////////////////
// [[ Pop ]]
//
// <Description>	A Function to Pop Number in StackArray
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
if(StackArray[0] != 0)
	StackArray[popCount-1] = 0;	// Modify RVKim , [popCount] -> [popCount-1]

}

////////////////////////////////////////////////////////////////////////////////////
// [[ Delete ]]
//
// <Description>	A Function to Stack Mem Clear
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
		if(StackArray[i] == SearchNum){
			cout << "Find SearchNum in " << i+1 << " position" << endl;
			SearchCheckCnt++;
		}
	}
	if(SearchCheckCnt ==0) cout << "Can't Find Number What you want " << endl;

}

////////////////////////////////////////////////////////////////////////////////////
// [[ Empty ]]
//
// <Description>	Check Stack Array Null 
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
	if(StackArray[0] == 0 && StackArray[EmptyCount] == 0){
		cout << "Stack Array is Empty" << endl;
	}
	else
		cout << "Stack Array is not Empty"<< endl;
		cout << "Stack have : " << EmptyCount<< endl;
}

////////////////////////////////////////////////////////////////////////////////////
// [[ Size ]]
//
// <Description>	Check Stack Array Size. 
// <Return>		   	Stack Size
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
		if(StackArray[i] !=0)	ArraySize++;
	}
	return ArraySize;
}

////////////////////////////////////////////////////////////////////////////////////
// [[ PrintStack ]]
//
// <Description>	Print present Stack Array.
// <Return>		   	None. Only Print Stack Array.
// <Parameter>	    None.
//
// <History Info> 	Ver 		Date			Comment				Owner
//					----------------------------------------------------------------
//					1.0.0		18.07.26		Create				RaviKim
//					1.0.1		18.07.27		Modify				RaviKim
/////////////////////////////////////////////////////////////////////////////////////

void PrintStack(){
	int ArrayCount = Size();
	
	for( int i = 0; i < ArrayCount; i++){	// RaviKim Modify 0727."<=" -> "<"
	cout << StackArray[i] << "|";
	}

	cout << endl;
}
