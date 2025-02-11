#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend()); // 내림차순 정렬
    for(int i=0; i<citations.size(); i++){
        if(citations[i]<=(i+1)) return i;
    }
}