//
//  cbase.cpp
//  Created by stevin on 2014-10-26
//  Copyright (c) 2014年 stevin. All rights reserved.
//

#include <iostream>
#include <string.h>
class Base{
    public:
        virtual void v(){};
};

class SonA : public Base{ };
class SonB : public Base{ };
class MyClass : public SonB, public SonA{};
int main(int argc, char** argv) {
    std::cout << sizeof(MyClass) << std::endl;
    std::cout << sizeof(Base) << std::endl;
    std::cout << sizeof(Son) << std::endl;
    return 0;
}

