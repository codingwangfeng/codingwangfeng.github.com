---
layout: post
title: Linux Samba
---

{{ page.title }}
================

>yum install samba
>cd /etc/samba/
>mv smb.conf smb.confbak
>touch smb.conf

如下配置写入
>[global]     
>workgroup = LinuxSir
>netbios name = stevinwang
>server string = Linux Samba Server TestServer
>security = user
> [search]
> path = /search/
> writeable = yes
> browseable = yes 
> guest ok = yes

启动服务
