//  Created by Дарья Землянская on 27.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>

enum class Month{
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

void f(Month c, bool a){
    switch(c){
        case Month::January:
        case Month::March:
        case Month::May:
        case Month::July:
        case Month::August:
        case Month::October:
        case Month::December:
            std::cout << 31 << std::endl;
            break;
        case Month::February:
            if (a){
                std::cout << 29 << std::endl;
                break;
            }else{
                std::cout << 28 << std::endl;
                break;
            }
        case Month::April:
        case Month::June:
        case Month::September:
        case Month::November:
            std::cout << 30 << std::endl;
            break;
        default:
            break;
    }
}
int main() {
    Month month;
    int number;
    std::cout << "Enter the month number: " ;
    std::cin >> number;
    month = static_cast<Month>(number);
    f(month, false);
    return 0;
}
