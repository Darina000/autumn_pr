//  Created by Дарья Землянская on 29.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>

union MyUnion{
    double error = 0;
    double result;
};

enum class Error{
    DIV_ZERO,
    MULT_ZERO,
    OUT_OF_RANGE
};

double f(Error c, double j, double k){
    MyUnion Result;
    if (k == 0){
        Result.error = 1;
        c = Error::DIV_ZERO;
    }
    else if (j == 0){
        Result.error = 1;
        c = Error::MULT_ZERO;
    }
    else if ((j > 100000) || (k > 100000)){
        Result.error = 1;
        c = Error::OUT_OF_RANGE;
    }
    
    if (Result.error != 0 ){
        switch (c) {
            case Error::DIV_ZERO:
                std::cout << "Error: DIV_ZERO" << std::endl;
                break;
            case Error::MULT_ZERO:
                std::cout << "Error: MULT_ZERO" << std::endl;
                break;
            case Error::OUT_OF_RANGE:
                std::cout << "Error: OUT_OF_RANGE" << std::endl;
                break;
            default:
                break;
        }
        return Result.error;
    }
    
    Result.result = j/k;
    std::cout <<  Result.result << std::endl;
    return Result.result;
}


int main() {
    Error error;
    double m = f(error, 3, 1);
    return 0;
}
