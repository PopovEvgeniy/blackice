                        BLACK ICE

  The complex file cryptography tool (both encryption and decryption) by Popov Evgeniy Alekseyevich

                          Version 2.0.6

System requirements.

1 megabyte of free RAM.
Operating system: Unix (any Unix-like system) or Windows (Windows 2000 or higher).

The program description.

This program lets you encrypt and decrypt your files. It uses a custom cryptography algorithm.

Some remarks about encryption and decryption.

An encrypted file is twice the size of the original file. A decrypted file has a normal size.
The output file will be created if needed.

The password limitation.

The minimum password length is 2 characters. The maximum password length is 255 characters.

The command-line arguments.

This program takes 3 command-line arguments: the mode, a password, and a file name.
The modes are: encrypt - encryption mode, decrypt - decryption mode.

Exit codes.

0: The operation was successfully completed.
1: The password length is invalid.
2: Can't open the input file.
3: Can't create the output file.
4: Can't read data.
5: Can't write data.
6: Can't allocate memory.
7: The invalid format.
8: The invalid mode.

License.

This program is distributed under the GNU GENERAL PUBLIC LICENSE.

The source code.

The code was compiled under Tiny C Compiler. But you can do it with any modern C compiler.
The source code can be compiled for a wide range of operating systems, but you need to create a makefile or a build script by yourself.
I provide only two things: the binary file for Windows and the makefile for Linux.

Install and uninstall under Linux.

Follow these steps:

1. Extract the content of the source code archive.
2. Open a terminal and go to the source code directory.
3.
Run as root for install: make install
Run as root for uninstall: make uninstall

Thanks.

I want to say <Big thanks for the technical consultation> to these people:

BlackBird
Astyanax
Uzix
FDDVORON
Nikodim
Oleq Pazdnikov

Version history.

0.1: The initial version.
0.2-0.8: The small changes.
0.9: The old versions of Windows support have been dropped. Linux support has been added. The file size limit has increased.
0.9.1: The small changes.
0.9.2: The speed of the cryptography algorithm has increased.
0.9.3: The small bug has been fixed.
0.9.4-0.9.4.3: The cryptography algorithm has been changed.
0.9.5: The processor usage has been reduced.
0.9.6: The memory usage has been reduced.
0.9.6.1: The processor usage has been reduced.
0.9.6.2: The small changes.
0.9.6.3: The processor and memory usage have reduced.
0.9.6.4: The small changes.
0.9.6.5: A lot of internal changes.
0.9.6.6: A small bug has been fixed.
0.9.6.7-0.9.6.8: The small changes.
0.9.6.9-0.9.8: The cryptography algorithm has been changed.
0.9.9-1.0.2: The small changes.
1.0.3: The program was sped up.
1.0.4-1.1.1: The small changes.
1.1.2: The memory usage has been reduced.
1.1.3-1.1.4: The small changes.
1.2: The small changes in the cryptography algorithm.
1.2.1: The maximum password length has decreased.
1.2.2: The small changes.
1.2.3-1.2.4: The small bug in the file decryption has been fixed.
1.2.5: The small changes.
1.3: The small changes in the cryptography algorithm.
1.3.1: The small changes.
1.4-1.5: The cryptography algorithm has been changed.
1.5.1-1.5.4: The small changes.
1.5.5: The cryptography algorithm has been changed.
1.5.5.1: The source code was recompiled under Open Watcom V2 Fork.
1.5.6-1.6: The performance has improved.
1.6.1-1.6.2: The small changes.
1.6.2.1: The makefile has been updated.
1.6.3-1.7: The small changes.
1.7.1: The minor changes in the cryptography algorithm.
1.7.2: The small changes.
1.7.3: Unix-specific improvement: the processor usage has been reduced.
1.7.4-1.7.8: The small changes.
1.7.9: Visual C++ support has improved.
1.8-1.8.3: The small changes.
1.8.4: A small bug has been fixed.
1.8.5-1.8.6: The small changes.
1.8.5.1: The documentation has been updated.
1.8.7: The small changes.
1.8.7.1-1.8.7.2: The documentation has been updated.
1.8.8: The source code was recompiled under Tiny C Compiler.
1.8.9: The small changes in the cryptography algorithm.
1.9-1.9.4: The small changes.
1.9.5: The small changes in the cryptography algorithm.
1.9.6: The small changes.
1.9.7-2.0: The small changes in the cryptography algorithm.
2.0.1: The code portability has improved.
2.0.1.1: The documentation has been updated.
2.0.2-2.0.3: The small changes.
2.0.3.1-2.0.3.3: The documentation has been updated.
2.0.4: The small changes.
2.0.5: The small changes in the cryptography algorithm.
2.0.6: The small changes.