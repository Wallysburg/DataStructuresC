#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<unistd.h>

#include "linkedlist.h"

/*
 * linked list test program
 * author: Charles Davis
 * created: March 2015
 * lastupdate: March 2015
 */

int g_debug = 0 ;

#define BUF_SIZE 1024

int main( int argc, char * argv[]) {
	char buf[BUF_SIZE] ;
	struct DLL * list = create_list();
	int ch ;
	
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
		char op = buf[0] ;
		char * s = buf+1 ;
		s[strlen(s)-1] = '\0' ;
		
		switch(op) {
		
		case '+':
			insert_list(list,s) ;
			printf("+:%s\n",s) ;
			break ;
		case '?':
			printf("?:") ;
			print_list(list) ;
			break ;
		case '!':
			printf("!:%d\n", destroy_list(list)) ;
			list = create_list() ;
			break ;
		case '-':
			if (remove_list(list,s)) printf("-:%s\n",s) ;
			else printf("-:-\n") ;
			break ;
		default: 
			;
		}
	}
	return 0 ;
}
