#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxVisit = 0;   // 현재까지 발견된 최대 던전탐험횟수

void dfs(int fatigue, vector<vector<int>>& dungeons, vector<bool>& visited, int count){
    // fatigue: 현재 피로도          dungeons: 전체 던전 정보
    // visited: 현재 던전 방문 상태    count: 현재 던전 방문횟수
    
    // 최대 던전탐험횟수 갱신
    if(maxVisit<count)
        maxVisit = count;
    
    // 탐색 시작
    int dungeonSize = dungeons.size();
    for(int i=0; i<dungeonSize; i++){
        // 현재 던전을 방문하지 않았고 && 현재 피로도가 던전 입장제한피로도 이상이면
        if(visited[i]==false && fatigue >= dungeons[i][0]){
            // 방문
            visited[i]=true;
            // 현재 던전을 방문한 상태로, 다음 던전 방문(재귀)
            dfs(fatigue-dungeons[i][1], dungeons, visited, count+1);
            
            // 현재 던전을 방문한 이후의 모든 던전 탐색이 완료되었으므로
            // 현재 던전을 방문하지 않은 상태로 되돌림(백트래킹)
            visited[i]=false;
        }
    }
}

// DFS vs Greedy
// 탐색의 양이 적절하다 = 모든 경우의 수 확인가능 (8! = 40320) -> DFS
// 신속성보다는 정확성(반례가 없는 것)이 중요 -> DFS
int solution(int k, vector<vector<int>> dungeons) {
    // 던전을 입장 피로도 오름차순으로 정렬
    sort(dungeons.begin(), dungeons.end());
    
    // 던전방문상태 를 전부 false로 초기화
    vector<bool> visited(dungeons.size(), false);
    
    // 완전탐색(DFS, 백트래킹) 시작
    // 인자: 현재 피로도, 전체 던전 정보, 던전 방문 상태(전부 false), 방문 횟수(0)
    dfs(k, dungeons, visited, 0);
    
    // dfs 함수로 연산완료된 전역변수 maxVisit(최대 던전 방문횟수) 리턴
    return maxVisit;
}