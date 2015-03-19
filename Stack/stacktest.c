#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include "stackapi.h"

/*
 * stack data structure test program
 * author: bjr
 * created: november 2014
 * lastupdate: nov 4, 2014
 */

int g_debug = 0 ;

#define BUF_SIZE 1024
#define INIT_STACK_SIZE 8

#define INSTRUCTIONS "+a add char a to stack\n-  pop stack return element or # if empty stack\n?  query if stack is empty\nh  help\nq  quit\n\n"

int main( int argc, char * argv[]) {
	char buf[BUF_SIZE] ;
	int ch ;
	struct Stack * stack ;

	stack = stackCreate(INIT_STACK_SIZE) ;
	if ( !stack ) {
		printf("Could not create stack\n") ;
		return -1 ;
	}
	
	while ((ch = getopt(argc, argv, "d:")) != -1) {
		switch(ch) {
		case 'd':
			g_debug = atoi(optarg) ;
			break ;
		case '?':
		default:
			printf("usage: -d n for debug level") ;
			return 0 ;
		}
	}
	argc -= optind;
	argv += optind;
    
	while (fgets(buf, sizeof(buf), stdin)) {
	
		// dissect input
		long l ;
		char op, *s ;
		l = strlen(buf) ;
		if ( l==1 ) {
			op = 'h' ; // empty lines are help
		}
		else op = buf[0] ;
		buf[l-1] = '\0' ; // truncate line, or cover newline
		s = buf+1 ;
		
		switch(op) {
		
		case 'h':
			printf(INSTRUCTIONS) ;
			break ;
		case '+':
			if ( s[0] )  {
				l = stackPush(stack,s[0]) ;
				if ( l==-1 ) printf("+*\n") ;
				else printf("+%c\n",s[0]) ;
			}
			// else nothing to insert, skip it
			break ;
		case '?':
			printf("?%d\n", stackIsEmpty(stack)) ;
			break ;
		case '-':
			l = stackPop(stack) ;
			if ( l==-1 ) printf("-#\n") ;
			else printf("-%c\n", (char) l) ;
			break ;
		case 'q':
			exit(0) ;
		case '!':
			while ( !stackIsEmpty(stack) ) {
				l = stackPop(stack) ;
				printf("-%c\n", (char) l ) ;
			}
			break ;
		default: 
			;
		}
	}
	return 0 ;
}
