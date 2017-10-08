/*
Available platform identfer
MS_WINDOWS - 32 bit Microsoft Windows and 64 bit Microsoft Windows
UNIX_32 - 32 bit Unix like system
UNIX_64 - 64 bit Unix like system
*/
#define MS_WINDOWS
#include "format.h"
#include "blackice.h"

void show_intro();
void command_line_help();
void show_start_message();
void show_end_message();
void show_progress(const long long int start,const long long int end);
void check_memory(void *memory);
int open_input_file(const char *name);
int create_output_file(const char *name);
long long int get_file_size(int target);
long long int file_tell(int target);
char *get_string_memory(const unsigned long int length);
unsigned long int get_extension_position(const char *source);
char *get_short_name(const char *name);
char* get_name(const char *name,const char *ext);
char *get_extension(const char *name);
blackice_head read_head(int target);
void write_container_data(int target,const char *extension);
void check_password_length(const char *key);
char get_key(const char *key,const unsigned long int length);
short int get_primary_key(const char *key,const unsigned long int length);
short int get_master_key(const char *key,const unsigned long int length);
short int get_iron_key(const char *key,const unsigned long int length);
short int get_silver_key(const char *key,const unsigned long int length);
short int get_plantium_key(const char *key);
short int encrypt_byte(char source,const char *key,const unsigned long int length,const short int plantium);
char decrypt_block(short int source,const char *key,const unsigned long int length,const short int plantium);
char *create_decrypt_buffer();
short int *create_encrypt_buffer();
void encrypt_data(char *source,short int *target,const char *key,const unsigned long int key_length,short int plantium,const unsigned long int length);
void decrypt_data(short int *source,char *target,const char *key,const unsigned long int key_length,short int plantium,const unsigned long int length);
void encrypt_file(const char *target,const char *key);
void decrypt_file(const char *target,const char *key);
void work(const char *mode,const char *key,const char *target);


int main(int argc, char *argv[])
{
 show_intro();
 if (argc<4)
 {
  command_line_help();
 }
 else
 {
  check_password_length(argv[2]);
  work(argv[1],argv[2],argv[3]);
 }
 return 0;
}

void show_intro()
{
 putchar('\n');
 puts("BLACK ICE");
 puts("Version 0.9.7");
 puts("Complex file cryptography tool(both encryption and decryption)");
 puts("Copyright by Popov Evgeniy Alekseyevich,2017 year");
 puts("This program distributed under GNU GENERAL PUBLIC LICENSE");
 putchar('\n');
}

void command_line_help()
{
 puts("You must give 3 command line arguments: mode,password,target file name");
 puts("The flags of mode: encrypt - encryption mode, decrypt - decryption mode");
}

void show_start_message()
{
 puts("Working... Please wait...");
}

void show_end_message()
{
 putchar('\n');
 puts("Work finish");
}

void show_progress(const long long int start,const long long int end)
{
 long long int progress;
 progress=start+1;
 progress*=100;
 progress/=end;
 printf("\r");
 printf("Amount of processed bytes: %lld from %lld.Progress:%lld%%",start,end,progress);
}

void check_memory(void *memory)
{
 if(memory==NULL)
 {
  puts("Can't allocate memory");
  exit(4);
 }

}

int open_input_file(const char *name)
{
 int file;
 file=open(name,INPUT_FILE_MODE);
 if (file==-1)
 {
  puts("Can't open input file");
  exit(2);
 }
 return file;
}

