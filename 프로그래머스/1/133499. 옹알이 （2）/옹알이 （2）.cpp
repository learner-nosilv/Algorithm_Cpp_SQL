#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    string word[4] = { "aya", "ye", "woo", "ma" };
    string doubleWord[4] = { "ayaaya", "yeye", "woowoo", "mama" };
    
    // Idx삭제가 쉬운 linked list로 자료형 변경
    list<string> babblingList;
    for(auto i : babbling){
        babblingList.push_back(i);
    }

    // 단어 중복이 한 번이라도 있는 단어와 길이가 1인 단어 제외
    for(list<string>::iterator iter = babblingList.begin(); iter != babblingList.end(); iter++){
        // 단어 길이가 1인 단어 제외
        if( (*iter).size()<2 ){
            list<string>::iterator temp = iter;
            iter--;
            babblingList.erase(temp);
            continue;
        }
        // 단어 중복이 한 번이라도 있는 단어 제외
        for(auto i : doubleWord){
            if( (*iter).find(i) != string::npos ){
                list<string>::iterator temp = iter;
                iter--;
                babblingList.erase(temp);
                break;
            }
        }    
    }
    
    // 조카가 할 수 있는 4가지 발음과 겹치는 단어파트 제거 -> 빈 문자열로 바뀐 단어는 전부 조카가 발음할 수 있음
    for(list<string>::iterator iter = babblingList.begin(); iter != babblingList.end(); iter++){
        for(int i=0; i<sizeof(word)/sizeof(word[0]); i++){
            if( (*iter).find( word[i] ) == 0 ){
                (*iter).replace(0, word[i].size(), "");
                i=-1;
                continue;
            }
        }
    }
    
    // 빈 문자열인 단어만 카운팅
    int count = 0;
    for(list<string>::iterator iter = babblingList.begin(); iter != babblingList.end(); iter++){
        if(*iter == "") count ++;
    }
    return count;
}