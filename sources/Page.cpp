#include "Row.hpp"
#include "Page.hpp"
using namespace std;
#include <iostream>
#include <iterator>
#include <map>
const int LENGHT_ROW=100;

Page::Page(){
}
void Page::add(int col,int row,Direction dir, string str){
    if(dir == Direction::Horizontal){
        int size = str.size();
        if (col + size > LENGHT_ROW){
                throw invalid_argument{"You can't write here1"};
        }
        if (!rows.contains(row)){
            Row New;
            rows.insert({row, New});
            rows[row].add(col,str);
        }
        else{
             rows[row].check_horizontal(col, str.size());
            //if(!check){return;}
            rows[row].add(col,str);
        }
    }
    if(dir == Direction::Vertical){
        for(int i= 0; i<str.size();i++){
            if(!rows.contains(row+i)){
                Row New;
                rows.insert({row+i, New});
            }
            else{
                rows[row+i].check_vertical(col);
                //if(!check){return;}
            } 
        }
        for(int i=0; i<str.size();i++){
            string c(1, (char)str[(unsigned long)i]);
            rows[row+i].add(col,c);
        }
    }

    
}

string Page::read(int col,int row,Direction dir, int size){
    string ans;
    if(dir == Direction::Horizontal){
        if (col + size > LENGHT_ROW){
                throw invalid_argument{"You can't write here"};
        }
        if(!rows.contains(row)){
                Row New;
                rows.insert({row, New});
        }
        ans = rows[row].read(col,size);
    }
    else{
        if (col > LENGHT_ROW){
                throw invalid_argument{"You can't write here"};
        }
        for(int i=0; i<size; i++){
            if(!rows.contains(row+i)){
                Row New;
                rows.insert({row+i, New});
            }
            ans += rows[row+i].read(col,1);
        }
    }
    return ans;
}

void Page::erase(int col,int row, Direction dir , int size){
    if(dir == Direction::Horizontal){
        if (col + size > LENGHT_ROW){
            cout << "here5";
                throw invalid_argument{"You can't write here4"};
                return;
        }
        if(!rows.contains(row)){
                Row New;
                rows.insert({row, New});
        }
        rows[row].erase(col,size);
    }
    else{
        for(int i=0; i<size; i++){
            if(!rows.contains(row+i)){
                Row New;
                rows.insert({row+i, New});
            }
            rows[row+i].erase(col,1);
        }
    }
}
void Page::show(){
    map<int, Row>::iterator itr;
    for (itr = rows.begin(); itr != rows.end(); ++itr) {
        cout << itr->first << ".";
        itr->second.show();
        cout << '\n';
    }
}
// Page::~Page(){
//     return;
// }



