#include <string>
#include <stack>

using namespace std;

bool isValid(string str){
    stack<char> st;
    for(char s : str){
        // 열리는 괄호 차곡차곡 스텍에 쌓기
        if( s == '(' || s == '{' || s == '['){
            st.push(s);
        } else {    // 열리는 괄호가 아닌 경우(짝이 맞는 닫는 괄호여야함)
            // 첫 문자부터 여는 괄호가 아니라면 올바르지 않음
            if(st.empty()) return false;
            // 최근의 열리는 괄호(스텍)와 현재 문자열에서 검사중인 문자가 같은 짝이어야 함
            char open = st.top();   // 최근의 열리는 괄호와
            if(s-open== 1 || s-open == 2){  // 검사 중인 문자가 같은 짝이라면
                st.pop();           // 해당 짝 제거
            } else{
                return false;               // 다른 짝이라면 올바르지 않음
            }
        }
    }
    return st.empty();              // 스택이 아예 비어있어야 올바름
}

int solution(string s){
    int count = 0;
    
    for(int i=0; i<s.size(); i++){
        // 문자열을 회전한 후 검사
        if( isValid(s.substr(i) + s.substr(0, i)) ){
            count ++;
        }
    }
    return count;
}