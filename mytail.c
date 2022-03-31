/* tail fork, usage: mytail -n 5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 500

char * getlines();

int main(int argc, char *argv[])
{
	int i, c, j, l;
	char temp[MAXLEN];
	int n = 10; /* number of lines to show */
	if (argc > 1){
		if (argv[1][0] == '-' && argv[1][1] == 'n')
			n = atoi(argv[2]);
		else {
			printf("Error: wrong argument.\n");
			return 0;
		}
	}
	if (n > MAXLINES) {
		printf("Error: argument is too big. Limit is %d.\n", MAXLINES);
		return 0;
	}
	char *lines[n];

	c = 0;
	l = 0;

	while (c != EOF) {
		for (j = 0; j < n; j++) {
			for (i = 0; (c = getchar()) !=EOF && c != '\n' && c != '\0'; ++i)
				temp[i] = c;
		    if (c == '\n') {
				temp[i] = c;
				++i;
		    }
		    temp[i] = '\0';
		    if (c != EOF) {
				lines[j] = (char *)malloc((i + 1) * sizeof(char));
			    strcpy(lines[j], temp);
			    l++;
			}
		}
    }
    
/*
    testing commiting
*/
    
	if (l <= n) {
		for (i = 0; i < l; i++) {
			printf("%s", lines[i]);
			free(lines[i]);
		}
	} else {
		l = (l - 1) % n + 1;
		for (i = l; i < n; i++) {
			printf("%s", lines[i]);
			free(lines[i]);
		}
		for (i = 0; i < l; i++) {
			printf("%s", lines[i]);
			free(lines[i]);
		}
	}
	return 1;
}
