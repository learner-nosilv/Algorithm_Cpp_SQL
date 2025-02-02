#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    if(s.size()==1) return 1;
    
    vector<string> divided;
    int i=0;
    while(i<s.size()){
        int eq=0; int neq=0;
        for(int j=0; j<s.size(); j++){
            if(s[i] == s[j]) eq++;
            else neq++;
            // 처음으로 두 횟수가 같아지는 순간
            if(eq == neq){
                divided.push_back(s.substr(0,j+1));
                s=s.substr(j+1);
                i=-1;
                break;
            }
        }
        i++;
    }
    if(s!="") divided.push_back(s);

    return divided.size();
}