#define BUFFER_LENGTH 1024

typedef struct
{
 char signature[4];
 unsigned long int extension:4;
} blackice_head;