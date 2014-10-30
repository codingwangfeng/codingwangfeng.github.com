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
/*
 * @brief split a string into vector by sep
 * @param 
 *  [in] str:input string to split
 *  [in] sep:input seperator 
 *  [out] ret_: the result of split
 */
void split(const string& str, vector<string>& ret_, string sep = " ") {
    if (str.empty()) {
        return ;
    }
    string tmp;
    string::size_type pos_begin = str.find_first_not_of(sep);
    string::size_type comma_pos = 0;

    while (pos_begin != string::npos) {
        comma_pos = str.find(sep, pos_begin);
        if (comma_pos != string::npos) {
            tmp = str.substr(pos_begin, comma_pos - pos_begin);
            pos_begin = comma_pos + sep.length();
        } else {
            tmp = str.substr(pos_begin);
            pos_begin = comma_pos;
        }

        if (!tmp.empty()) {
            ret_.push_back(tmp);
            tmp.clear();
        }
    }
}
</code>
</pre>
