#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int todayInt[3] = { stoi(today.substr(0, 4)), stoi(today.substr(5, 2)), stoi(today.substr(8, 2))};  // { year, month, day } 순 으로 저장
    vector <int*> termsInt;
    for(string str : terms){
        termsInt.push_back(new int[2]{str[0], stoi(str.substr(2))});
    }
    cout << "오늘" << todayInt[0] << '-'<< todayInt[1] << '-' << todayInt[2]<<endl;
    
    
    vector<int> answer;
    
    // 비교 판단
    for(int i=0; i<privacies.size(); i++){
        // 해당 회원의 개인정보 수집 일자
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2));
        cout << "수집일 " << year << '-'<< month << '-' << day<<endl;
        // 해당 회원에 해당하는 약관
        int term = privacies[i][11];
        
        // 해당 회원의 유효기간만료일 찾기 (해당일까지는 유효)
        int gapMonth = 0;
        for(int j=0; j<termsInt.size(); j++){
            if(term ==termsInt[j][0]){
                gapMonth = termsInt[j][1];
                cout << "gapMonth: "<<gapMonth<<endl;
                break;
            }
        }
        month += gapMonth;
        while(month>12){
            year++;
            month=month-12;
        }
        
        cout << "만료일(파기) " << year << '-'<< month << '-' << day<<endl;
        // 파기해야할지 판단
        if(year == todayInt[0]) {
            if(month < todayInt[1]) answer.push_back(i+1);
            else if(month == todayInt[1]){
                if(day <= todayInt[2]) answer.push_back(i+1);
            }
        }
        else if(year < todayInt[0]) answer.push_back(i+1);
    }
    for(int* arr : termsInt) delete[] arr;  // 동적 메모리 할당의 해제
    return answer;
}