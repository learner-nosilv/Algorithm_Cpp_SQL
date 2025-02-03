#include <string>
#include <vector>
#include <algorithm>

using namespace std;
char jump(char c, string skip, int jump){
    sort(skip.begin(), skip.end());       // 스킵 문자열 오름차순 정리
    
    if(c+jump < skip[0]) return c+jump;   // 빠른 처리가 가능한 상황 선처리
    
    int cPtr = 0;
    // 비교할 문자가 skip 어디에 있는지 체크
    for(int i=0; i<skip.size(); i++){
        if(c<skip[i]){
            cPtr=i;
            break;
        }
    }

    // 위에서 정한 위치에서부터 비교
    int i=cPtr;
    while(jump != 0){
        c++;            // 한 칸 이동
        if(c>'z') {     // 이동한 위치가 z를 초과하는 경우, 한 바퀴 돌리고 재시작
            c = c-'z'+'a'-2;
            continue;
        }
        if(c == skip[i]) i=((i+1)%skip.size());
        else jump--;
    }
    return c;
}
    
string solution(string s, string skip, int index) {
    string answer = "";
    for(int i=0; i<s.size(); i++){
        answer = answer + jump(s[i], skip, index);
    }
    return answer;
}