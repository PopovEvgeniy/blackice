#define BUFFER_LENGTH 4096

typedef struct
{
 char signature[4];
 unsigned int extension:32;
} blackice_head;