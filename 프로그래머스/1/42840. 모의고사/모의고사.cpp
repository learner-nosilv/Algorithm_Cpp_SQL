#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> score = {0, 0, 0};      // 수포자 점수
    vector<vector<int>> pattern = {{1,2,3,4,5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};                              // 수포자 패턴
    
    // 채점
    for(int i=0;i<answers.size();i++){
        for(int j=0; j<score.size(); j++){
            if(answers[i] == pattern[j][i%pattern[j].size()]) score[j]+=1;
        }
    }
    
    // 최고점수 찾기
    int max=score[0];
    for(int i=1; i<score.size(); i++){
        if(max<score[i]) max = score[i];
    }
    // 최고득점자 찾기
    vector<int> answer;
    for(int i=0; i<score.size(); i++){
        if(max==score[i]) answer.push_back(i+1);
    }
    return answer;
}