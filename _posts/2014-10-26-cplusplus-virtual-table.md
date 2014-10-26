---
layout:post
title:cplusplus virtual table
---

{{ page.title }}
================

##概念
来个例子
<pre>
<code>class CBase {
    public:
        CBase(){}
        virtual ~ CBase(){}
        virtual void v1(){
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
int main(int argc, char** argv) {
    call(new CBase());
    call(new CChild());
    return 0;
}</code>
</pre>
输出
<pre><code>CBase::v1
CChild::v1
</code></pre>

虚函数表是一种支持C++多态的机制。
当一个类定义一个虚函数的时候，多数编译器会生成一个隐藏的变量，这个变量是一个指向这个虚函数表（VMT/VTable）的指针。
这个VTable本质是虚函数指针数组，虚函数表地址在类开头，这是为了能够更高效获取虚函数？
<pre>
<code>
class CBase {
    public:
        virtual void v1(){
            std::cout << "CBase::" << __func__ << std::endl;
        }
        virtual void v2(){
            std::cout << "CBase::" << __func__ << std::endl;
        }
        virtual void v3(){
            std::cout << "CBase::" << __func__ << std::endl;
        }
};
typedef void(*Fun)(void);
int main(int argc, char** argv) {
    CBase b;
    int* vtableAddr = (int*)&b;
    Fun f = NULL;
    std::cout << "VTable addr:" << vtableAddr << std::endl;
    f = (Fun)*((int*)*vtableAddr);
    std::cout << "VTable addr:" << (int*)*vtableAddr+0 << std::endl;
    f();
    f = (Fun)*((int*)*vtableAddr+2);
    std::cout << "VTable addr:" << (int*)*vtableAddr+2 << std::endl;
    f();
    f = (Fun)*((int*)*vtableAddr+4);
    std::cout << "VTable addr:" << (int*)*vtableAddr+4 << std::endl;
    f();
    return 0;
}
output:
VTable addr:0x7fff02e24580
VTable addr:0x400c70
CBase::v1
VTable addr:0x400c78
CBase::v2
VTable addr:0x400c80
CBase::v3
</code>
</pre>
##多重继承中
* 每个父类都有自己的虚表。
* 子类的成员函数被放到了第一个父类的表中。
* 内存布局中，其父类布局依次按声明顺序排列。
* 每个父类的虚表中的f()函数都被overwrite成了子类的f()。这样做就是为了解决不同的父类类型的指针指向同一个子类实例，而能够调用到实际的函数。

