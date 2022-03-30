#include "Row.hpp"
using namespace std;
#include <iostream>
const int LENGHT_ROW =100;


Row::Row(){
    for(int i=0;i<LENGHT_ROW;i++){
        array[i] = '_';
    }
    array[LENGHT_ROW]= '\0';
}
void Row::check_horizontal(int col, int size){
    for(int i = col; i< size + col; i++){
            if(array[i] != '_'){
                throw invalid_argument{"You can't write here"};
                //return 0;
        }
    }
    //return 1;
}
void Row::check_vertical(int col){
    if(array[col] != '_'){
        throw invalid_argument{"You can't write here"};
        //return 0;
    }
    //return 1;
}

void Row::add(int col, string str){
    int size = str.size();
    for(int i=col ; i< size+col ;i++){
         int index =i-col;
            array[i] = str[(unsigned long)index];
    }
}

string Row::read(int col, int size){
    string ans;
    for(int i=col ; i< size+col ;i++){
            ans += array[i];
    }
    return ans;
}
void Row::erase(int col,int size){
    for(int i=col ; i< size+col ;i++){
            array[i] = '~';
    }
}
void Row::show(){
    for(int i =0 ; i<LENGHT_ROW; i++){
        cout << array[i];
    }
}
// Row::~Row(){
//     delete[] array;
// }