#include "Page.hpp"
#include <iostream>
#include "Direction.hpp"
using ariel::Direction;
using namespace std;

namespace ariel {
	class Notebook {
        private:
            map<int, Page> pages;
        public:
            Notebook();
            void write(int page, int row,int col, Direction dir, string str);
            string read(int page,int row,int col, Direction dir , int size);
            void erase(int page,int row,int col, Direction dir , int size);
            void show(int page);
        
    };
}