#define BUFFER_LENGTH 2048

#ifdef _WIN32
#define INPUT_FILE_MODE O_RDONLY|O_BINARY
#define OUTPUT_FILE_MODE O_CREAT|O_WRONLY|O_BINARY
#define file_seek _lseeki64
#else
#define _LARGEFILE64_SOURCE
#define INPUT_FILE_MODE O_RDONLY|O_LARGEFILE
#define OUTPUT_FILE_MODE O_CREAT|O_WRONLY|O_LARGEFILE
#define file_seek lseek64
#endif

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>