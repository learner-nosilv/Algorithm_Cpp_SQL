#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    if(s=="1") return { 0, 0 };
    int count=1;        // 이진변환횟수(누적)
    int totalZero = 0;  // 0의 갯수(누적)
    
    // 최초 0과 1의 갯수 세기
    int countOne = 0;       // 1의 갯수
    for(char a : s){
        if(a=='1') countOne++;
        else totalZero++;
    }
    
    while(true){    
        if(countOne == 1) {
            return {count, totalZero};
        }
        // 이진변환
        count++;    // 이진변환 횟수 증가
        int result = countOne;  // 0 제거 후 길이 = 1의 갯수
        countOne=0;
        while(result>0){
            if(result%2 == 1)
                countOne++;
            else
                totalZero++;
            result = result >> 1;
        }
    }
}