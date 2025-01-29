#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int gap=0;
    // 지나간 월 더하기
    for(int i=1;i<a;i++){
        if(i==2) gap+=29;
        else if (i==4||i==6||i==9||i==11) gap+=30;
        else gap+=31;
    }
    // 지나간 일 더하기
    gap+=b;
    // 요일
    gap%=7;
    
    switch(gap){
        case 0: return "THU";
        case 1: return "FRI";
        case 2: return "SAT";
        case 3: return "SUN";
        case 4: return "MON";
        case 5: return "TUE";
        case 6: return "WED";
    }
}