#include <string>
using namespace std;

string solution(string s) {
    int size = s.size();
    // 홀수
    if(size%2){
        return s.substr(size/2,1);
    }
    else{
        return s.substr(size/2-1,2);
    }
}