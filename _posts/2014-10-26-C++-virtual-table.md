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
