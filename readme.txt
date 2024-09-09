                        BLACK ICE

  Complex file cryptography tool (both encryption and decryption) by Popov Evgeniy Alekseyevich

                          Version 1.8.6.1

System requirement

1 megabyte of free RAM.
72 kilobytes of free space on storage media.
Operating system: Unix (any Unix-like system) or Windows (Windows NT 4.0 or higher)

Program description

This program lets you encrypt and decrypt your files. It uses the strong cryptography algorithm.

Some remarks about encryption and decryption

An encrypted file has twice the size of the original file. A decrypted file has a normal size.
An output file will be created before starting the encryption or decryption process.

Password limitation

Minimum password length is 2 characters. Maximum password length is 255 characters.

Command line arguments

This program takes 3 command line arguments: mode,password,target file name
The flags of mode: encrypt- encryption mode, decrypt - decryption mode

Exit codes

0 - Operation successfully completed
1 - Invalid password length
2 - Can't open input file
3 - Can't create output file
4 - Can't read data
5 - Can't write data
6 - Can't allocate memory
7 - Invalid cryptography container format
8 - Invalid mode flag

License

This program is distributed under GNU GENERAL PUBLIC LICENSE.

Source code

The code was compiled under Open Watcom V2 Fork. But you can do it under any modern C compiler.
Source code can be compiled for a wide range of operating systems, but you need to create a makefile or build script by yourself.
I provide only two things: the binary file for Windows and makefile for Linux.

Installation and uninstall under Linux

Installation steps:

1. Extract the content of the source code archive.
2. Open a terminal and go to the source code directory.
3. Run as root: make install

Uninstall steps:

1. Extract the content of the source code archive.
2. Open a terminal and go to the source code directory.
3. Run as root: make uninstall

Contact

You can send me a letter at tuzik87@inbox.ru.

Thanks

I want to say «Big thanks for technical consultation» to these people:

BlackBird
Astyanax
Uzix
FDDVORON
Nikodim
Oleq Pazdnikov

Version history

0.1 — Initial version.
0.2 — 0.8 — Small changes.
0.9 — Old Windows version support has been dropped. Linux has been support added. File size limit increased.
0.9.1 — Small changes.
0.9.2 — Speed of cryptography algorithm increased.
0.9.3 — Small bug fixed.
0.9.4 — 0.9.4.3 — Cryptography algorithm changed.
0.9.5 — Processor usage reduced.
0.9.6 — Memory usage reduced.
0.9.6.1 — Processor usage reduced.
0.9.6.2 — Small changes.
0.9.6.3 — Processor and memory usage reduced.
0.9.6.4 — Small changes.
0.9.6.5 — A lot of internal changes.
0.9.6.6 — Small bug fixed.
0.9.6.7 — 0.9.6.8 — Small changes.
0.9.6.9 — 0.9.8 — Cryptography algorithm has been changed.
0.9.9 — 1.0.2 — Small changes.
1.0.3 — Program was speedup.
1.0.4 — 1.1.1 — Small changes.
1.1.2 — Memory usage reduced.
1.1.3 — 1.1.4 — Small changes.
1.2 — Small changes in cryptography algorithm.
1.2.1 — Maximum password length decreased.
1.2.2 — Small changes.
1.2.3 — 1.2.4 — Small bug in file decryption fixed.
1.2.5 — Small changes.
1.3 — Small changes in cryptography algorithm.
1.3.1 — Small changes.
1.4 — 1.5 — Cryptography algorithm changed.
1.5.1 — 1.5.4 — Small changes.
1.5.5 — Cryptography algorithm changed.
1.5.5.1 — Source code recompiled under Open Watcom V2 Fork.
1.5.6 — 1.6 — Performance improved.
1.6.1 — 1.6.2 — Small changes.
1.6.2.1 — Makefile update.
1.6.3 — 1.7 — Small changes.
1.7.1 —  Minor changes in cryptography algorithm.
1.7.2 — Small changes.
1.7.3 — Unix specific improvement: processor usage reduced.
1.7.4 — 1.7.8 — Small changes.
1.7.9 — Visual C++ support improved.
1.8 — 1.8.3 — Small changes.
1.8.4 — Small bug fixed.
1.8.5 — 1.8.6 — Small changes.
1.8.6.1 — Documentation update.