
struct Stack {
	int size ;
	int tos ;
	char * theStack ;
} ;

/* note:
 *   tos is the next place to add a element, 0 on initialization
 *   size is the current size of the the stack, that is, the number of
 *     elements in the array theStack
 */

struct Stack * stackCreate( int size ) ;
void stackDestroy( struct Stack * s ) ;
int stackIsEmpty( struct Stack * s ) ;
int stackPush( struct Stack * s, char  c) ;
int stackPop( struct Stack * s ) ;


