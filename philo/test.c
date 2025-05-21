#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

extern int usleep (__useconds_t __useconds);


long current_time_in_ms(void)
{
	struct timeval yo;
	long val;

	gettimeofday(&yo, NULL);
	val = (yo.tv_sec * 1000) + yo.tv_usec / 1000;
	return (val);
}

int main(void) {

	struct timeval ok;
	long start_time;

	
	start_time = (ok.tv_sec * 1000 )+ (ok.tv_usec / 1000);
	
	printf("time in milisecond %ld\n", (ok.tv_sec * 1000) + (ok.tv_usec / 1000));
	usleep(1000);

	gettimeofday(&ok, NULL);


	printf("diff == %ld\n", ((ok.tv_sec * 1000) + (ok.tv_usec / 1000)) - start_time);
}