int create_output_file(const char *name)
{
 int file;
 file=open(name,OUTPUT_FILE_MODE,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
 if (file==-1)
 {
  puts("Can't create output file");
  exit(3);
 }
 return file;
}

long long int get_file_size(int target)
{
 long long int length;
 length=file_seek(target,0,SEEK_END);
 file_seek(target,0,SEEK_SET);
 return length;
}

long long int file_tell(int target)
{
 return file_seek(target,0,SEEK_CUR);
}

char *get_string_memory(const unsigned long int length)
{
 char *memory=NULL;
 memory=(char*)calloc(length+1,1);
 check_memory(memory);
 return memory;
}

unsigned long int get_extension_position(const char *source)
{
 unsigned long int index;
 for(index=strlen(source);index>0;index--)
 {
  if(source[index]=='.')
  {
   break;
  }

 }
 if (index==0) index=strlen(source);
 return index;
}

char *get_short_name(const char *name)
{
 unsigned long int length;
 char *result=NULL;
 length=get_extension_position(name);
 result=get_string_memory(length);
 strncpy(result,name,length);
 return result;
}

char* get_name(const char *name,const char *ext)
{
  char *result=NULL;
  unsigned long int length;
  if(ext==NULL)
  {
   length=strlen(name);
   result=get_string_memory(length);
   strcpy(result,name);
  }
  else
  {
   length=strlen(name)+strlen(ext);
   result=get_string_memory(length);
   strcpy(result,name);
   strcat(result,ext);
  }
 return result;
}

char *get_extension(const char *name)
{
 char *result=NULL;
 unsigned long int index,length;
 length=strlen(name);
 for(index=length;index>0;index--)
 {
  if(name[index]=='.')
  {
   length-=index-1;
   result=get_string_memory(length);
   memmove(result,name+index,length);
   break;
  }

 }
 return result;
}

blackice_head read_head(int target)
{
 blackice_head head;
 read(target,&head,sizeof(blackice_head));
 if(strncmp(head.signature,"BEF",3)!=0)
 {
  puts("Invalid cryptography container format");
  exit(5);
 }
 return head;
}

void write_container_data(int target,const char *extension)
{
 blackice_head head;
 memset(&head,0,sizeof(blackice_head));
 strncpy(head.signature,"BEF",3);
 if(extension==NULL)
 {
  write(target,&head,sizeof(blackice_head));
 }
 else
 {
  head.extension=strlen(extension);
  write(target,&head,sizeof(blackice_head));
  write(target,extension,head.extension);
 }

}

void check_password_length(const char *key)
{
 unsigned long int length;
 length=strlen(key);
 if (length<2||length>258)
 {
  puts("Invalid password length");
  puts("Minimum password length: 2 character");
  puts("Maximum password length: 258 character");
  exit(1);
 }

}

char get_key(const char *key,const unsigned long int length)
{
 char result;
 static unsigned long int position=0;
 if (position==length-1)
 {
  position=0;
 }
 result=key[position];
 position++;
 return result;
}

short int get_primary_key(const char *key,const unsigned long int length)
{
 static unsigned long int index=0;
 short int result;
 if (index==length-1)
 {
  index=0;
 }
 result=key[index];
 result+=key[index+1];
 index++;
 return result;
}

short int get_master_key(const char *key,const unsigned long int length)
{
 static unsigned long int tail=0;
 static unsigned long int head=0;
 short int result;
 if (tail==length-1) tail=0;
 if (head==0) head=length-1;
 result=key[tail];
 result+=key[head];
 tail++;
 head--;
 return result;
}

short int get_iron_key(const char *key,const unsigned long int length)
{
 static unsigned long int tail=0;
 static unsigned long int head=0;
 short int result;
 if (tail==length-1) tail=0;
 if (head==0) head=length-1;
 result=key[tail]^key[head];
 tail++;
 head--;
 return result;
}

short int get_silver_key(const char *key,const unsigned long int length)
{
 static unsigned long int index=0;
 short int result;
 if (index==length-1)
 {
  index=0;
 }
 result=key[index]^key[index+1];
 index++;
 return result;
}

short int get_plantium_key(const char *key)
{
 unsigned long int index;
 short int result;
 result=0;
 for (index=strlen(key);index>0;index--)
 {
  result+=key[index]^key[index-1];
 }
 return result;
}

short int encrypt_byte(char source,const char *key,const unsigned long int length,const short int plantium)
{
 short int result;
 source^=get_key(key,length);
 ~source;
 result=source;
 result+=get_primary_key(key,length)+get_master_key(key,length)+get_iron_key(key,length)+get_silver_key(key,length);
 return result^plantium;
}

char decrypt_block(short int source,const char *key,const unsigned long int length,const short int plantium)
{
 source^=plantium;
 source-=get_silver_key(key,length)+get_iron_key(key,length)+get_master_key(key,length)+get_primary_key(key,length);
 ~source;
 return source^get_key(key,length);
}

char *create_decrypt_buffer()
{
 char *result;
 result=(char*)calloc(BUFFER_LENGTH,sizeof(char));
 check_memory(result);
 return result;
}

short int *create_encrypt_buffer()
{
 short int *result;
 result=(short int*)calloc(BUFFER_LENGTH,sizeof(short int));
 check_memory(result);
 return result;
}

void encrypt_data(char *source,short int *target,const char *key,const unsigned long int key_length,short int plantium,const unsigned long int length)
{
 unsigned long int index;
 for(index=0;index<length;index++) target[index]=encrypt_byte(source[index],key,key_length,plantium);
}

void decrypt_data(short int *source,char *target,const char *key,const unsigned long int key_length,short int plantium,const unsigned long int length)
{
 unsigned long int index;
 for(index=0;index<length;index++) target[index]=decrypt_block(source[index],key,key_length,plantium);
}

void encrypt_file(const char *target,const char *key)
{
 int input,output;
 long long index,size;
 long int block;
 unsigned long int key_length;
 short int plantium;
 short int *encrypted;
 char *decrypted;
 char *short_name=NULL;
 char *name=NULL;
 char *extension=NULL;
 input=open_input_file(target);
 size=get_file_size(input);
 short_name=get_short_name(target);
 extension=get_extension(target);
 name=get_name(short_name,".bef");
 output=create_output_file(name);
 write_container_data(output,extension);
 free(short_name);
 free(name);
 free(extension);
 encrypted=create_encrypt_buffer();
 decrypted=create_decrypt_buffer();
 block=BUFFER_LENGTH;
 index=0;
 plantium=get_plantium_key(key);
 key_length=strlen(key);
 while(index<size)
 {
  if(size-index<block) block=size-index;
  read(input,decrypted,block);
  encrypt_data(decrypted,encrypted,key,key_length,plantium,block);
  write(output,encrypted,2*block);
  index=file_tell(input);
  show_progress(index,size);
  blackice_sleep(10);
 }
 free(encrypted);
 free(decrypted);
 close(input);
 close(output);
}

void decrypt_file(const char *target,const char *key)
{
 int input,output;
 long long index,size;
 long int block;
 unsigned long int key_length;
 short int plantium;
 short int *encrypted;
 char *decrypted;
 blackice_head head;
 char *short_name=NULL;
 char *name=NULL;
 char *extension=NULL;
 input=open_input_file(target);
 size=get_file_size(input);
 short_name=get_short_name(target);
 head=read_head(input);
 if(head.extension>0)
 {
  extension=get_string_memory(head.extension);
  read(input,extension,head.extension);
 }
 size-=file_tell(input);
 name=get_name(short_name,extension);
 output=create_output_file(name);
 encrypted=create_encrypt_buffer();
 decrypted=create_decrypt_buffer();
 block=BUFFER_LENGTH;
 index=0;
 plantium=get_plantium_key(key);
 key_length=strlen(key);
 while(index<size)
 {
  if(size-index<block) block=size-index;
  read(input,encrypted,block);
  decrypt_data(encrypted,decrypted,key,key_length,plantium,block/2);
  write(output,decrypted,block/2);
  index=file_tell(input);
  show_progress(index,size);
  blackice_sleep(10);
 }
 free(encrypted);
 free(decrypted);
 close(input);
 close(output);
}

void work(const char *mode,const char *key,const char *target)
{
 if(strcmp(mode,"encrypt")!=0)
 {
  if(strcmp(mode,"decrypt")!=0)
  {
   puts("Invalid mode flag");
   exit(6);
  }

 }
 if (strcmp(mode,"decrypt")==0)
 {
  show_start_message();
  decrypt_file(target,key);
  show_end_message();
 }
 if (strcmp(mode,"encrypt")==0)
 {
  show_start_message();
  encrypt_file(target,key);
  show_end_message();
 }

}