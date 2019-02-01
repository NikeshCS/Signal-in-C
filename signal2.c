#include <signal.h> 
#include <stdio.h>
#include "mytools.h" 
 #include <assert.h>
 #include <time.h>
 
void cnt(int sig); void cnt2(int sig); void cnt3 (int sig);
int killflag = 0;
main() 
{ 
    double x;
    int i;
    int cnt1 = 1; 
    int cntx = 1; 
    struct timespec tim;
    tim.tv_sec  = 0;
    tim.tv_nsec = 500000000L;
    double random_number = 0;
    int n = 0;
    pid_t pid; 
    signal(SIGINT, cnt); 
    
    //assert mytools 
    assert(init_mytool()==0);
    while (cnt1 == 1)
    {
      if(killflag == 1)
      {
        kill(pid, SIGKILL);
      } 
      //gsl rng call
      double random_number = get_random_number() * 100;
      int n = ((int) random_number) % 31 + 1;
      sleep(1);
      printf ("parent sending signal %d\n", n); 
      pid = fork();
      if(pid == -1)
      {
        perror("fork error");
        exit(EXIT_FAILURE);
      }
      if(pid == 0)
       {
         signal(SIGTSTP, cnt2);
         printf ("Signal Received by Child %d\n", n); 
         sleep(1);
         while (cntx == 1)
         {
           printf("Child waiting\n");           
           nanosleep(&tim, NULL);
         }
       }
     }
     finalize_mytool();
     return 0;   
} 

void cnt(int sig) 
{ 
      killflag = 1;
      printf("Signal Received by Parent %d\n", sig); 
      printf("Parent will exit now\n");
      exit(0);
} 


void cnt2(int sig) 
{   
      printf("Signal Received by Child %d\n", sig); 
}