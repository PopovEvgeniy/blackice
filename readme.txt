                        BLACK ICE

  Complex file cryptography tool(both encryption and decryption) by Popov Evgeniy Alekseyevich

                          Version 1.5.5

System requirement

Processor:Intel core 2 Duo or better.
1 megabyte of free RAM.
124 kilobytes free space on storage media.
Operation system: Unix(Any Unix like system) or Windows(Windows XP or better)

Program description

This program let you encrypt and decrypt your files. It uses the strong cryptography algorithm.

Some remarks about encryption and decryption

An encrypted file have twice size than original file. An decrypted file have normal size.
Output file will create before start encryption or decryption process.

Password limitation

Minimum password length is 2 character. Maximum password length is 255 character.

Command line arguments

This program takes 3 command line arguments: mode,password,target file name
The flags of mode: encrypt - encryption mode, decrypt - decryption mode

Exit codes

0 - Operation successfully complete
1 - Invalid password length
2 - Can't open input file
3 - Can't create output file
4 - Can't read data
5 - Can't write data
6 - Can't allocate memory
7 - Invalid cryptography container format
8 - Invalid mode flag

License

This program distributed under GNU GENERAL PUBLIC LICENSE.

Source code

The program source code was compiled under MINGW-w64. But you can do it under any modern C compiler.
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
4.Run as root: make install

Uninstall steps:

1.Extract content of source code archive.
2.Open terminal and go to source code directory.
3.Run as root: make uninstall

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
1.0.4 - 1.1.1 - Small changes.
1.1.2 - Memory usage was reduced.
1.1.3 - 1.1.4 - Small changes.
1.2 - Small changes in cryptography algorithm.
1.2.1 - Maximum password length was decreased.
1.2.2 - Small changes.
1.2.3 - 1.2.4 - Small bug in file decryption was fixed.
1.2.5 - Small changes.
1.3 - Small changes in cryptography algorithm.
1.3.1 - Small changes.
1.4 - 1.5 - Cryptography algorithm was changed.
1.5.1 - 1.5.4 - Small changes.
1.5.5 - Cryptography algorithm was changed.