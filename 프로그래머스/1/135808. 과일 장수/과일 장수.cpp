#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int total = 0;
    sort(score.begin(), score.end());
    
    for(int i=0;i<score.size()/m;i++){
        total += score[score.size()-(i+1)*m] * m;
    }
    return total;
}