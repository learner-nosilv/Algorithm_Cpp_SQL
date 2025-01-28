#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    set<int> numSet;
    for(int i=0;i<numbers.size()-1; i++){
        for(int j=i+1; j<numbers.size(); j++){
            numSet.insert(numbers[i]+numbers[j]);
        }
    }
    vector<int> answer;
    for(auto i : numSet){
        answer.push_back(i);
    }
    
    return answer;
}