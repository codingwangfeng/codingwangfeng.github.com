//
//  vtable.cpp
//  Created by stevin on 2014-10-26
//  Copyright (c) 2014年 stevin. All rights reserved.
//

#include <iostream>
#include <string.h>
class CBase {
    public:
        CBase(){}
        ~ CBase(){}
        virtual void v1(){
            std::cout << "CBase::" << __func__ << std::endl;
        }
        virtual void v2(){
            std::cout << "CBase::" << __func__ << std::endl;
        }
};
class CChild: public CBase {
    public:
        virtual void v1(){
            std::cout << "CChild::" << __func__ << std::endl;
        }
};
void call(CBase* b){
    b->v1();
}
typedef void(*Fun)(void);
int main(int argc, char** argv) {
    CBase b;
    int* vtableAddr = (int*)&b;
    Fun f = NULL;
    std::cout << "VTable addr:" << std::hex << vtableAddr << std::endl;
    std::cout << "VTable 1st Func addr:" << std::hex << *vtableAddr << std::endl;
    std::cout << "sizeof(Fun)" << std::hex << sizeof(Fun) << std::endl;
    f = (Fun)*((int*)*vtableAddr);
    f();
    f = (Fun)*((int*)*vtableAddr+2);
    f();
    return 0;
}

