#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int empty=0;    // 빈자리
    
    // 내림차순 정렬
    sort(lottos.rbegin(), lottos.rend());
    sort(win_nums.rbegin(), win_nums.rend());

    while(!lottos.empty() && lottos.back()==0) {
        lottos.pop_back();
        empty++;
    }
    
    // 현재 맞춘 갯수 카운팅
    int match=0;     // 맞춘갯수
    int l=0;
    int w=0;
    while(l<lottos.size() && w<win_nums.size()){
        if(lottos[l]==win_nums[w]) { match++; l++; w++; }
        else if(lottos[l]<win_nums[w]) w++;
        else l++;
    }
    cout << empty << ':' << match << endl;
    
    vector<int> answer;
    answer.push_back( (empty+match>1 ? 7-(empty+match) : 6) );  // 최고등수
    answer.push_back( (match>1 ? 7-(match) : 6) );              // 최저등수
    
    return answer;
}