//
//  cbase.cpp
//  Created by stevin on 2014-10-26
//  Copyright (c) 2014年 stevin. All rights reserved.
//

#include <iostream>
class CBase{
    public:
        CBase(){}
        ~CBase(){}
        virtual void printHello() {
            std::cout << "Hello" << std::endl;
        }

};
class CBase2{
    public:
        virtual void printHehe(){}
};
class CChild: public CBase, public CBase2{
    public:
        virtual void heh(){}
};
int main(int argc, char** argv) {
    std::cout << sizeof(CBase) << std::endl;
    std::cout << sizeof(CBase2) << std::endl;
    std::cout << sizeof(CChild) << std::endl;
    return 0;
}

