#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    int buddys[10]={0,};        // 공통으로 나타나는 0~9의 갯수
    
    // 오름차순 소팅
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    
    for(int i=0; i<10; i++){
        int x=0; int y=0;           // X, Y 별 숫자의 갯수
        char num = i+'0';
        
        // X, Y 별 특정 숫자의 갯수를 센 후 이 중 작은 숫자로 결정 (공통된 수)
        x = (int)X.rfind(num) + 1;
        y = (int)Y.rfind(num) + 1;
        buddys[i] = (x<y? x: y);
        
        // 둘 중에 하나가 더 이상 숫자가 없는 경우, 해당 숫자부터는 전부 0 처리
        if(x == X.size() || y == Y.size()){
            for( i = i+1 ; i<10 ; i++){
                buddys[i] = 0;
            }
            break;
        }
        
        X = X.substr(x);
        Y = Y.substr(y);
    }
    
    // 공통된 숫자가 0뿐이거나 없는 경우 선처리
    bool isNone=true;
    for(int i=1; i<10; i++){
        if(buddys[i]!=0) {
            isNone=false;
            break;
        }
    }
    if(isNone){
        if(buddys[0]) return "0";
        else return "-1";
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
    return buddy;
}