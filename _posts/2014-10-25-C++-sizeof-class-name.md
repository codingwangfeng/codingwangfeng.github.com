---
layout: post
title: \[C++\] sizeof classname
---

{{ page.title }}
================

注意这里是研究对象，不是内存管理，把简单事情搞复杂就是为了搞的更清楚。
###类成员函数不影响sizeof大小
所谓成员函数只是名义上的，实际上**成员函数并不存储在类的对象里边**，各个对象共享一段函数代码.
不在对象里，那如何访问呢？
####数据与代码
系统为每个对象分配空间，那么类中的数据和函数在对象中是如何分布的呢？
可能你眼中的C++对象与其函数和数据的关系：
<pre>
<code>
+------++------++------+ 
| data || data || data |
+------++------++------+
| func || func || func |
+------++------++------+
</pre>
</code>

可是实际上：
<pre>
<code>
+------+ +------+ +------+
|      | |      | |      |
| data | | data | | data |
|      | |      | |      |
+------+ +------+ +------+
+------+-----------------+
|           func         |
+------------------------+
</pre>
</code>

**因此每个对象所占用空间是其数据成员的空间，注意这里static不算是对象的空间**
<pre>
<code>
class CBase {
    public:
        CBase(){}
        ~CBase(){}
        void printHello() {
            std::cout << "Hello" << std::endl;
        }
    private:
        int nCount;
        char ch;
};
</code>
</pre>
因此sizeof CBase 大小是 sizeof int + sizeof char = 5
问题来了，相同代码段，如何操作不同对象的数据？
各对象有自己的this指针，
<pre><code>
CBase b;
b.printHello();
</pre></code>
### sizeof(ClassName)大小
#### 无数据成员情况
<pre>
<code>
class CBase{};
</code>
</pre>
sizeof(CBase) == 1;
难道不应该是0么？**c++每个实例在内存中都有一个独一无二的地址** empty class也可以实例化，那么他就会有独一无二的地址，如何保证独一无二地址，有大小。
#### 成员如何计算大小
* 指针，就是size_t大小
* 非指针数据成员，就是sizeof其本身
* static 自然不计算在内
#### 虚函数情况
<pre>
<code>
class CBase{
    public:
        CBase(){}
        ~CBase(){}
        virtual void printHello() {
            std::cout << "Hello" << std::endl;
        }

};
</code>
</pre>
sizeof(CBase) == 8;
因为有虚函数，故会生一个虚函数表指针vptr，64bits机器大小为8
<pre>
<code>
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
};
int main(int argc, char** argv) {
    std::cout << sizeof(CBase) << std::endl;
    std::cout << sizeof(CBase2) << std::endl;
    std::cout << sizeof(CChild) << std::endl;
    return 0;
}
</code>
</pre>
输出：
<pre>
<code>
8 
8
16
</code>
</pre>
**子类为每个父类准备独立的虚函数表，子类的函数放到第一个父类中**
#### 考虑对齐情况
<pre>
<code>
#include &lt;iostream>
class CBase{
    public:
        CBase(){}
        ~CBase(){}
        virtual void printHello() {
            std::cout << "Hello" << std::endl;
        }

};
class CChildChar: public CBase{
    private:
        char ch;
};
class CChildInt: public CBase{
    private:
        int i;
};
class CChildPtr: public CBase{
    private:
        int* i;
};
int main(int argc, char** argv) {
    std::cout << sizeof(CChildChar) << std::endl;
    std::cout << sizeof(CChildInt) << std::endl;
    std::cout << sizeof(CChildPtr) << std::endl;
    return 0;
}
</code>
</pre>
64bits机器输出结果
<pre><code>
16 
16
16
</code>
</pre>
三者者都集成了CBase会有一个虚函数表，大小为8，这一点很明确
三者各自有一个成员char和int和char*，大小分别为1和4和8.
**这是因为为了提高类的存取速度，类的大小往往被调整到系统的整数倍**

