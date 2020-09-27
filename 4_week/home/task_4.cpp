//  Created by Дарья Землянская on 27.09.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>

enum class Month{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

void f(Month c){
    switch(c){
        case Month::January:
            std::cout << "January: " << 31 << std::endl;
            break;
        case Month::February:
            std::cout << "February: " << 29 << std::endl;
            break;
        case Month::March:
            std::cout << "March: " << 31 << std::endl;
            break;
        case Month::April:
            std::cout << "April: " << 30 << std::endl;
            break;
        case Month::May:
            std::cout << "May: " << 31 << std::endl;
            break;
        case Month::June:
            std::cout << "June: " << 30 << std::endl;
            break;
        case Month::July:
            std::cout << "July: " << 31 << std::endl;
            break;
        case Month::August:
            std::cout << "August: " << 31 << std::endl;
            break;
        case Month::September:
            std::cout << "September: " << 30 << std::endl;
            break;
        case Month::October:
            std::cout << "October: " << 31 << std::endl;
            break;
        case Month::November:
            std::cout << "November: " << 30 << std::endl;
            break;
        case Month::December:
            std::cout << "December: " << 31 << std::endl;
            break;
    }
}
int main() {
    Month month;
    int number;
    std::cout << "Enter the month number: " ;
    std::cin >> number;
    month = Month(number);
    f(month);
    return 0;
}
