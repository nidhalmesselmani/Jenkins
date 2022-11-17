#include<iostream>
#include "dog.h"
#include "operations.h"
#include "log.h"

int main(){
    double result = add(2,70);
    std::cout << "result : " << result << std::endl;

    Dog dog("Rex");
    dog.print_info();

    log_data("Hello there ",LogType::MESSAGE);

    return 0;
}