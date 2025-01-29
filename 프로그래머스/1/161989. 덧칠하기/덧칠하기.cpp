#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    while(!section.empty()){
        int startPoint=section.back()-m+1;
        while(!section.empty() && section.back() >= startPoint){
            section.pop_back();
        }
        answer++;
    }
    return answer;
}