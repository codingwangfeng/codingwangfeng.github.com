---
layout: post
title: C++ string lib
---

{{ page.title }}
================
<code>
<pre>
#include <string>
#include <vector>

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

/*
 * @brief like its name
 * @param
 *  [in] str input string
 *  [in] src replace from
 *  [out] dest replace to
 * @note
 *  e.g.: 
 *   string s1 = "hello world";
 *   string src = "hello";
 *   string dest = "hi";
 *   s1 = replace(s1, src, dest);
 *   output:
 *    s1:"hi world"
 */
string replace(const string& str, const string& src, const string& dest) {
    string ret;
    string::size_type pos_begin = 0;
    string::size_type pos = str.find(src);
    while (pos != string::npos) {
        ret.append(str.data() + pos_begin, pos - pos_begin);
        ret += dest;
        pos_begin = pos + 1;
        pos = str.find(src, pos_begin);
    }
    if (pos_begin < str.length()) {
        ret.append(str.begin() + pos_begin, str.end());
    }
    return ret;
}
</code>
</pre>
