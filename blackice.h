#if defined _MSC_VER && _MSC_VER>=1400
  #pragma warning(disable : 4996)
#endif

#ifndef _WIN32
#define _LARGEFILE64_SOURCE
#define _FILE_OFFSET_BITS 64
#define __USE_FILE_OFFSET64
#endif

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define DIRECTORY_SEPARATOR '\\'
#define file_seek _fseeki64
#define file_tell _ftelli64
#else
#define DIRECTORY_SEPARATOR '/'
#define file_seek fseeko
#define file_tell ftello
#endif