int solution(int n, int a, int b)
{
    // a < b 로 정렬
    if(a>b){
        int temp=a;
        a=b;
        b=temp;
    }
    
    int count = 1;
    while(true){
        if(a%2!=0 && a+1==b) return count;
        a = (a+1)>>1;
        b = (b+1)>>1;
        count ++;
    }
}