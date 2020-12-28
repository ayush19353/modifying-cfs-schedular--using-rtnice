/*Name-Ayush Mahant
Roll No. 2019353
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <linux/kernel.h>
#include <omp.h>

void rec(int i)
{
while(i > 0)
	{
		wait(NULL);
		i--;
	}}
void changer()
{long gf=0;
for(long hg=0;hg<5000000000;hg++)
{
gf++;
}}

int main()
{printf("it is variable so doesnot always give the correct process time because of other factors");
long startingtimer;
double star;double t;
printf("When soft real time is given-------\n");
	
star = omp_get_wtime();
int i=0;
while(i<4)
	{
	if(fork() == 0)
	{
		if(i==0)
	startingtimer = -11;
	else if(i==1)
startingtimer = 80000000000;
	else if(i==2)
startingtimer = 10000000000;
else if(i==3)
startingtimer = 60000000000;
	else
startingtimer = 0;
		long temp;	
		if(i==1)
	{ temp = syscall(440,-4,startingtimer);}
		else
	 temp = syscall(440,getpid(),startingtimer);
		if(temp==0)
		{changer();
		t = omp_get_wtime() - star;
	printf("Process %d: %f sec\n", i , t);
		exit(0);}
		else
		{printf("ERROR is reported-- (INVALID DETAIL PROVIDED)  %ld\n",temp);exit(0);
		}
	}i++;}
	rec(i);

	
	printf("When soft real time is        NOT          given-------\n");
	
	star = omp_get_wtime();
	 i=0;
	while(i<4)
	{
		if(fork() == 0)
		{
			 changer();
t = omp_get_wtime() - star;
printf("Processes ran in seconds is %d: %f\n",i, t);
			exit(0);
		}i++;
	}
	rec(i);

	return 0;

}
