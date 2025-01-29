#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    list<int> award;      // 명예의 전당
    vector<int> answer;     // 최하위 점수
    
    // score 순회
    for(int i=0; i<score.size(); i++){
        // award 순회하며 score값 삽입
        bool changed=false;
        for(list<int>::iterator iter=award.begin(); iter!=award.end(); iter++) {
            if(*iter < score[i]){
                award.insert(iter, score[i]);
                changed = true;
                break;
            }
        }
        if(changed==false){ // 최소값인 경우
            award.push_back(score[i]);
        }
        
        // 명예의 전당 최하위
        if(award.size()>k)
            award.pop_back();
        answer.push_back(award.back());
    }
    
    return answer;
}