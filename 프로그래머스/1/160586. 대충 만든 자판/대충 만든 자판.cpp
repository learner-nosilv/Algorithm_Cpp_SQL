#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    // 모든 알파벳에 대한 최소 입력횟수를 파악한다
    int key[26] = {0, };
    for(string s : keymap){
        for(int i=0; i<s.size(); i++){
            int alpaIdx = s[i]-'A';
            if(key[alpaIdx] == 0 || key[alpaIdx] > i+1)
                key[alpaIdx] = i+1;
        }
    }
    
    vector<int> answer;
    int count=0;
    for(string s : targets){
        for(int i=0; i<s.size(); i++) {
            int alpaIdx = s[i]-'A';
            if(key[alpaIdx] == 0){
                count = -1;
                break;
            }
            count += key[alpaIdx];
        }
        answer.push_back(count);
        count=0;
    }
    return answer;
}