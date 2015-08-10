#!/bin/sh -x

#  Author : stevin
#    File : commit.sh
#    Date : 2014年11月 2日 星期日 16时27分00秒 CST
# History : 1.created on 2014年11月 2日 星期日 16时27分00秒 CST by

set -e
git add $1
git commit -m "$2"
git push origin master
