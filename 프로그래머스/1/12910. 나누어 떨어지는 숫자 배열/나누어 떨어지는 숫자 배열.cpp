// 방법 1. algorithm의 sorting 활용
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    // array의 각 element 중 divisor로 나누어 떨어지는 값을 answer 벡터에 추가
    for(auto i : arr){
        if(!(i%divisor)){
            answer.push_back(i);
        }
    }   
    
    // divisor로 나누어 떨어지는 element가 한 개 혹은 0개 인 경우
    if(answer.empty()) {
        answer.push_back(-1);
        return answer;
    }

    // element가 2개 이상인 경우 
    sort(answer.begin(), answer.end());
    return answer;
}