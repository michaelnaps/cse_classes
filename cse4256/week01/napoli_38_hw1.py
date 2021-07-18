# File: napoli_38_hw1.py
# Created by: Michael Napoli
# Created on: 5/15/2021
# Due Date: 5/20/2021

# intialize the randoom number module
import random

print("\nProblem 1")
def prob1():
    # intialize guess counter
    guess_c = 1
    # initialize random number
    val = random.randrange(1, 101)
    # get initial guess from user
    guess = int(input("Enter a guess: "))
    # enter loop that iterates until user is correct
    while (guess != val):
        # check if guess is correct
        if (guess > val):
            print("To high.")
        else:
            print("To low.")
        # get a new guess
        guess = int(input("Enter another guess: "))
        #iterate guess count
        guess_c += 1;  # iterate count variable
    return guess_c  # return number of guesses

print(prob1())

print("\nProblem 2")
def prob2():
    # guess count (for checking that it is below 7)
    guess_c = 0
    # intial guess is always 50 (between 1 and 100)
    guess = 50
    # result intialized to begin 'while' loop
    result = "X"
    # range of potential values
    l = 1
    h = 100
    # use bisection method to solve for user's guess
    while (result != "C"):
        # output computer's guess
        print("I am guessing " + str(guess))
        # ask user if current guess is correct
        result = input("Enter L (Low), H (High) or C (Correct): ")
        # adjust range based on user input
        if (result == "L"):
            l = guess
        elif (result == "H"):
            h = guess
        elif (result == "C"):
            print("That is correct.")
        guess = int((l + h) / 2)  # divide range by two for next guess
        guess_c += 1  # iterate guess counter
    return guess_c  # return guess counter (for checking)

print(prob2())
