#include "format.h"
#include "blackice.h"

void show_intro();
void command_line_help();
void show_message(const char *message);
void show_progress(const long long int start,const long long int end);
void check_memory(const void *memory);
int open_input_file(const char *name);
int create_output_file(const char *name);
long long int get_file_size(const int target);
long long int file_tell(const int target);
void read_data(const int target,void *buffer,const size_t amount);
void write_data(const int target,void *buffer,const size_t amount);
char *get_string_memory(const size_t length);
size_t get_extension_position(const char *source);
char *get_short_name(const char *name);
char* get_name(const char *name,const char *ext);
char *get_extension(const char *name);
void check_signature(const char *signature);
blackice_head read_head(const int target);
void write_container_data(const int target,const char *extension);
void check_password_length(const char *key);
char get_key(const char *key,const size_t length);
short int get_primary_key(const char *key,const size_t length);
short int get_silver_key(const char *key,const size_t length);
short int get_iron_key(const char *key,const size_t length);
short int get_cobalt_key(const char *key,const size_t length);
short int get_gold_key(const char *key,const size_t length);
short int get_plantium_key(const char *key,const size_t length);
short int encrypt_byte(const char source,const char *key,const size_t length,const short int plantium);
char decrypt_block(short int source,const char *key,const size_t length,const short int plantium);
char *create_decrypt_buffer();
short int *create_encrypt_buffer();
void encrypt_data(const char *source,short int *target,const char *key,const size_t length,const short int plantium,const size_t amount);
void decrypt_data(const short int *source,char *target,const char *key,const size_t length,const short int plantium,const size_t amount);
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
 puts("Version 1.7.1");
 puts("Complex file cryptography tool(both encryption and decryption)");
 puts("Copyright by Popov Evgeniy Alekseyevich,2017-2023 years");
 puts("This program distributed under GNU GENERAL PUBLIC LICENSE");
}

void command_line_help()
{
 putchar('\n');
 puts("You must give 3 command line arguments: mode,password,target file name");
 puts("The flags of mode: encrypt - encryption mode, decrypt - decryption mode");
}

void show_message(const char *message)
{
 putchar('\n');
 puts(message);
}

void show_progress(const long long int start,const long long int end)
{
 long long int progress;
 progress=(start+1)*100;
 progress/=end;
 printf("\r");
 printf("Amount of processed bytes: %lld from %lld.Progress:%lld%%",start,end,progress);
}

void check_memory(const void *memory)
{
 if(memory==NULL)
 {
  show_message("Can't allocate memory");
  exit(6);
 }

}

int open_input_file(const char *name)
{
 int file;
 file=open(name,INPUT_FILE_MODE,S_IRUSR|S_IRGRP|S_IROTH);
 if (file==-1)
 {
  show_message("Can't open input file");
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
  show_message("Can't create output file");
  exit(3);
 }
 return file;
}

long long int get_file_size(const int target)
{
 long long int length;
 length=file_seek(target,0,SEEK_END);
 file_seek(target,0,SEEK_SET);
 return length;
}

long long int file_tell(const int target)
{
 return file_seek(target,0,SEEK_CUR);
}

void read_data(const int target,void *buffer,const size_t amount)
{
 if (read(target,buffer,amount)==-1)
  {
   show_message("Can't read data!");
   exit(4);
  }

}

void write_data(const int target,void *buffer,const size_t amount)
{
 if (write(target,buffer,amount)==-1)
  {
   show_message("Can't write data!");
   exit(5);
  }

}

char *get_string_memory(const size_t length)
{
 char *memory=NULL;
 memory=(char*)calloc(length+1,sizeof(char));
 check_memory(memory);
 return memory;
}

size_t get_extension_position(const char *source)
{
 size_t index;
 for(index=strlen(source);index>0;--index)
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
 size_t length;
 char *result=NULL;
 length=get_extension_position(name);
 result=get_string_memory(length);
 strncpy(result,name,length);
 return result;
}

char* get_name(const char *name,const char *ext)
{
  char *result=NULL;
  size_t length;
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
 size_t index,length;
 length=strlen(name);
 for(index=length;index>0;--index)
 {
  if(name[index]=='.')
  {
   length-=index-1;
   result=get_string_memory(length);
   strncpy(result,name+index,length);
   break;
  }

 }
 return result;
}

void check_signature(const char *signature)
{
 if(strncmp(signature,"BEF",3)!=0)
 {
  show_message("Invalid cryptography container format");
  exit(7);
 }

}

blackice_head read_head(const int target)
{
 blackice_head head;
 read(target,&head,sizeof(blackice_head));
 check_signature(head.signature);
 return head;
}

void write_container_data(const int target,const char *extension)
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
  head.extension=(unsigned long int)strlen(extension);
  write(target,&head,sizeof(blackice_head));
  write(target,extension,head.extension);
 }

}

void check_password_length(const char *key)
{
 size_t length;
 length=strlen(key);
 if (length<2||length>255)
 {
  puts("Invalid password length");
  puts("Minimum password length: 2 character");
  puts("Maximum password length: 255 character");
  exit(1);
 }

}

char get_key(const char *key,const size_t length)
{
 char result;
 static size_t position=0;
 if (position==length)
 {
  position=0;
 }
 result=key[position];
 ++position;
 return result;
}

short int get_primary_key(const char *key,const size_t length)
{
 short int result;
 static size_t index=0;
 if (index==length-1)
 {
  index=0;
 }
 result=key[index];
 result+=key[index+1];
 ++index;
 return result;
}

