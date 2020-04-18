import numpy
from scipy import stats
n=input()
a=[int(i) for i in input().split()]
print(numpy.mean(a))
print(numpy.median(a))
print(stats.mode(a)[0][0])
