int solution(int n, int a, int b)
{
    int count = 0;
    while(true){
        if(a==b) return count;
        a = (a+1)>>1;
        b = (b+1)>>1;
        count ++;
    }
}