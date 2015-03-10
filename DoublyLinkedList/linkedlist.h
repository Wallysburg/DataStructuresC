

/*
 * linked list data definitions and API
 * author: Charles Davis
 * created: March 2015
 * lastupdate: March 4, 2015
 */

extern int g_debug ;

struct N { 
	struct N * next ;
	struct N * prev ;
	char * data ;
}; 

struct DLL {
  struct N* head;
  struct N* tail;
  int size;

}; 
struct DLL * create_list() ; // returns empty list (with dummy header)
void print_list(struct DLL * list) ; // space separated newline terminated
void insert_list(struct DLL * list, char * s) ; // inserts in lexicographic order
int destroy_list(struct DLL * list) ;  // returns number of items removed
int remove_list(struct DLL * list, char * s) ;  // returns 1 if item removed, else 0

