# File: napoli_38_hw2.py
# Created by: Michael Napoli
# Created on: 5/21/2021

# import necessary directories
import numpy

# Problem 1
# create string list
str_list = ['test', 'test1', 'omitted', 'pie', 'michael', 'napoli', 'ava', 'jane']
n_str_list = [word for word in str_list if len(word) <= 4]
print(n_str_list)

# Problem 2
# create integer list
int_list = [i ** 2 for i in range(1, 11) if not ((str(i ** 2)[-1] == str(5)) or (str(i ** 2)[-1] == str(6)))]
print(int_list)
