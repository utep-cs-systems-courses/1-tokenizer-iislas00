#include "stdio.h"
#include "stdlib.h"
#include "history.h"
#include "tokenizer.h"

List* init_history(){
  List* history_list = (List*)malloc(sizeof(List));
  history_list->root = NULL;
  return history_list;  
}

void add_history(List* list, char* str){
  //allocating memory for our item 
  Item *item = (Item*)malloc(sizeof(Item));

  //here we are setting the string to the item in our history list
  item->str = str;
  item->next = NULL;

  //if our list is empty we insert the item at the head of the list
  if(list->root == NULL){
    list->root = item;
    item->id = 1;

    //else if our list if not empty we add the item to the end of our history list
  }else{
    Item *item2 = list->root;
    while(item2->next != NULL){
      item2 = item2->next;
    }
    item2->next = item;
    item->id = item->id + 1;
  }
}

char* get_history(List* list, int id){
  /*
    if the current item in the list matches with the id we return the string, otherwise continue
    with the next item in the list
  */
  Item *temp = list->root;
  while(temp != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  //if the id is not in our list we return NULL
  return NULL;
}

void print_history(List* list){
  Item *root = list->root;

  if(list == NULL){
    printf("list is empty.\n");
    return;
  }

  while(root != NULL){
    printf("%s\n", root->str);
    root = root->next;
  }
}


void free_history(List* list){
  Item *head = list->root;
  while(head != NULL){
    Item *next = head->next;
    free(head->str);
    free(head);
    head = next;
  }
  free(list);
}
