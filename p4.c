#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
int accmode,val;
if(argc!=2)
{
fprintf(stderr,"usage:%s <description>",argv[0]);
exit(1);
}
val=fcntl(atoi(argv[1]),F_GETFL,0); /* F_GETFL (void)
              Return (as the function result) the file access mode and the
              file status flags;*/
if(val<0)
{
perror("fcntl error for fd");
exit(1);
}
accmode=val & O_ACCMODE; /*This macro stands for a mask that can be bitwise-ANDed with the file status flag value to produce a value representing the file access mode. The mode will be O_RDONLY, O_WRONLY, or O_RDWR.*/

if(accmode==O_RDONLY)
printf("read only");
else if(accmode==O_WRONLY) 
printf("Write only");
else if(accmode==O_RDWR)
printf("read write");
else
{
fprintf(stderr,"unknown access mode");
exit(1);
}
if(val & O_APPEND)
printf(",append");
if(val & O_NONBLOCK)
printf(",nonblocking");
if(val & O_SYNC)
printf(",synchronous write"); /*wait for writes to complete (data and attributes)*/
putchar('\n');
exit(0);

}
