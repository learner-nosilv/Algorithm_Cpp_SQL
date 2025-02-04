#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    char indicatorAlpa[8] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    int indicator[4][2] = {{0, 0}, };  // {{R, T}, {C, F}, {J, M}, {A, N}}
    
    for(int i=0; i<survey.size(); i++){
        // R~N 지표 인식
        int minus=-1; int plus=-1;
        for(int j=0; j<8; j++){
            if(survey[i][0]==indicatorAlpa[j]){
                minus = j;
            }
            else if(survey[i][1]==indicatorAlpa[j]){
                plus = j;
            }
            if(minus!=-1 && plus!=-1) break;
        }
        // 점수 매기기
        int score = choices[i]-4;
        if (score > 0) indicator[plus/2][plus%2] += score;
        else if (score < 0) indicator[minus/2][minus%2] -= score;
    }
    
    // 결과 생성 및 출력
    string answer = "";
    for(int i=0; i<4 ; i++){
        if(indicator[i][0]>= indicator[i][1]){
            answer = answer + indicatorAlpa[2*i];
        }
        else answer = answer + indicatorAlpa[2*i+1];
    }
    return answer;
}