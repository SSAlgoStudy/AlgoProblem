#include <string>
#include <vector>
#include<algorithm>
#include<functional>
#include<map>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    int n  = A.size();
    
    int Bidx = 0;
    int Bend = n-1;
    for(int i = 0; i < n; i++){
        
        if(A[i] < B[Bidx]){
            answer++;
            Bidx++;
        }
        else{
            Bend--;
        }
    }
    
    return answer;
}