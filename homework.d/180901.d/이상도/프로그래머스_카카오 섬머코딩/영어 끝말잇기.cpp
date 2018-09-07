#include <string>
#include <vector>
#include <iostream>
#include<map>
using namespace std;

map<string, bool> mp;
int turns[10];
vector<int> solution(int n, vector<string> words) {
    mp.clear();
    vector<int> answer;
    answer.resize(2);
    answer[0] = 0;
    answer[1] = 0;
    
    char last = words[0][words[0].size()-1];
    
    mp[words[0]] = true;
    int turn = 1;
    turns[0]++;
    for(int i = 1; i < words.size(); i++){
        string& str = words[i];
        if(mp[words[i]] || last != str[0]) {
            answer[0] = turn + 1;
            answer[1] = turns[turn]+1;
            break;
        }
        
        mp[str] = true;
        turns[turn]++;
        last = str[str.size()-1];
        turn = (turn+1)%n;
    }

    return answer;
}