#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for(int i=1 ; i<= sqrt(yellow); i++){
        if(yellow%i == 0){
            int yellowH=i;
            int yellowW=yellow/i;
            int brownBlocks = 4;
            brownBlocks += yellowH+yellowH+yellowW+yellowW;
            if(brown == brownBlocks) return {yellowW+2, yellowH+2};
        }
    }
}