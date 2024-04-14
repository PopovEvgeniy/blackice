#define BUFFER_LENGTH 4096

typedef struct
{
 char signature[4];
 unsigned long int extension:4;
} blackice_head;