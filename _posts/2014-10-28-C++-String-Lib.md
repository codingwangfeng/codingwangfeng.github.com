---
layout: post
title: C++ string lib
---

{{ page.title }}
================
<pre>
<code>
#include < string >
#include < vector >

using namespace::std;
/*
 * @brief delete space from two side of the string
 *  e.g.: ' abc    ' --> 'abc'
 * @param
 *  [in] str:input string to trim
 * @return the result of trim
 */
string trim(const string& str) {
    string::size_type start = str.find_first_not_of(' ');
    if (start == string::npos) {
        return str;
    }
    string::size_type end = str.find_last_not_of(' ');
    if (end != string::npos) {
        return str.substr(start, end - start + 1);
    }
    return str.substr(start);
}
</code>
</pre>
