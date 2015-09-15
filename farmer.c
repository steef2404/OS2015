/* 
 * Operating Systems  (2INC0)  Practical Assignment
 * Interprocess Communication
 *
 * STUDENT_NAME_1 (STUDENT_NR_1)
 * STUDENT_NAME_2 (STUDENT_NR_2)
 *
 * Grading:
 * Students who hand in clean code that fully satisfies the minimum requirements will get an 8. 
 * ”Extra” steps can lead to higher marks because we want students to take the initiative. 
 * Extra steps can be, for example, in the form of measurements added to your code, a formal 
 * analysis of deadlock freeness etc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>    
#include <unistd.h>         // for execlp
#include <mqueue.h>         // for mq

#include "settings.h"
#include "output.h"
#include "common.h"



int main (int argc, char * argv[])
{
    if (argc != 1)
    {
        fprintf (stderr, "%s: invalid arguments\n", argv[0]);
    }
        
    output_init ();

    printf(" Hello world\n");
    
    pid_t processID;
    
    printf("parent pid:%d\n", getpid());
    processID = fork();
    if (processID < 0)
    {
	perror("fork() failed");
	exit(1);
    }
    else
    {
	if (processID == 0)
	{
	    printf ("child pid:%d\n", getpid());
	    execlp ("./worker", "stefan" "-l", NULL);
	    perror ("execlp() failed");
	}
	
	waitpid (processID, NULL, 0);
	printf ("child %d has been finished\n\n", processID);
    }

    // TODO:
    //  * create the message queues (see message_queue_test() in interprocess_basic.c)
    //  * create the child processes (see process_test() and message_queue_test())
    //  * do the farming (use output_draw_pixel() for the coloring)
    //  * wait until the chilren have been stopped (see process_test())
    //  * clean up the message queues (see message_queue_test())

    // Important notice: make sure that the names of the message queues contain your
    // student name and the process id (to ensure uniqueness during testing)
    
    output_end();
    
    return (0);
}

