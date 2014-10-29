---
layout: post
title: Linux Samba
---

{{ page.title }}
================

>yum install samba samba-client samba-common
>cd /etc/samba/
>mv smb.conf smb.confbak
>touch smb.conf

如下配置
>[global]     
>workgroup = LinuxSir
>netbios name = stevinwang
>server string = Linux Samba Server TestServer
>security = user
>[search]
>path = /search/
>writeable = yes
>browseable = yes 
>guest ok = yes

账户设置
>smbpasswd -a username

启动服务

windows下尝试访问

>如果失败chown一下
