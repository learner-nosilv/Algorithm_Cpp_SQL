#include <string>
#include <vector>
#include <set>      // 연속 수열 합 저장할 자료구조

using namespace std;

int solution(vector<int> elements) {
    set<int> results;
    int i=1;    // 수열의 길이
    for(int i=0; i<elements.size(); i++){       // 길이가 1 ~ N인 경우
        for(int j=0; j<elements.size(); j++){   // 길이가 k인 경우 내에서 합의 가짓수
            int sum=0;
            int idx = j;
            for(int k=0; k<=i; k++){            // 한 번 합할 때 포함하는 원소수
                sum += elements[(idx%elements.size())];
                idx++;
            }
            results.insert(sum);
        }
    }
    return results.size();
}