#!/usr/bin/env python3
import itertools
import copy

five = list(itertools.permutations('ABCDE', 5))
for f in five:
    prob = list(f)
    ans_string = ""
    f_new = copy.deepcopy(f)
    if f[0] > f[1]:
        f_new[2] = f[1]
    else
        f_new[2] = f[0]
    if f[3] > f[4]:
        f_new[3] = f[3]
