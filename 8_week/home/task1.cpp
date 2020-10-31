//  Created by Дарья Землянская on 29.10.2020.
//  Copyright © 2020 Дарья Землянская. All rights reserved.
//

#include <iostream>

enum class Error{
    FAILURE,
    //...
};

using result_t = double;
using error_t = Error;

union Value{
    error_t error; //тут ошибка из перечисления
    result_t result;
};

struct Answer
{
    bool has_error; //если true, то читать поле error, иначе result
    Value value;
};

Answer f(double j, double k){
    Answer answer;
    answer.value.result = j/k;
    if ((k == 0) || (j > 100000) || (k > 100000) ){
        answer.has_error = true;
    }else{
        answer.has_error = false;
    }
    
    if (answer.has_error == true){
        answer.value.error = Error::FAILURE;
    }else{
        answer.value.result = j/k;
    }
    
    return answer;
}


int main() {

    Answer ans = f(3, 0);
    
    return 0;
}

