#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    bool find;
    for(int i=0; i<s.size(); i++){
        find=false;
        for(int j=1; j<=i; j++){
            if(s[i]==s[i-j]){
                answer.push_back(j);
                find=true;
                break;
            }
        }
        if(find==false) answer.push_back(-1);
    }
    return answer;
}