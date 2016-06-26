#! /usr/bin/python3.4

import re
import os
import urllib

# ********************************************************
# CS 200 HW #2  DUE Thursday, 2/18/2016 at 11:59 pm
#                via the submit system on the Zoo
# EXTENSION     DUE Monday, 2/22/2016 at 11:59 pm
# ********************************************************
# Name:
# Email address:
# ********************************************************

# This file may be opened in python 3
# Lines beginning with hashes are comments.

# If you are asked to write a procedure, please make sure it has 
# the specified name, and the specified number and order of arguments.  
# The names of the formal arguments need not be the same
# as in the problem specification.

# For each problem, the intended inputs to your procedures
# are specified (for example, "positive integers") 
# and your procedures need not do anything reasonable 
# for other possible inputs.

# You may write auxiliary procedures in addition to
# the requested one(s) -- for each of your auxiliary 
# procedures, please include a comment explaining
# what it does, and giving an example or two.

# You may also use procedures you have written 
# elsewhere in this assignment or previous assignments.
# They only need to be defined once somewhere within this file.

# Reading: Google Python Class

# ********************************************************
# ** problem 0 ** (1 easy point) 
# Replace the number 0 in the definition below to indicate
# the number of hours you spent doing this assignment
# Decimal numbers (eg, 6.237) are fine.  Exclude time
# spent reading.

def hours():
    return 0

# ********************************************************
# ** problem 1 ** (9 points)
# Write a procedure

# sumtree(tree)

# that takes a nested list tree and returns the sum of integers in the leaves
# you may assume that all the leaves are integers

# Examples
# sumtree([1, 2, 3]) => 6
# sumtree([1, [2, [3]]]) => 6
# sumtree([[[]]]) => 0
# sumtree([[[[2]]]]) => 2

# ********************************************************
def sumtree(tree):
    pass
		

# Replace the pass statement with your procedure(s).

## You can trace recursive functions using the following code:
def trace(f):
    f.indent = 0
    def g(x):
        print('|  ' * f.indent + '|--', f.__name__, x)
        f.indent += 1
        value = f(x)
        print('|  ' * f.indent + '|--', 'return', repr(value))
        f.indent -= 1
        return value
    return g

# for example, the folling turns on trace for your sumtree procedure
#  see the fib example from class.  /c/cs200/hws/fib.py
sumtree = trace(sumtree)


# ********************************************************
# ** problem 2 ** (10 points)
# Write a procedure

# doubletree(tree)

# that takes a nested list tree and returns another tree with the same 
# structure, but with each element doubled
# you may assume that all the leaves are integers

# Examples

# doubletree([1, 2, 3]) => [2,4,6]
# doubletree([1, [2, [3]]]) => [2, [4, [6]]]
# doubletree([]) => []
# doubletree([[[[8, 8, 8]]]]) => [[[[16, 16, 16]]]]

# ********************************************************

def doubletree(tree):
    pass

# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 3 ** (10 points)
# Write a procedure

# largesttree(tree)

# which takes a nested list tree and returns the largest number among
# the leaves
# you may assume that all the leaves are integers

# Examples
# largesttree([1, 2, 3, 4, 5]) => 5
# largesttree([]) => None
# largesttree([1, [2, [3, [4, [5]]]]]) => 5
# largesttree([[[[[3]]]]]) => 3


# ********************************************************

def largesttree(tree):
    pass

# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 4 ** (10 points)
# Write a procedure

# allsametree(tree)

# that takes a nested list tree of n elements and returns True if
# the leaf elements are identical, else it returns False
# Note: leaf nodes may not always be integers

# Examples:

# allsametree([1, 1, 1, 1]) => True
# allsametree([1, 2, 3]) => False
# allsametree([]) => True
# allsametree([1, [1, [1, [1]]]])  => True
# allsametree([1, [[[[[2]]]]]]) => False
# allsametree(['a', 'a', 'a']) => True
# allsametree(['a', 'b', 'c']) => False

# ********************************************************

def allsametree(tree):
    pass
# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 5 ** (10 points)
# Write a procedure

# alldifferenttree(tree)

# that takes a nested list tree and returns True if all the leaf elements
# of the tree are different.
# Note: leaf nodes may not always be integers

