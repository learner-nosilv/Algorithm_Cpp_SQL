#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int dogPoint[2];    // 강아지 위치(행, 열)
    
    // 강아지 시작위치 찾기
    for(int row=0; row<park.size(); row++){
        bool find = false;
        for(int col=0; col<park[0].size(); col++){
            if(park[row][col] == 'S'){
                find=true;
                dogPoint[0] = row;
                dogPoint[1] = col;
                break;
            }
        }
        if(find==true) break;
    }
    
    // routes 명령어대로 이동하기
    for(string route: routes){
        // 한 명령 route의 방향과 거리 파악
        char direction = route[0];
        int distance = stoi(route.substr(2));
        switch (direction) {
            case 'N':
                if(dogPoint[0]>=distance){              // 공원 내부에서 움직이고
                    bool isBarrier=false;
                    for(int i=1; i<=distance; i++){     // 장애물도 만나지 않으면
                        if(park[dogPoint[0]-i][dogPoint[1]] == 'X'){
                            isBarrier=true;
                            break;
                        }
                    }
                    if(isBarrier==false){
                       dogPoint[0]-=distance;
                    }
                }
                break;
            case 'S':
                if(dogPoint[0]+distance<park.size()){              // 공원 내부에서 움직이고
                    bool isBarrier=false;
                    for(int i=1; i<=distance; i++){     // 장애물도 만나지 않으면
                        if(park[dogPoint[0]+i][dogPoint[1]] == 'X'){
                            isBarrier=true;
                            break;
                        }
                    }
                    if(isBarrier==false){
                       dogPoint[0]+=distance;
                    }
                }
                break;
            case 'W':
                if(dogPoint[1]>=distance){              // 공원 내부에서 움직이고
                    bool isBarrier=false;
                    for(int i=1; i<=distance; i++){     // 장애물도 만나지 않으면
                        if(park[dogPoint[0]][dogPoint[1]-i] == 'X'){
                            isBarrier=true;
                            break;
                        }
                    }
                    if(isBarrier==false){
                       dogPoint[1]-=distance;
                    }
                }
                break;
            case 'E':
                if(dogPoint[1]+distance<park[0].size()){              // 공원 내부에서 움직이고
                    bool isBarrier=false;
                    for(int i=1; i<=distance; i++){     // 장애물도 만나지 않으면
                        if(park[dogPoint[0]][dogPoint[1]+i] == 'X'){
                            isBarrier=true;
                            break;
                        }
                    }
                    if(isBarrier==false){
                       dogPoint[1]+=distance;
                    }
                }
                break;
        }
    }
    vector<int> answer = { dogPoint[0], dogPoint[1] };
    return answer;
}