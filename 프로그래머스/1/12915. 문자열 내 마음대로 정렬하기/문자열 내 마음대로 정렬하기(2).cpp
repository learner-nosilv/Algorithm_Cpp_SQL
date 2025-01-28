#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool sortN(string a, string b){
    if(a[N]==b[N])
        return (a < b);
    else
        return (a[N]<b[N]);
}

vector<string> solution(vector <string> strings, int n){
    N=n;
    sort(strings.begin(), strings.end(), sortN);
    // // 인덱스 n기준 정렬
    // for(int i=0; i<strings.size()-1; i++){
    //     for(int j=i+1; j<strings.size();j++){
    //         if(strings[i][n]>strings[j][n]){
    //             string temp = strings[i];
    //             strings[i] = strings[j];
    //             strings[j] = temp;
    //         }
    //         // 동률인 경우, 사전 순 소팅
    //         if(strings[i][n]==strings[j][n]){
    //             if(strings[i] > strings[j]){
    //                 string temp = strings[i];
    //                 strings[i] = strings[j];
    //                 strings[j] = temp;
    //             }
    //         }
    //     }
    // }
    return strings;
}
