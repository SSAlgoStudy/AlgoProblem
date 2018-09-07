#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    int value = 0;
    int i = 0;
    while(i < d.size()&&  value + d[i] <= budget){
        value += d[i];
        i++;
        answer++;
        
    }
    return answer;
}