#include <vector>
#include <unordered_set>      // 연속 수열 합 저장할 자료구조

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> results;

    int size = elements.size();
 
    for(int i=0; i<size; i++){  // i = 0 ~ 길이-2
        int sum=0;
        for(int j=i; j<i+size-1; j++){
            sum += elements[j%size];
            results.insert(sum);
        }
    }
    return results.size()+1;
}