#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // id 검색을 용이하게 하기 위해, id와 id_list의 index가 매치된 해시맵 제작
    unordered_map <string, int> id_listMap;     // { ID, idx }
    for(int i=0 ; i<id_list.size(); i++){
        id_listMap[id_list[i]]=i;
    }

    //중복신고제거
    unordered_set <string> reportSet;
    for(string rep: report){
        reportSet.insert(rep);
    }
    
    // report 를 읽고 유저들의 신고자들 정리
    vector<int>* reporters = new vector<int>[id_list.size()]{}; // 신고자Idx저장, 0초기화
    for(string rep: reportSet){
        // cout << "신고상황: " << rep<<endl;
        int spaceIdx=rep.find(' ');
        int reporterIdx = id_listMap[rep.substr(0, spaceIdx)];
        int reporteeIdx = id_listMap[rep.substr(spaceIdx+1)];
        // cout << "reporters["<<reporteeIdx<<"].push_back("<<reporterIdx<<")" << endl;
        reporters[reporteeIdx].push_back(reporterIdx);
    }
    
    // 정지 유저를 찾고 신고자에게 메일 보내기
    vector<int> mailCounter(id_list.size());
    // int* mailCounter = new int[id_list.size()]{};
    for(int i=0; i<id_list.size(); i++){
        if(reporters[i].size()>=k){
            // cout << i<<" 의 신고횟수 : "<<reporters[i].size()<<endl;
            // cout << "신고한 사람: ";
            for(int idx: reporters[i]){
                // cout << idx <<", ";
                mailCounter[idx]++;
            }
            cout << endl;
        }
    }

    delete[] reporters;
    return mailCounter;
}