#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int lux=-1; int luy=-1;
    int rdx=-1; int rdy=-1;
    
    for(int i=0; i<wallpaper.size(); i++){
        if (wallpaper[i].find('#') != std::string::npos){
            int idx = wallpaper[i].find('#');
            cout << idx << endl;
            if(lux==-1) {lux = idx; luy = i;}
            else if(lux>idx) {lux = idx;}
        }
    }
    for(int i=0; i<wallpaper.size(); i++){
        if (wallpaper[i].rfind('#') != std::string::npos){
            int idx = wallpaper[i].rfind('#');
            cout << idx << endl;
            if(rdx==-1) {rdx = idx; rdy = i;}
            else if(rdx<idx) {rdx = idx;}
            if(rdy<i) {rdy=i;}
            
        }
    }
    rdx++; rdy++;
    vector<int> answer = {luy, lux, rdy, rdx};
    return answer;
}