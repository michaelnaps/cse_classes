# File: napoli_38_hw2.py
# Created by: Michael Napoli
# Created on: 5/21/2021

# Problem 1
# function for applying given conditions to a list of strings
def adj_string_list(s):
    return [word for word in str_list if len(word) <= 4]

# print('Problem 1')
# list of arbitrary words for testing
# str_list = ['test', 'test_', 'omitted', 'pie', 'michael', 'napoli', 'ava', 'jane']
# print(four_or_less(str_list))  # print string list


# Problem 2
# function for apply given conditions to a list of integers
def adj_integer_list(n):
    return [(10 + i ** 2) for i in n if not ((str(i ** 2)[-1] == str(5)) or (str(i ** 2)[-1] == str(6)))]

# print('\nProblem 2')
# int_list = [i for i in range(1, 16)]  # create array of integers from 1-15
# print(int_list)  # print integer list
# print([(i ** 2 + 10) for i in int_list])
# print(adj_integers(int_list))


# Problem 3
# maximum difference function
def largest_diff(num_list):
    # arbitrary intializations for loop variables
    max = num_list[1]  # initialized to first value in array
    min = num_list[-1]  # initialized to last value in array

    # for all values in given array
    for i in range(len(num_list)):
        if num_list[i] < min:  # if less than current minimum, replace
            min = num_list[i]
        if num_list[i] > max:  # if greater than current maximum, replace
            max = num_list[i]

    return (max - min)  # return the difference

# run some test cases
# print('\nProblem 3')
# print(largest_diff([1, 2, 3, 4, 5, 6, 7]))  # for ordered array
# print(largest_diff([1, 2, -3, 11, 18, 5]))  # for non-ordered array


# Problem 4
def equal_split(list):
    # loop that splits array at all applicable points and compares sums
    # skip first position (would cause problematic indexing)
    for i in range(len(list)):
        a_sum = [list[j] for j in range(i)]
        b_sum = [list[j] for j in range(i, len(list))]

        # if the sum of the first half is equal to that of the second, return True
        if sum(a_sum) == sum(b_sum):
            return True

    # if loop exits, return false (no equal split)
    return False

# run test cases
# print('\nProblem 4')
# print(equal_split([1, 3, 4, 8]))            # case where condition is true
# print(equal_split([8, 4, 4]))               # case where condition is true
# print(equal_split([100, 325, 175, 250]))    # case where condition is true
# print(equal_split([1, 2, 5]))               # case where condition is false
