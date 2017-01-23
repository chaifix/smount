/**
* smout test.  
*/
#include "smount.h"
#include <stdio.h>

int main()
{
	sm_Shared* S = sm_newshared();
	int e = sm_mount(S, ".//C///");
    if (e != 0)
        printf(sm_errstr(e)); 

    e = sm_exists(S, "./games/mario/mario.txt/../"); 
    e = sm_isreg(S, "games/mario/mario.txt");
    printf(sm_read(S, "games/mario/mario.txt", 0));
    printf(sm_fullpath(S, "/games/mario"));
    printf("%d \n", sm_size(S, "games/mario/mario.txt"));
    //sm_delete(S, "games/mario/mario.txt");
    char* str = "this is a demo";
    sm_write(S, "games/mario/mario.txt", str, strlen(str));
	getchar();
	return 0;
}