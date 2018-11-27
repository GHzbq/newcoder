# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        # write code here
        if len(array) == 0 or len(array) == 1:
            return array;
        length = len(array) # array length
        even_point = odd_point = 0
        while odd_point < length:
            if array[odd_point] % 2 == 1:
                tmp = array[odd_point]
                for i in range(odd_point, even_point, -1):
                    array[i] = array[i - 1]
                array[even_point] = tmp
                odd_point += 1
                even_point += 1
            else:
                odd_point += 1
        return array
