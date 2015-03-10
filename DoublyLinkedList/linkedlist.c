#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include "linkedlist.h"


/*
 * linked list procedures
 * author: Charles Davis 
 * created: March 3, 2015
 * lastupdate: March 3, 2015
 */

//---------------------------------------------------------------------------  
//---------------------------------------------------------------------------  
struct N * make_node() {
	struct N * n = (struct N *) malloc(sizeof(struct N)) ;
	n->prev = n->next = NULL ;
	n->data = NULL ;
	return n ;
}
//---------------------------------------------------------------------------  
void free_node(struct N * n ) {
	free(n->data) ;
	free(n);
}
//---------------------------------------------------------------------------  
struct DLL * create_list() {
  struct DLL *list = (struct DLL *)malloc(sizeof(struct DLL));
  list-> head = make_node();
  list ->tail = make_node();
  list->head->next = list->tail;
  list->tail-> prev = list->head;
  list->head->data = strdup("[head]");
  list->tail->data = strdup("[tail]");
  list->size = 0;
  // use strdup so that every n->data is "freeable"      	
	return list;
}
//---------------------------------------------------------------------------  
void print_list(struct DLL * list) {
  struct N* n = list->head;
	if (g_debug>0) printf("Entered print_list\n") ; 
	else printf("\n") ;
		if (n==NULL) {
	  return;
        } 
	while (n != NULL) {
        char* temp = n-> data;
	printf("%s ", temp);
	n = n -> next;
	}
	printf("\n");
	printf("# of items in list :%d\n", list->size);
	return;
}
//---------------------------------------------------------------------------  
void insert_list(struct DLL *list, char * s) {
    struct N * newNode = make_node();
    newNode-> data = strdup(s);
    struct N * current = list->head;    
    //iterate through list until next node is tail or contains the data that comes next
    while (current->next != list->tail && strcmp((current->next)->data, s) <= 0 ) {  
	current = current->next;
    } 
    //insert 
    newNode -> prev = current;
    newNode ->next = current ->next;
    (current->next)-> prev = newNode;
    current->next = newNode;
    list->size++;
}
//---------------------------------------------------------------------------
int destroy_list(struct DLL * list) {
  struct N* n = list->head; 
  struct N *temp = (struct N *)malloc(sizeof(struct N));
  //keep track of nodes destroyed (we could also just use list->size...but whatever)
  int casualities = 0;
  while(n) {
    temp = n;
    n = n -> next;
    free_node(temp);
    casualities++;
  }
  free(list);
    // returns number of items removed (not including head and tail)
	return casualities-2 ;
}
//---------------------------------------------------------------------------  
int remove_list(struct DLL * list, char * s) {
// returns 1 if item removed, else 0
  struct N * current = list->head;

  //iterate through list                                                                          
  while (current->next != list->tail && strcmp((current->next)->data, s) <= 0 ) {
    current = current->next;
  }
  //if we haven't found it yet, and the last node before tail isn't it, then it's not in the list
  if(strcmp(current->data, s) != 0) {
    return 0;
  }
  //remove                                                                                        
  (current->next)->prev = current->prev; 
  (current->prev)-> next = current->next;
  free_node(current);
  list->size--;
  return 1;
}
//---------------------------------------------------------------------------  
//---------------------------------------------------------------------------  
