/*                                         
 * BSP data definitions and API      
 * author: Charles Davis
 * created: March 2015                                               
 * lastupdate: March 4, 2015 
*/


typedef struct Node {
  struct Node * left;
  struct Node * right;
  char * data;

} node;

typedef struct BSP {
  struct Node * root;
  int size;
} BSP;

struct BSP * create_tree();
void print_tree(struct BSP * tree);
void insert_tree(struct BSP * tree, char *s);
int destroy_tree(struct BSP * tree);
int remove_tree(struct BSP * tree, char * s);
