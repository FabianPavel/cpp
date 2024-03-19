#include <iostream>
#include "retezec.h"

int main() {
    // Testování třídy Retezec
    Retezec str1("Hello");
    Retezec str2(" world!");
    Retezec str3 = str1 + str2; // Test operátoru +

    std::cout << "str1: " << str1.ZiskatObsah() << std::endl;
    std::cout << "str2: " << str2.ZiskatObsah() << std::endl;
    std::cout << "str3: " << str3.ZiskatObsah() << std::endl;

    return 0;
}