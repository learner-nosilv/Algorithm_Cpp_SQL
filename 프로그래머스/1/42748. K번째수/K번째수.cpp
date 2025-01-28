#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto i : commands){
        vector<int> temp;
        for(int j=i[0]; j<=i[1];j++){
            temp.push_back(array[j-1]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[(i[2]-1)]);
    }
    return answer;
}