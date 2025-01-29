#include <string>
#include <vector>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> cards1Q;
    queue<string> cards2Q;
    queue<string> goalQ;
    for(auto i : cards1){
        cards1Q.push(i);
    }
    for(auto i : cards2){
        cards2Q.push(i);
    }
    for(auto i : goal){
        goalQ.push(i);
    }
    while(!goalQ.empty()){
        if(!cards1Q.empty() && (cards1Q.front()==goalQ.front())){
            cards1Q.pop();
            goalQ.pop();
            continue;
        }
        if(!cards2Q.empty() && (cards2Q.front()==goalQ.front())){
            cards2Q.pop();
            goalQ.pop();
            continue;
        }
        if(cards1Q.empty() && (cards2Q.front()!=goalQ.front())){
            return "No";
        }
        if(cards2Q.empty() && (cards1Q.front()!=goalQ.front())){
            return "No";
        }
        if((cards1Q.front()!=goalQ.front()) && (cards2Q.front()!=goalQ.front())){
            return "No";
        }
    }
    if(goalQ.empty()){
            return "Yes";
    }
}