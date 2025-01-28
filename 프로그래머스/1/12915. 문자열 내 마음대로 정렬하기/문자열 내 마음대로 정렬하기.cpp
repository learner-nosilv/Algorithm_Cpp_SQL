#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector <string> strings, int n){
    
    // 인덱스 n기준 정렬
    for(int i=0; i<strings.size()-1; i++){
        for(int j=i+1; j<strings.size();j++){
            if(strings[i][n]>strings[j][n]){
                string temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
    
    // 동률인 경우 사전 순으로
    for(int i=0; i<strings.size()-1; i++){
        for(int j=i+1; j<strings.size();j++){
            if(strings[i][n]==strings[j][n]){
                if(strings[i] > strings[j]){
                    string temp = strings[i];
                    strings[i] = strings[j];
                    strings[j] = temp;
                }
            }
        }
    }
    
    return strings;
}