# Examples

# alldifferenttree([1, 1, 1, 1]) => False
# alldifferenttree([1, [2, [3, [4]]]])  => True
# alldifferenttree([]) => True
# alldifferenttree([[[[[[9]]]]]]) => True
# alldifferenttree(['a', 'a', 'a']) => False
# alldifferenttree(['a', 'b', 'c']) => True

# ********************************************************
def alldifferenttree(tree):
    pass
# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 6 ** (10 points)
# Write a procedure

# cull(pred,lst)

# that takes a predicate pred and a list lst and returns a new list
# of two lists: the first list comprises the elements that satisfy
# pred, and the second list comprises elements that do not.

# Examples:

def iseven(n): return n % 2 == 0
def isodd(n): return n % 2
def isstring(s): return isinstance(s, str)

# cull(iseven, [1, 2, 3, 4, 5, 6]) => [[2, 4, 6], [1, 3, 5]]
# cull(isstring, [1, 2, 'a', 'b', 3, 3, 'd', 'e']) => [['a', 'b', 'd', 'e'], [1, 2, 3, 3]]
# cull(iseven, [2, 4, 6]) => [[2, 4, 6], []]
# cull(isodd, [2, 4, 6]) => [[] [2, 4, 6]]
# cull(lambda x: x > 3, [2, 4, 6]) => [[2, 4, 6], []]
# cull(isodd, []) => [[], []]

# ********************************************************
def cull(pred, lst):
    pass

# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 7 ** (10 points)
# Write a procedure 

# treeaverage(tree)

# that takes a nested list tree whose leaf nodes are integers 
# and returns the average of those integers.

# See if you can have your code traverse the data only once.

# Examples:

# treeaverage([1, 2, 3]) => 2
# treeaverage([1, [2, [3]]])  => 2
# treeaverage([]) => 0
# treeaverage([[[[[[[7]]]]]]]) => 7
# treeaverage([[[[[[[]]]]]]]) => 0

# ********************************************************
def treeaverage(tree):
	pass
 
# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 8 ** (10 points)
# Write the procedure

# countpat(file, pat)

# which reads the given file and returns the number of times
# that the pattern pat matches in the file.

# Examples:

# countpat('/usr/share/dict/words', '^...$') => 6221
# countpat('/usr/share/dict/words', '^.$') => 53
# countpat('/usr/share/dict/words', '^[aeiou].*[aeiou]$') => 17784
# countpat('/usr/share/dict/words', '^[aeiou]+$') => 29
# countpat('/usr/share/dict/words', '^[^aeiou]+$') => 7843

# ********************************************************

def countpat(file, pat):
    pass
# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 9 ** (10 points)
# Write the procedure

# biggest_file(dir) 

# which finds the largest file in the given directory

# Examples:

# biggest_file('/usr/share/dict') => 'linux.words'
# biggest_file('/usr') => 'lib64'
# biggest_file('/usr/share/dictxx') => '*** error reading /usr/share/dictx'

## Hint: the google python class uses the commands module which
# is not supported in Python 3.  Instead, you may use:
# os.system() 
# and redirect its output to a tmp file (e.g., /tmp/foo) , 
# which you then read and remove.

# there are many other ways of approaching this problem.

# ********************************************************

def biggest_file(dir):
    pass
# Replace the pass statement with your procedure(s).

# ********************************************************
# ** problem 10 ** (10 points)
# Write the procedure

# counttags(url, nodups=False) 

# count the number of links in a web page
# with or without duplicates

# If nodups is False (the default value) you include duplicates
# If nodups is True, you count only unique instances.

# Examples:

# counttags('http://www.yale.edu/') => 133
# counttags('http://www.yale.edu/', True) => 133
# counttags('http://zoo.cs.yale.edu/classes/cs200/index.html') => 20
# counttags('http://zoo.cs.yale.edu/classes/cs200/index.html', True) => 19


# ********************************************************
def counttags(url, nodups=False):
    pass
# Replace the pass statement with your procedure(s).

# ********************************************************


