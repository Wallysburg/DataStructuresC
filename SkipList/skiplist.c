#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


//-----------------------------------------------------
snode * make_snode() {
  snode * n = (struct snode *)malloc(sizeof(struct snode));
  n->*forward = NULL;
  n->data = NULL;
  n.key= 0;
  return n;
}
//----------------------------------------------------- 
skiplist *create_slist() {
  struct skiplist *list = (struct skiplist *)malloc(sizeof(struct skiplist));
  snode *head = (struct snode *)malloc(sizeof*(struct snode));
  list->head = head;
  head->key = INT_MAX;
  //make forward an array of snodes that each point to the list head
  head->forward = (struct snode **)malloc(sizeof(snode*) * (SKIPLIST_MAX_LEVEL+1));
  for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
    header->forward[i] = list->head;
  }

  list->level = 1;
  list->size = 0;
  return list;
}
//------------------------------------------------------
int random_level() {
  int level = 1;
  while (rand() < RAND_MAX/2 && level < SKIPLIST_MAX_LEVEL)
    level++;
  return level;
}
//------------------------------------------------------ 
