#include <string>
#include <vector>
#include <unordered_map>    // 같은 사이즈의 귤 추가
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    // 귤을 크기 별로 갯수 세기 | 맵 { 귤크기 : 갯수 }
    unordered_map<int, int> tangerineMap;
    for(int tan: tangerine){
        // if(tangerineMap.find(tan)==tangerineMap.end()){
        //     tangerineMap[tan]=1;
        // }
        // else{
            tangerineMap[tan]++;
        // }
    }
    
    // 갯수(value) 별로 내림차순 정렬을 하기 위해서 벡터로 변환
    vector<pair<int, int>> tangerineVec(tangerineMap.begin(), tangerineMap.end());
    
    // 갯수(value) 기준 내림차순 정렬
    sort(tangerineVec.begin(), tangerineVec.end(), [](const auto &a, const auto &b){return a.second > b.second;});
    
    int counter=0;
    for(auto pair :tangerineVec){
        k -= pair.second;
        counter++;
        if(k<=0) break;
    }
    return counter;
}