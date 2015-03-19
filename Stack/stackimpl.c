#include<stdlib.h>
#include "stackapi.h"

/*
 * stack implementation on an array
 * author: CHARLIE DAVIS
 * created: november 2014
 * last update: november 2014
 */

struct Stack * stackCreate(int size ) {
        struct Stack * s =  (struct Stack*)malloc(sizeof(struct Stack));
	char * contents;
	contents = malloc(sizeof(char)*size);
	s->size = size;
	s->tos = 0; 
	s->theStack = contents;;
	return s ;
}

void stackDestroy(struct Stack * s) {
	if (!s) return ;
	free(s->theStack);
	free(s) ;
}

int stackIsEmpty( struct Stack * s ) {
  if (s->tos == 0) {
	return 1;
  } else return 0;  // why the else?
}

int stackPush( struct Stack * s, char  c)  {
	if (!s) return -1 ;
	if ( s->tos == s->size) {
		/* have to resizemake */
	  int newSize = s->size*2;
	  
	  // declare all variables at the top of a block. don't use inline declarations.
	  
	  // s->theStack = oldContents;
	  // struct Stack *news; 
	  // news = stackCreate(newSize);//(struct Stack*)malloc(sizeof(struct Stack)*newSize);
	  char * newcontents;
	  newcontents = malloc(sizeof(char)*newSize);
	    for(int i=0;i<=s->size;i++) {
		newcontents[i] = s->theStack[i];
	      }
	  s-> size = newSize;
	  free(s->theStack);
	  s -> theStack = newcontents;
	  // free(oldContents);
		// news -> theStack[++news->tos]=c;
	}
	s-> theStack[++s->tos] = c;
	return 0 ; 
}

int stackPop( struct Stack * s )  {
  if (stackIsEmpty(s)) {
	return -1 ;

// why the else here? you wouldn't be here if you entered the if ... ?

  } else {
        return  s->theStack[s->tos--];
   // return 0;
  }
}
