#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    size_t startIdx = 0;
    size_t nextSpaceIdx = 0;
    int max, min;
    // 최초 값
    nextSpaceIdx = s.find(' ', startIdx);
    max=min=stoi(s.substr(0, nextSpaceIdx));
    startIdx = nextSpaceIdx+1;
    
    int temp;
    while(true){
        nextSpaceIdx = s.find(' ', startIdx);
        if(nextSpaceIdx == string::npos){
            temp = stoi(s.substr(startIdx));
            if(temp<min) min=temp;
            else if(temp>max) max=temp;
            break;
        }
        else{
            temp = stoi(s.substr(startIdx, nextSpaceIdx-startIdx));
            if(temp<min) min=temp;
            else if(temp>max) max=temp;
            startIdx = nextSpaceIdx+1;
        }  
    }
    return (to_string(min) + ' ' + to_string(max));
}