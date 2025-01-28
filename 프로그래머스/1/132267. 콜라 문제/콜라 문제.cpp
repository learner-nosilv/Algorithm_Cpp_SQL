#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = b*(n/a);
    int remain = n;
    while(remain>=a){
        remain = b*(remain/a) + remain%a;
        answer += b*(remain/a);
    }
    return answer;
}