#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> award;      // 명예의 전당
    vector<int> answer;     // 최하위 점수
    
    // score 순회
    for(auto i : score){
        award.push_back(i);                 // 명전 추가
        sort(award.rbegin(), award.rend());   // 명전 소팅
        if(award.size()>k)                  // 명전이 만석이면 제거 
            award.pop_back();
        answer.push_back(award.back());     // 명전 최하위 추가
    }
    
    return answer;
}