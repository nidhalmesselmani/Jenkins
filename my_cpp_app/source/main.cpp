#include<iostream>
#include "dog.h"
#include "operations.h"
#include "log.h"

int main(){
    double result = add(2,70);
    auto testCpp20 = (10 <=> 20) > 0;
    std::cout << testCpp20 << "\n";

    if (testCpp20)
        std::cout << "10 > 20\n";
    else
        std::cout << "10 < 20\n";
    std::cout << "result : " << result << std::endl;

    Dog dog("Rex");
    dog.print_info();

    log_data("Hello there  How are you doing ",LogType::MESSAGE);

    return 0;
}