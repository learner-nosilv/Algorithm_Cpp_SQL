// https://school.programmers.co.kr/learn/courses/14743/lessons/116435
using namespace std;
int addDivideThem(int n, int a=0, int b=1){
    if(n==0) return a;
    if(n==1) return b;
    if(n==2) return (a+b)%1234567;
    if(n>2) return addDivideThem(n-1, b, (a+b)%1234567);
}

int solution(int n) {
    return addDivideThem(n);
}