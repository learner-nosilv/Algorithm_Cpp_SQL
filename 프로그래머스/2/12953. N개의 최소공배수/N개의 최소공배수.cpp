#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;
// 최소공배수 = 곱 / 최대공약수

int solution(vector<int> arr) {
    // 1부터 100까지의 소수가 얼마 없어서(25개) 이를 사용함
    int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    unordered_map<int, int> element;    // 한 원소의 소인수분해 결과
    unordered_map<int, int> lcm;        // LCM <약수: 개수>
    for(int i = 0 ; i<25; i++){
        lcm[prime[i]] = 0;
    }                                                         
    
    for(int i = 0; i<arr.size(); i++){
        // 한 원소의 소인수분해 진행
        for(int j = 0; arr[i] >= prime[j]; j++){
            // 소수로 나눈 후, 나누어 떨어진다면
            if(arr[i] % prime[j] ==0){
                // 해시맵을 사용하여 해당 소수(키)의 지수(값)를 올리기
                // 해당 소수(키)가 없다면 생성한 후, 위의 작업 진행
                if(element.find(prime[j]) == element.end()){
                    element[prime[j]] = 0;
                }
                element[prime[j]]++;
                arr[i]=arr[i]/prime[j];
                j--;
            }
        }

        // 최대공배수의 소인수분해 식에 취합
        for(const auto& pair : element){
            // 최대공배수 배열에 약수가 없다면
            if(lcm.find(pair.first) == lcm.end() || lcm[pair.first] < pair.second){
                lcm[pair.first] = pair.second;
            }
        }
        
        // 소인수 분해가 완료되면 해시맵 초기화
        element.clear();
    }
    
    int answer = 1;
    for(const auto& pair : lcm){
        for(int i=0 ; i<pair.second; i++){
            answer *= pair.first;
        }
    }
    return answer;
}