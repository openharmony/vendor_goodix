#!/usr/bin/env python
# -*- coding: utf-8 -*-
# author: zhangqf
"""
This module use arm-none-eabi-xxx function to deal the xxx.elf file. we recept two parameters, and the 
format of the usage: bin_create.py input_file.elf  out_file.bin. Thanks for use this module
"""

import os
from os import path
import sys

def make_bin(input_file = "", output_file = ""):
    shell_script =  '''arm-none-eabi-size {src_file}
    arm-none-eabi-objdump -D {src_file} > {dst_file}.list
    arm-none-eabi-objcopy -O binary -S {src_file} {dst_file}'''.format(src_file = input_file, dst_file = output_file)
    cmd_output = os.system(shell_script)

    return   

if __name__ == "__main__":
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    make_bin(input_file = input_file, output_file = output_file)
