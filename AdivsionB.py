#!/usr/bin/env python
# coding=utf-8

#A除以B (20)
# 时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
# 题目描述
# 本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。
# 
# 输入描述:
# 输入在1行中依次给出A和B，中间以1空格分隔。
# 
# 
# 输出描述:
# 在1行中依次输出Q和R，中间以1空格分隔。
# 
# 输入例子:
# 123456789050987654321 7
# 
# 输出例子:
# 17636684150141093474 3
# from __future__ import division

tuple = raw_input().split(" ");
A = tuple[0]
B = tuple[1]

Q = long(A) / long(B)
R = long(A) - long(B) * Q

print Q, R
