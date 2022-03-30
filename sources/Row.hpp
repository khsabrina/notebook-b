#pragma once
#include <iostream>
using namespace std;

class Row {       // The class
    private:             // Access specifier       // Attribute (int variable)
        char * array = new char[101];
    public:
        Row();
        void add(int col, string str);
        string read(int col, int size);
        void check_horizontal( int col, int size);
        void check_vertical( int col);
        void erase( int col,int size);
         void show();
        //~Row();
        // delete[] array;
        // }
};