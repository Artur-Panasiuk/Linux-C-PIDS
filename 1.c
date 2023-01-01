#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]){

	if(argc == 1 || argc > 3){
		fprintf(stderr, "%s\n", "error: argument amount invalid");
		return 1;
	}

	double argvNum = atof(argv[1]);

	if(argvNum < 0){4=n
		fprintf(stderr, "%s\n", "error: argument must be natural number");
		return 2;
	}

	if(argvNum < 1 || argvNum > 13){
		fprintf(stderr, "%s\n", "error: invalid numerical interval");
		return 3;
	}

	if(argvNum == 1 || argvNum == 2) return 1;

  int p[2];

	for(int i = 0; i < 2; i++){
            pid_t pid = fork();
            char buf[10];
            int temp = argvNum - i - 1;
            sprintf(buf, "%d", temp);
            if(pid == 0){
                execl("./1", "./1", buf, NULL);
            }
            p[i] = temp;
	}
	int exits[2];

	for(int j = 0; j < 2; j++){
		int status, child = wait(&status);
    if(WIFEXITED(status)) printf("%d\t%d\t%d\t%d\n", getpid(), child, p[j], WEXITSTATUS(status));
		exits[j] = WEXITSTATUS(status);
	}

	printf("%d\t\t\t%d\n\n", getpid(), exits[0]+exits[1]);

	return p[0];
}
