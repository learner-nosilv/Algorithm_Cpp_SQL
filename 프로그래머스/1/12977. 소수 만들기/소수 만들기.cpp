#include <vector>
#include <cmath>
using namespace std;

bool checkPrime(int a){
    for(int divider=2; divider <= sqrt(a); divider++){
        if(a%divider==0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+1; j<nums.size()-1; j++){
            for(int k=j+1; k<nums.size(); k++){
                if(checkPrime(nums[i]+nums[j]+nums[k])) answer++;
            }
        }
    }
    return answer;
}