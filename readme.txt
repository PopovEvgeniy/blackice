                        BLACK ICE

  Complex file cryptography tool(both encryption and decryption) by Popov Evgeniy Alekseyevich

                          Version 1.0.5

System requirement

2 megabytes of free RAM.
56 kilobytes free space on storage media.

Program description

This program let you encrypt and decrypt your files. It uses the strong cryptography algorithm.

Some remarks about encryption and decryption

An encrypted file have twice size than original file. Maximum size of original file is 4 terabytes.

Password limitation

Minimum password length is 2 character. Maximum password length is 258 character.

Command line arguments

This program takes 3 command line arguments: mode,password,target file name
The flags of mode: encrypt - encryption mode, decrypt - decryption mode
Output file will create before begin of encryption or decryption.

Exit codes

0 - Operation successfully complete
1 - Invalid password length
2 - Can't open input file
3 - Can't create output file
4 - Can't allocate memory
5 - Invalid cryptography container format
6 - Invalid mode flag

License

This program distributed under GNU GENERAL PUBLIC LICENSE.

Source code

The program source code was compiled under Open Watcom. But you can do it under any modern C compiler.
Source code can be compiled for wide range operation systems, but you need create makefile or build script by yourself.
I provide only two things: compiled binary file for Windows and makefile for Linux.

Some remarks about source code

Program source compatibility with any modern C compiler.
Open blackice.c file and check platform identifier before start compiling.

Installation and uninstall under Linux

Installation steps:

1.Extract content of source code archive.
2.Open blackice.c file and change platform identifier. Save changes.
3.Open terminal and go to source code directory.
4.Run: make install

Uninstall steps:

1.Extract content of source code archive.
2.Open terminal and go to source code directory.
3.Run: make uninstall

Contact

You can send me a letter to tuzik87@inbox.ru.

Thanks

What you need when you try create a big thing? A technical consultation. I need it too.
I want to say «Big thanks for technical consultation» to these peoples:

BlackBird
Astyanax
Uzix
FDDVORON
Nikodim
Oleq Pazdnikov

Version history

0.1 - Initial version.
0.2 - 0.8 - Small changes.
0.9 - Old Windows version support was dropped. Linux support was added. File size limit was increased.
0.9.1 - Small changes.
0.9.2 - Speed of cryptography algorithm was increased.
0.9.3 - Small bug has been fixed.
0.9.4 - 0.9.4.3 - Cryptography algorithm was changed.
0.9.5 - Processor usage was reduced.
0.9.6 - Memory usage was reduced.
0.9.6.1 - Processor usage was reduced.
0.9.6.2 - Small changes.
0.9.6.3 - Processor and memory usage was reduced.
0.9.6.4 - Small changes.
0.9.6.5 - A lot of internal changes.
0.9.6.6 - Small bug was fixed.
0.9.6.7 - 0.9.6.8 - Small changes.
0.9.6.9 - 0.9.8 - Cryptography algorithm was changed.
0.9.9 - 1.0.2 - Small changes.
1.0.3 - Program was speedup.
1.0.4 - 1.0.5 - Small changes.