//  Created by Дарья Землянская on 27.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>


struct DataTime{
    DataTime(unsigned short d, unsigned short m, unsigned short y, unsigned short h, unsigned short min, unsigned short sec, unsigned short milis): day(d), month(m), year(y), hour(h), minute(min), second(sec), milisecond(milis)
    {
    }
    ~DataTime(){
    }
    unsigned short day : 6;
    unsigned short month : 4;
    unsigned short year : 11;
    unsigned short hour : 5;
    unsigned short minute : 6;
    unsigned short second : 6;
    unsigned short milisecond : 10;
};

int main() {
    DataTime bot = {29, 12, 2001, 12, 45, 23, 857};
    
    return 0;
}
