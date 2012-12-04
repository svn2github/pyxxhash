#!/usr/bin/env python
# -*- coding: utf-8 -*-
import pyxxhash
char ="a"
n=19
for i in range(n):
    data=char *(i+1)
    print " %-20s %-s 0 %-10d " %(data,' ',pyxxhash.fast32(data,len(data),0))

