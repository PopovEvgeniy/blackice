#include "format.h"
#include "blackice.h"

void show_intro();
void command_line_help();
void show_message(const char *message);
void show_progress(const long long int start,const long long int end);
void check_password_length(const char *key);
int open_input_file(const char *name);
int create_output_file(const char *name);
void read_data(const int target,void *buffer,const size_t amount);
void write_data(const int target,const void *buffer,const size_t amount);
void check_memory(const void *memory);
void check_signature(const char *signature);
long long int get_file_size(const int target);
char *get_string_memory(const size_t length);
size_t get_name_without_extension_length(const char *source);
char *get_name_without_extension(const char *name);
char *get_name(const char *name,const char *extension);
char *get_extension(const char *name);
blackice_head read_head(const int target);
void write_container_data(const int target,const char *extension);
char get_key(const char *key,const size_t length);
short int get_primary_key(const char *key,const size_t length);
short int get_silver_key(const char *key,const size_t length);
short int get_iron_key(const char *key,const size_t length);
short int get_bronze_key(const char *key,const size_t length);
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
 puts("Version 2.2.6");
 puts("The complex file cryptography tool (both encryption and decryption) by Popov Evgeniy Alekseyevich,2017-2026 years");
 puts("This program is distributed under the GNU GENERAL PUBLIC LICENSE");
}

void command_line_help()
{
 putchar('\n');
 puts("You must give 3 command-line arguments: the mode,a password, and a file name");
 puts("The mode: encrypt - encryption mode, decrypt - decryption mode");
}

void show_message(const char *message)
{
 putchar('\n');
 puts(message);
}

void show_progress(const long long int start,const long long int end)
{
 putchar('\r');
 printf("The amount of the processed bytes: %llu from %llu. The progress:%llu%%",start,end,(start*100)/end);
}

void check_password_length(const char *key)
{
 size_t length=0;
 if (key!=NULL)
 {
  length=strlen(key);
 }
 if ((length<2)||(length>255))
 {
  puts("The password length is invalid");
  puts("The minimum password length is 2 characters");
  puts("The maximum password length is 255 characters");
  exit(1);
 }

}

int open_input_file(const char *name)
{
 int target=-1;
 if (name==NULL)
 {
  puts("Can't open the input file");
  exit(2);
 }
 target=open(name,INPUT_FILE_MODE);
 if (target==-1)
 {
  puts("Can't open the input file");
  exit(2);
 }
 return target;
}

int create_output_file(const char *name)
{
 int target=-1;
 if (name==NULL)
 {
  puts("Can't create the output file");
  exit(3);
 }
 target=open(name,OUTPUT_FILE_MODE,OUTPUT_FILE_PERMISSIONS);
 if (target==-1)
 {
  puts("Can't create the output file");
  exit(3);
 }
 return target;
}

void read_data(const int target,void *buffer,const size_t amount)
{
 if (read(target,buffer,amount)==-1)
  {
   show_message("Can't read data!");
   exit(4);
  }

}

void write_data(const int target,const void *buffer,const size_t amount)
{
 if (write(target,buffer,amount)==-1)
  {
   show_message("Can't write data!");
   exit(5);
  }

}

void check_memory(const void *memory)
{
 if (memory==NULL)
 {
  puts("Can't allocate memory");
  exit(6);
 }

}

void check_signature(const char *signature)
{
 if(strncmp(signature,"BEF",3)!=0)
 {
  puts("The invalid format");
  exit(7);
 }

}

long long int get_file_size(const int target)
{
 long long int length=0;
 length=file_seek(target,0,SEEK_END);
 if (length==-1)
 {
  puts("Can't get the file size!");
  exit(8);
 }
 file_seek(target,0,SEEK_SET);
 return length;
}

char *get_string_memory(const size_t length)
{
 char *memory=NULL;
 memory=(char*)calloc(length+1,sizeof(char));
 check_memory(memory);
 return memory;
}

