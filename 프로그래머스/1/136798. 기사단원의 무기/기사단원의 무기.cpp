#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 약수의 개수를 출력하는 함수
int divisorCounter(int a){
    int counter=0;
    double sqrtA=sqrt(a);
    if((int)sqrtA*(int)sqrtA==a) counter++;
    for(int i=1; i<sqrtA; i++){
        if(a%i==0) counter += 2;
    }
    return counter;
}

int solution(int number, int limit, int power) {
    int answer =0;
    for(int i=1 ; i<=number ; i++){
        int knightPower=divisorCounter(i);
        if(knightPower>limit) knightPower = power;
        answer += knightPower;
    }
    return answer;
}