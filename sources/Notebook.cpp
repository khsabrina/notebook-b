#include "Notebook.hpp"
#include "Page.hpp"
using namespace std;
#include <iostream>
const int LOW_VALID_CHAR = 32;
const int HIGH_VALID_CHAR =126;
const int LENGHT_ROW =100;

namespace ariel{
Notebook::Notebook(){
}
void Notebook::write(int page,int row,int col, Direction dir, string str){
    if (page < 0 || row < 0 || col < 0 || col >=LENGHT_ROW){
        throw invalid_argument{"Can't be a negative number"};
    }
    for(int i = 0; i < str.size(); i++){
        if (str[(unsigned long)i]< LOW_VALID_CHAR || str[(unsigned long)i] > HIGH_VALID_CHAR ||  str[(unsigned long)i]=='~'){
            throw invalid_argument{"Invalid input of string"};
        }
    }
    if(!pages.contains(page)){
        Page New;
        pages.insert({page, New});
    }
    pages[page].add(col,row,dir,str);
}
string Notebook::read(int page,int row,int col, Direction dir , int size){
    if (page < 0 || row < 0 || col < 0 || col >=LENGHT_ROW || size <0){
        throw invalid_argument{"Can't be a negative number"};
    }
    string ans;
    if(!pages.contains(page)){
        Page New;
        pages.insert({page, New});
    }
    ans = pages[page].read(col,row,dir,size);
    return ans;
}
void Notebook::erase(int page, int row,int col, Direction dir , int size){
    if (page < 0 || row < 0 || col < 0 || col >=LENGHT_ROW || size <0){
        throw invalid_argument{"Can't be a negative number"};
    }
    if(!pages.contains(page)){
        Page New;
        pages.insert({page, New});
    }
    pages[page].erase(col,row,dir,size);
}
void Notebook::show(int page){
    if (page < 0){
        throw invalid_argument{"Can't be a negative number"};
    }
    if(!pages.contains(page)){
        Page New;
        pages.insert({page, New});
    }
    pages[page].show();
}
}
