#include <iostream>


struct DataTime{
    typedef unsigned short USh;
    DataTime(USh d, USh m, USh y, USh h, USh min, USh sec, USh milis): day(d), year(y*13+m), hour(h), minute(min), second(sec), milisecond(milis)
    {
    }
    ~DataTime(){
    }
    USh day : 5;
    USh year : 17; //year*13+month
    USh hour : 5;
    USh minute : 6;
    USh second : 6;
    USh milisecond : 10;
};

int main() {
    DataTime bot = {29, 12, 2001, 12, 45, 23, 857};
    
    return 0;
}
