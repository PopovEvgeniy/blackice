#define BUFFER_LENGTH 1048576

typedef struct
{
 char signature[4];
 unsigned int extension;
} blackice_head;