### test function from google python course
### =======================================
# Provided simple test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def test(got, expected):
    if (hasattr(expected, '__call__')):
        OK = expected(got)
    else:
        OK = (got == expected)
    if OK:
        prefix = ' OK '
    else:
        prefix = '  X '
    print ('%s got: %s expected: %s' % (prefix, repr(got), repr(expected)))


# Provided main() calls the above functions with interesting inputs,
# using test() to check if each result is correct or not.
def main():
  print ('hours')
  print('# is it greater than 0?')
  test(hours(), lambda x: x > 0)

  print ('sumtree')
  test(sumtree([1, 2, 3]), 6)
  test(sumtree([1, [2, [3]]]), 6)
  test(sumtree([[[]]]), 0)
  test(sumtree([[[[2]]]]), 2)

  print ('doubletree')
  test(doubletree([1, 2, 3]), [2,4,6])
  test(doubletree([1, [2, [3]]]), [2, [4, [6]]])
  test(doubletree([]), [])
  test(doubletree([[[[8, 8, 8]]]]), [[[[16, 16, 16]]]])

  print ('largesttree')
  test(largesttree([1, 2, 3, 4, 5]), 5)
  test(largesttree([]), None)
  test(largesttree([1, [2, [3, [4, [5]]]]]), 5)
  test(largesttree([[[[[3]]]]]), 3)

  print ('allsametree')
  test(allsametree([1, 1, 1, 1]), True)
  test(allsametree([1, 2, 3]), False)
  test(allsametree([]), True)
  test(allsametree([1, [1, [1, [1]]]]) , True)
  test(allsametree([1, [[[[[2]]]]]]), False)
  test(allsametree(['a', 'a', 'a']), True)
  test(allsametree(['a', 'b', 'c']), False)

  print ('alldifferent')
  test(alldifferenttree([1, 1, 1, 1]), False)
  test(alldifferenttree([1, [2, [3, [4]]]]) , True)
  test(alldifferenttree([]), True)
  test(alldifferenttree([[[[[[9]]]]]]), True)
  test(alldifferenttree(['a', 'a', 'a']), False)
  test(alldifferenttree(['a', 'b', 'c']), True)

  print ('cull')
  test(cull(iseven, [1, 2, 3, 4, 5, 6]), [[2, 4, 6], [1, 3, 5]])
  test(cull(isstring, [1, 2, 'a', 'b', 3, 3, 'd', 'e']), [['a', 'b', 'd', 'e'], [1, 2, 3, 3]])
  test(cull(iseven, [2, 4, 6]), [[2, 4, 6], []])
  test(cull(isodd, [2, 4, 6]), [[], [2, 4, 6]])
  test(cull(lambda x: x > 3, [2, 4, 6]), [[4, 6], [2]])
  test(cull(isodd, []), [[], []])

  print ('treeaverage')
  test(treeaverage([1, 2, 3]), 2)
  test(treeaverage([1, [2, [3]]]) , 2)
  test(treeaverage([]), 0)
  test(treeaverage([[[[[[[7]]]]]]]), 7)
  test(treeaverage([[[[[[[]]]]]]]), 0)

  print ('countpat')
  test(countpat('/usr/share/dict/words', '^...$'), 6221)
  test(countpat('/usr/share/dict/words', '^.$'), 53)
  test(countpat('/usr/share/dict/words', '^[aeiou].*[aeiou]$'), 17784)
  test(countpat('/usr/share/dict/words', '^[aeiou]+$'), 29)
  test(countpat('/usr/share/dict/words', '^[^aeiou]+$'), 7843)

## compare with:
## grep '^...$' /usr/share/dict/words

  print ('biggest_file')
  test(biggest_file('/usr/share/dict'), 'linux.words')
  test(biggest_file('/usr'), 'lib64')
  test(biggest_file('/usr/share/dictx'), '*** error reading /usr/share/dictx')

  print ('counttags')
  test(counttags('http://www.yale.edu/'), 133)
  test(counttags('http://www.yale.edu/', True), 113)
  test(counttags('http://zoo.cs.yale.edu/classes/cs200/index.html'), 20)
  test(counttags('http://zoo.cs.yale.edu/classes/cs200/index.html', True), 19)

# Standard boilerplate to call the main() function.
if __name__ == '__main__':
  main()



# ********************************************************
# **** end of hw #2
