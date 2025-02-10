#include <vector>
#include <unordered_set>      // 연속 수열 합 저장할 자료구조

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> results;

    int size = elements.size();
    for(int i=0; i<size; i++){  // i = 길이-1
        int sum=0;
        for(int j=i; j<i+size; j++){
            sum += elements[j%size];
            results.insert(sum);
        }
    }
    return results.size();
}