#define BUFFER_LENGTH 4096

typedef struct
{
 char signature[4];
 unsigned int extension;
} blackice_head;