#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main()
{
mode_t oldMask,newMask;
oldMask=umask((mode_t)0);
printf("\n Old mask = %o",(int)oldMask);
if(oldMask & S_IRGRP){
printf("\nChanging group read permission from Masked to unmasked.n");
oldMask=(oldMask ^ S_IRGRP);/* ^ Operator is binar XOR  operator, copies the bit if it is set in one operand but not in both. Exclusive or is a logical operator that outputs true only when inputs differ*/
}

newMask=(oldMask|S_IWGRP|S_IXGRP);
umask(newMask);
printf("\nNew MAsk = %o",(int)newMask);
printf("\nThe file mode creation mask now specifies:");
printf("\n  Group read permission  UNMASKED");
printf("\n  Group write permission  MASKED");
printf("\n  Group execute permission  MASKED");

oldMask=umask((mode_t)0);
printf("\n Old mask = %o",(int)oldMask);

if(oldMask & S_IRUSR){
printf("\nChanging user read permission from Masked to unmasked.n");
oldMask=(oldMask ^ S_IRUSR);
}
newMask=(oldMask|S_IWUSR|S_IXUSR);
umask(newMask);
printf("\nNew MAsk = %o",(int)newMask);
printf("\nThe file mode creation mask now specifies:");
printf("\n  User read permission  UNMASKEDn");
printf("\n  User write permission  MASKEDn");
printf("\n  User execute permission  MASKEDn");

oldMask=umask((mode_t)0);
printf("\n Old mask = %o",(int)oldMask);

if(oldMask & S_IROTH){
printf("\nChanging Other read permission from Masked to unmasked.n");
oldMask=(oldMask ^ S_IROTH);
}
newMask=(oldMask|S_IWOTH|S_IXOTH);
umask(newMask);
printf("\nNew MAsk = %o",(int)newMask);
printf("\nThe file mode creation mask now specifies:");
printf("\n  Other read permission  UNMASKED");
printf("\n  Other write permission  MASKED");
printf("\n  Other execute permission  MASKED");
}