size_t get_name_without_extension_length(const char *source)
{
 size_t index=0;
 size_t position=0;
 size_t length=0;
 if (source!=NULL)
 {
  length=strlen(source);
 }
 for (index=length;index>0;--index)
 {
  position=index-1;
  if (source[position]==DIRECTORY_SEPARATOR)
  {
   break;
  }
  if (source[position]=='.')
  {
   if (position>0)
   {
    if ((source[position-1]!=DIRECTORY_SEPARATOR) && (source[position-1]!='.'))
    {
     length=position;
     break;
    }

   }

  }

 }
 return length;
}

char *get_name_without_extension(const char *name)
{
 char *result=NULL;
 size_t length=0;
 length=get_name_without_extension_length(name);
 if (length>0)
 {
  result=get_string_memory(length);
  strncpy(result,name,length);
 }
 return result;
}

char *get_name(const char *name,const char *extension)
{
  char *result=NULL;
  char *name_without_extension=NULL;
  size_t name_length=0;
  size_t extension_length=0;
  name_without_extension=get_name_without_extension(name);
  if (name_without_extension!=NULL)
  {
   name_length=strlen(name_without_extension);
  }
  if (extension!=NULL)
  {
   extension_length=strlen(extension);
  }
  if ((name_length>0) && (extension_length>0))
  {
   result=get_string_memory(name_length+extension_length);
   strncpy(result,name_without_extension,name_length);
   strncat(result,extension,extension_length);
  }
  free(name_without_extension);
  return result;
}

