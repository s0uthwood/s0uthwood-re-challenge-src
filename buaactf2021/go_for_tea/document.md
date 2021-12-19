

# Go for Tea

## 题目描述

Go语言逆向

## 出题

flag格式： `flag{xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxxxxx}`

md5(Everyone loves orange)

加密流程：

- 从flag中提取v0 v1 u0 u1
- 简单的伪随机数算法生成key
- 进行两次xtea加密

build:

`go build -ldflags "-s" cup_of_tea.go`

## 官方WP

先还原符号化，看到输入的是四个数，直到加密部分前都和输入无关

直接动调拿key

进入加密部分，发现是小改过的xtea，求出最后的sum，然后做个求解