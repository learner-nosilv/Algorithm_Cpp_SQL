#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int N = 0;
    int burger[4] = {1, 2, 3, 1};
    
    while(true) {
        int i=0;
        while(i<(ingredient.size()-3)){
            if (ingredient.size() < 4) return N;
            // 재료 4개 [0-3] 을 한 단위로 재료 검사
            bool find = true;
            for(int j=0; j<4; j++){
                if(ingredient[i+j] != burger[j]) {
                    find = false;
                    break;
                }
            }
            // 재료가 다 있는 경우를 찾은 경우, 빼서 버거 제조
            if(find == true){
                N++;
                ingredient.erase(ingredient.begin() + i, ingredient.begin() + i + 4);
                i=(i-3<0?0:i-3);
                continue;
            }
            // 재료가 없는 경우, 다음 재료 4개 [1-4] 를 한 단위로 재료 검사
            else {
                i++;
            }
        }
        return N;
    }
}