---
layout: post
title: C++ virtual table
---

{{ page.title }}
================

##概念
来个例子
<pre>
<code>
class CBase {
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
}
</code>
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
</code>
</pre>

