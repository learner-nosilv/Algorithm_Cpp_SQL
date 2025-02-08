#include <vector>
using namespace std;

long long solution(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    int nk_2 = 1;
    int nk_1 = 2;
    while(n>3){
        int temp=nk_2;
        nk_2 = nk_1;
        nk_1 = (temp + nk_1)%1234567;
        n--;
    }
    return ((nk_2+nk_1)%1234567);
}
// // 조합C 를 사용 -> 실패 (이유모름)
// long long solution(int n) {
//     long long answer = 1;               // 전부 1인 횟수 추가(전체C0)
//     int maxTwo= n/2; int minOne=n%2;    // 2가 가장 많은 상황에서의 2와 1의 갯수
    
//     // (1의 갯수+2의 갯수) C (1의 갯수 혹은 2의 갯수) / 전부 1인 경우는 선처리되어있음
//     while(maxTwo>0){
//         int total = maxTwo + minOne;                // 1과 2의 총 갯수
//         int min = (maxTwo>minOne?minOne:maxTwo);    // 1과 2의 갯수 중 작은 것
//         long long multiple = 1;
//         for(int i=0; i<min; i++){
//             multiple *= total;
//             total--;
//         }
//         for(int i=1; i<min; i++){
//             multiple /= min;
//             min--;
//         }
//         answer += multiple;
//         maxTwo--;
//         minOne+=2;
//     }
//     answer %= 1234567;
//     return answer;
// }