char *get_extension(const char *name)
{
 char *result=NULL;
 size_t position=0;
 size_t amount=0;
 position=get_name_without_extension_length(name);
 if (position>0)
 {
  amount=strlen(name)-position;
 }
 if (amount>0)
 {
  result=get_string_memory(amount);
  strncpy(result,name+position,amount);
 }
 return result;
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
 strncpy(head.signature,"BEF",3);
 head.signature[3]=0;
 head.extension=0;
 if (extension==NULL)
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

char get_key(const char *key,const size_t length)
{
 char result=0;
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
 short int result=0;
 static size_t index=0;
 if (index==(length-1))
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
 short int result=0;
 static size_t index=0;
 if (index==(length-1))
 {
  index=0;
 }
 result=key[index];
 result-=key[index+1];
 ++index;
 return result;
}

short int get_iron_key(const char *key,const size_t length)
{
 static size_t tail=0;
 static size_t head=0;
 short int result=0;
 if (tail==(length-1))
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

short int get_bronze_key(const char *key,const size_t length)
{
 static size_t tail=0;
 static size_t head=0;
 short int result=0;
 if (tail==(length-1))
 {
  tail=0;
 }
 if (head==0)
 {
  head=length-1;
 }
 result=key[tail];
 result*=key[head];
 ++tail;
 --head;
 return result;
}

short int get_cobalt_key(const char *key,const size_t length)
{
 short int result=0;
 size_t index=0;
 for(index=0;index<length;++index)
 {
  result+=key[index];
 }
 return ~result;
}

short int get_gold_key(const char *key,const size_t length)
{
 size_t index=0;
 short int result=0;
 result=0;
 for (index=1;index<length;++index)
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
 short int result=0;
 result=source^get_key(key,length);
 result+=get_primary_key(key,length)+get_silver_key(key,length)+get_bronze_key(key,length)+get_iron_key(key,length);
 return result^plantium;
}

char decrypt_block(short int source,const char *key,const size_t length,const short int plantium)
{
 source^=plantium;
 source-=get_bronze_key(key,length)+get_iron_key(key,length)+get_silver_key(key,length)+get_primary_key(key,length);
 return source^get_key(key,length);
}

char *create_decrypt_buffer()
{
 return get_string_memory(BUFFER_LENGTH-1);
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
 size_t index=0;
 for (index=0;index<amount;++index)
 {
  target[index]=encrypt_byte(source[index],key,length,plantium);
 }

}

void decrypt_data(const short int *source,char *target,const char *key,const size_t length,const short int plantium,const size_t amount)
{
 size_t index=0;
 for (index=0;index<amount;++index)
 {
  target[index]=decrypt_block(source[index],key,length,plantium);
 }

}

void encrypt_file(const char *target,const char *key)
{
 int input=-1;
 int output=-1;
 long long int index=0;
 long long int amount=0;
 size_t blocks=0;
 size_t length=0;
 short int plantium=0;
 short int *encrypted=NULL;
 char *decrypted=NULL;
 char *name_without_extension=NULL;
 char *name=NULL;
 char *extension=NULL;
 input=open_input_file(target);
 amount=get_file_size(input);
 name_without_extension=get_name_without_extension(target);
 extension=get_extension(target);
 name=get_name(name_without_extension,".bef");
 output=create_output_file(name);
 write_container_data(output,extension);
 free(name_without_extension);
 free(name);
 free(extension);
 encrypted=create_encrypt_buffer();
 decrypted=create_decrypt_buffer();
 blocks=BUFFER_LENGTH;
 index=0;
 length=strlen(key);
 plantium=get_plantium_key(key,length);
 while (index<amount)
 {
  if ((amount-index)<BUFFER_LENGTH)
  {
   blocks=(size_t)(amount-index);
  }
  read_data(input,decrypted,blocks);
  encrypt_data(decrypted,encrypted,key,length,plantium,blocks);
  write_data(output,encrypted,sizeof(short int)*blocks);
  index=file_seek(input,0,SEEK_CUR);
  show_progress(index,amount);
 }
 show_message("Data synchronization in progress. Please wait");
 file_sync(output);
 free(encrypted);
 free(decrypted);
 close(input);
 close(output);
}

void decrypt_file(const char *target,const char *key)
{
 int input=-1;
 int output=-1;
 long long int index=0;
 size_t amount=0;
 size_t blocks=0;
 size_t length=0;
 size_t chunk=0;
 short int plantium=0;
 short int *encrypted=NULL;
 char *decrypted=NULL;
 char *name_without_extension=NULL;
 char *name=NULL;
 char *extension=NULL;
 blackice_head head;
 input=open_input_file(target);
 amount=get_file_size(input);
 name_without_extension=get_name_without_extension(target);
 head=read_head(input);
 if (head.extension>0)
 {
  extension=get_string_memory((size_t)head.extension);
  read(input,extension,head.extension);
 }
 name=get_name(name_without_extension,extension);
 output=create_output_file(name);
 encrypted=create_encrypt_buffer();
 decrypted=create_decrypt_buffer();
 blocks=BUFFER_LENGTH;
 chunk=sizeof(short int)*blocks;
 index=0;
 length=strlen(key);
 plantium=get_plantium_key(key,length);
 while (index<amount)
 {
  if ((amount-index)<(long long int)chunk)
  {
   blocks=(size_t)(amount-index)/sizeof(short int);
   chunk=blocks*sizeof(short int);
  }
  read_data(input,encrypted,chunk);
  decrypt_data(encrypted,decrypted,key,length,plantium,blocks);
  write_data(output,decrypted,blocks);
  index=file_seek(input,0,SEEK_CUR);
  show_progress(index,amount);
 }
 show_message("Data synchronization in progress. Please wait");
 file_sync(output);
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
   show_message("The invalid mode");
   exit(9);
  }

 }
 if (strcmp(mode,"decrypt")==0)
 {
  show_message("Working... Please wait...");
  decrypt_file(target,key);
  puts("The work has been finished");
 }
 if (strcmp(mode,"encrypt")==0)
 {
  show_message("Working... Please wait...");
  encrypt_file(target,key);
  puts("The work has been finished");
 }

}