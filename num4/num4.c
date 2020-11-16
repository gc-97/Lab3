#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#define BUFSIZE 512 /* 읽혀질 덩어리의 크기 */

char centence1[BUFSIZE] = "Hello LINUX world";
char centence2[BUFSIZE] = "COmputer software Engineering";
char centence3[BUFSIZE] = "Lemon Green Tea";

int main(){
    time_t start_time, end_time;
    char a[20];
    char buffer[BUFSIZE]; // 타자수 확인 버퍼
    char buf1[BUFSIZE]; // 파일 입력 버퍼
    char buf2[BUFSIZE]; // 파일 입력 버퍼
    char buf3[BUFSIZE]; // 파일 입력 버퍼
    int wrong_count=0;
    int n;
    int filedes;
    int fd;
    int sum = 0;
    double total = 0;

    printf("---------Press Enter----------");
    gets(a);
    start_time = time(NULL);

    fprintf(stderr, "%s\n",centence1);
    gets(buf1);

    fprintf(stderr,"\n%s\n",centence2);
    gets(buf2);

    fprintf(stderr, "\n%s\n",centence3);
    gets(buf3);
    end_time = time(NULL);

  
    total = difftime(end_time, start_time);
    sum = strlen(buf1) + strlen(buf2) + strlen(buf3);
    sum /= total/60;
  
    for(int i = 0; i < strlen(centence1); i++)
	 if(buf1[i] != centence1[i]) wrong_count++;
    for(int i = 0; i < strlen(centence2); i++) 
	if(buf2[i] != centence2[i]) wrong_count++;
    for(int i = 0; i < strlen(centence3); i++) 
	if(buf3[i] != centence3[i]) wrong_count++;
    

    printf("\nwrong tiping: %d\n",wrong_count); 
    printf("avg: %d\n", sum);
    printf("total time: %f\n", total);

    exit(0);

    return 0;
}
