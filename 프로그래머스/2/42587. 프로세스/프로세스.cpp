#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pQ;             // 우선순위 큐
    queue<pair<int, int>> prioritiesQ;  // 일반 큐{ priorities 인덱스, 우선순위 }
    
    // 1. 큐 초기화
    int size = priorities.size();
    for(int i=0; i<size; i++){
        pQ.push(priorities[i]);
        prioritiesQ.push({i, priorities[i]});
    }
    
    // 2. 대기 프로세스 실행
    int count =0;   // 실행된 프로세스 개수

    while(!prioritiesQ.empty()){
        pair<int, int> current = prioritiesQ.front();    // 현 프로세스의 {인덱스, 우선순위}
        prioritiesQ.pop();
        
        // 현 프로세스의 우선순위가 전체 큐에서 가장 높은 우선순위라면
        if(current.second == pQ.top()){
            pQ.pop();   // 우선순위 큐에서 제거 = 실행시키고
            count++;    // 실행 프로세스카운트 증가
            
            // 현 프로세스가 언제 실행되는지 알고싶은 프로세스라면
            if(current.first == location){
                return count;   // 메인함수 종료
            }
        }
        // 현 프로세스의 우선순위가 전체 큐에서 가장 높은 우선순위는 아니라면
        else {
            prioritiesQ.push(current);  // 다시 일반 큐의 끝으로 푸시
        }
    }
}