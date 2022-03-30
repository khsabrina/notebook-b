#pragma once
#include <iterator>
#include <map>
#include "Direction.hpp"
#include "Row.hpp"
using ariel::Direction;
#include <iostream>

class Page{
    private:
        map<int , Row> rows;
    public:
        Page();
        void add(int col,int row,Direction dir, string str);
        string read(int col,int row, Direction dir , int size);
        void erase(int col,int row, Direction dir , int size);
        void show();
        //~Page();

};