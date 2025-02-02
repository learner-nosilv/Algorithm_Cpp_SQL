#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> students(n, 1);     // 학생 별 체육복 갯수 (학생 수만큼 1으로 채워진 벡터 생성)
    for(int a : lost)               // 도난 당한 체육복 반영
        students[a-1]--;
    for(int a : reserve)            // 여분의 체육복 반영
        students[a-1]++;
    
    for(int i=0; i<students.size(); i++){
        if(students[i]==0){
            // 왼쪽 살펴서 빌려주기
            if(i!=0 && students[i-1]>1){
                students[i-1]--;
                students[i]++;
                continue;
            }
            // 오른쪽 살펴서 빌려주기
            if(i!=students.size()-1 && students[i+1]>1){
                students[i+1]--;
                students[i]++;
            }
        }
    }
    
    // 체육수업을 들을 수 있는 학생 수 세기
    int answer = 0;
    for(int a : students){
        if(a >0) answer++;
    }
    return answer;
}