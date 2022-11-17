#include<iostream>
#include "dog.h"
#include "operations.h"
#include "log.h"

int main(){


    Dog dog("Rex");
    dog.print_info();

    log_data("Hello there  How are you doing ",LogType::MESSAGE);

    return 0;
}