short int get_silver_key(const char *key,const size_t length)
{
 short int result;
 static size_t index=0;
 if (index==length-1)
 {
  index=0;
 }
 result=key[index];
 result*=key[index+1];
 ++index;
 return result;
}

short int get_iron_key(const char *key,const size_t length)
{
 static size_t tail=0;
 static size_t head=0;
 short int result;
 if (tail==length-1)
 {
  tail=0;
 }
 if (head==0)
 {
  head=length-1;
 }
 result=key[tail];
 result+=key[head];
 ++tail;
 --head;
 return result;
}

short int get_cobalt_key(const char *key,const size_t length)
{
 short int result;
 size_t index;
 result=0;
 for(index=0;index<length;++index)
 {
  result+=key[index];
 }
 return result;
}

short int get_gold_key(const char *key,const size_t length)
{
 size_t index;
 short int result;
 result=0;
 for (index=length;index>0;--index)
 {
  result+=key[index]^key[index-1];
 }
 return result;
}

short int get_plantium_key(const char *key,const size_t length)
{
 return get_cobalt_key(key,length)^get_gold_key(key,length);
}

short int encrypt_byte(const char source,const char *key,const size_t length,const short int plantium)
{
 short int result;
 result=source^get_key(key,length);
 result+=get_primary_key(key,length)+get_silver_key(key,length)+get_iron_key(key,length);
 return result^plantium;
}

char decrypt_block(short int source,const char *key,const size_t length,const short int plantium)
{
 source^=plantium;
 source-=get_iron_key(key,length)+get_silver_key(key,length)+get_primary_key(key,length);
 return source^get_key(key,length);
}

char *create_decrypt_buffer()
{
 char *result=NULL;
 result=(char*)calloc(BUFFER_LENGTH,sizeof(char));
 check_memory(result);
 return result;
}

short int *create_encrypt_buffer()
{
 short int *result=NULL;
 result=(short int*)calloc(BUFFER_LENGTH,sizeof(short int));
 check_memory(result);
 return result;
}

void encrypt_data(const char *source,short int *target,const char *key,const size_t length,const short int plantium,const size_t amount)
{
 size_t index;
 for (index=0;index<amount;++index)
 {
  target[index]=encrypt_byte(source[index],key,length,plantium);
 }

}

void decrypt_data(const short int *source,char *target,const char *key,const size_t length,const short int plantium,const size_t amount)
{
 size_t index;
 for (index=0;index<amount;++index)
 {
  target[index]=decrypt_block(source[index],key,length,plantium);
 }

}

void encrypt_file(const char *target,const char *key)
{
 int input,output;
 long long int index,amount;
 size_t blocks,length,chunk,encrypted_block_size;
 short int plantium;
 short int *encrypted=NULL;
 char *decrypted;
 char *short_name=NULL;
 char *name=NULL;
 char *extension=NULL;
 input=open_input_file(target);
 amount=get_file_size(input);
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
 blocks=BUFFER_LENGTH;
 encrypted_block_size=sizeof(short int);
 chunk=blocks*encrypted_block_size;
 index=0;
 length=strlen(key);
 plantium=get_plantium_key(key,length);
 while (index<amount)
 {
  if (amount-index<(long long int)blocks)
  {
   blocks=(size_t)amount-(size_t)index;
   chunk=blocks*encrypted_block_size;
  }
  read_data(input,decrypted,blocks);
  encrypt_data(decrypted,encrypted,key,length,plantium,blocks);
  write_data(output,encrypted,chunk);
  index=file_tell(input);
  show_progress(index,amount);
 }
 free(encrypted);
 free(decrypted);
 close(input);
 close(output);
}

void decrypt_file(const char *target,const char *key)
{
 int input,output;
 long long int index,amount;
 size_t blocks,length,chunk,encrypted_block_size;
 short int plantium;
 blackice_head head;
 short int *encrypted=NULL;
 char *decrypted=NULL;
 char *short_name=NULL;
 char *name=NULL;
 char *extension=NULL;
 input=open_input_file(target);
 amount=get_file_size(input);
 short_name=get_short_name(target);
 head=read_head(input);
 if (head.extension>0)
 {
  extension=get_string_memory((size_t)head.extension);
  read(input,extension,head.extension);
 }
 name=get_name(short_name,extension);
 output=create_output_file(name);
 encrypted=create_encrypt_buffer();
 decrypted=create_decrypt_buffer();
 blocks=BUFFER_LENGTH;
 encrypted_block_size=sizeof(short int);
 chunk=blocks*encrypted_block_size;
 index=0;
 length=strlen(key);
 plantium=get_plantium_key(key,length);
 while (index<amount)
 {
  if (amount-index<(long long int)chunk)
  {
   blocks=((size_t)amount-(size_t)index)/encrypted_block_size;
   chunk=blocks*encrypted_block_size;
  }
  read_data(input,encrypted,chunk);
  decrypt_data(encrypted,decrypted,key,length,plantium,blocks);
  write_data(output,decrypted,blocks);
  index=file_tell(input);
  show_progress(index,amount);
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
   show_message("Invalid mode flag");
   exit(8);
  }

 }
 if (strcmp(mode,"decrypt")==0)
 {
  show_message("Working... Please wait...");
  decrypt_file(target,key);
  show_message("Work finish");
 }
 if (strcmp(mode,"encrypt")==0)
 {
  show_message("Working... Please wait...");
  encrypt_file(target,key);
  show_message("Work finish");
 }

}