---
layout: post
title: 随机算法、洗牌算法
---

h1. 随机算法

h2. n个数中随机选出m个数。

思路：
<pre>
<code>
template<class T>
bool GetRandOf(const std::vector<T> vtrSrcData, int m, std::vector<T>& vtrRandRslt)
{
    int32_t nSize = vtrSrcData.size(), nIdx = 0;
    if(nSize  < m || m < 0)
        return false;
    vtrRandRslt.clear();
    vtrRandRslt.reserve(m);
    for(int32_t i = 0; i < m; i++){
        nIdx = nrand()%nSize;
        vtrRandRslt.push_back(vtrSrcData[nIdx]);
        swap(vtrSrcData[nIdx], vtrSrcData[nSize-1]);
        m --;
        nSize --;
    }
    return true;
}
</code>
</pre>
代码较少，逻辑不赘述。
原理的话，推到前两个即可知道。

