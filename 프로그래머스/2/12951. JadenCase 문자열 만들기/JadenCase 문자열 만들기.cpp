#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool isFirst = true;
    for(int i=0; i<s.size(); i++){
        if(isFirst==true){
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i]-'a'+'A';
            isFirst=false;
        }
        else if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i]-'A'+'a';
        if(s[i]==' ') isFirst=true;
    }
    return s;
}