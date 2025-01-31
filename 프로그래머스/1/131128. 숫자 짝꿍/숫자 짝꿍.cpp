#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    int buddys[10]={0,};
    int xCount[10]={0,};
    int yCount[10]={0,};
    // X, Y 의 숫자 갯수 체크
    for( char i : X ){ xCount[i-'0']++; }
    for( char i : Y ){ yCount[i-'0']++; }
    
    // X, Y 가 공통적으로 가진 숫자 갯수 체크
    for(int i=0; i<10; i++){
        buddys[i] = (xCount[i]<yCount[i] ? xCount[i] : yCount[i]);
    }
    
    // 가장 큰 정수 만들기
    string buddy = "";
    for(int i=0; i<10; i++){
        string temp="";
        for( int j=0 ; j < buddys[i] ; j++){
            temp+=to_string(i);
        }
        buddy = temp + buddy;
    }
    
    // 출력하기
    if (buddy == "") { buddy="-1"; }
    else if (buddy[0] == '0') { buddy = "0"; }
    return buddy;
}