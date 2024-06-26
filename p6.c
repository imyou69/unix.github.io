#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
struct stat sb;
if(argc!=2)
{
fprintf(stderr,"usage: %s <pathname>\n", argv[0]);
exit(EXIT_FAILURE);
}
if(stat(argv[1],&sb)==-1)
{
perror("stat");
exit(EXIT_FAILURE);
}

printf("file type:          ");
switch(sb.st_mode & S_IFMT)
{
case S_IFBLK: printf("block device file\n");  
	      break;
case S_IFCHR: printf("character device file\n");  
	      break;
case S_IFDIR: printf("directory\n");  
	      break;
case S_IFIFO: printf("FIFO/pipe\n");  
	      break;
case S_IFLNK: printf("symlink\n");  
	      break;
case S_IFREG: printf("regular file\n");  
	      break;
case S_IFSOCK: printf("socket\n");  
	       break;
default:       printf("regular file\n");  
	       break;
}
printf("Inode number:   %ld\n", (long) sb.st_ino);
printf("Mode:   %lo(octal)\n", (unsigned long) sb.st_mode);	
printf("Blocks allocated:   %lld\n", (long long) sb.st_blocks);
exit(EXIT_SUCCESS);
}
