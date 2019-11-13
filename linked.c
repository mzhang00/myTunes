#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked.h"
#include "myTunes.h"

struct song_node * insert_front(struct song_node * firstnode, char newartist[100], char newname[100]){
  struct song_node * new = malloc(sizeof(struct song_node));
  strcpy(new->song, newname);
  strcpy(new->artist, newartist);
  new->next = firstnode;
  return new;
}

int compare(struct song_node* first, struct song_node* second){
  char a[200] = "dummy";
  char b[200] = "string";
  strcpy(a, first->artist);
  strcat(a, first->song);
  strcpy(b, second->artist);
  strcat(b, second->song);
  return strcmp(a,b);
  return 0;
}

struct song_node * insert_order(struct song_node * front, char artist[100], char name[100]){
  struct song_node * previous = NULL;
  struct song_node * current = front;
  while (current != NULL){
    if (strcmp(current->artist, artist) > 0){
      break;
    }
    if (strcmp(current->artist, artist) == 0){
      if (strcmp(current->song, name) > 0){
        break;
      }
    }
    previous = current;
    current = current->next;
  }
  struct song_node * pointer = insert_front(current, artist, name);
  if (previous != NULL){
    previous->next = pointer;
    return front;
  }
  return pointer;
}

int get_length(struct song_node* node) {
  int counter = 0;
  while (node) {
    counter++;
    node = node->next;
  }
  return counter;
}

struct song_node * find_rand(struct song_node * node) {
  int counter = 0;
  int randomNum = rand() % get_length(node);
  while(counter < randomNum) {
    node = node->next;
    counter++;
  }
  if (node != NULL) {
    printf("Random song found!");
    return node;
  }
  printf("Random song not found! :(\n");
  return node;
}
struct song_node * find_song(struct song_node * firstnode, char name[100], char theartist[100]) {
  struct song_node * tempnode = firstnode;
  while (tempnode != NULL) {
    if(strcmp(tempnode->artist,theartist) == 0 && strcmp(tempnode->song,name) == 0){
      return tempnode;
    }
    tempnode=tempnode->next;
  }
  return tempnode;
}

struct song_node * find_artist(struct song_node * firstnode, char theartist[100]) {
  struct song_node * tempnode = firstnode;
  while (tempnode != NULL) {
    if(strcmp(tempnode->artist,theartist) == 0){
      return tempnode;
    }
    tempnode=tempnode->next;
  }
  return tempnode;
}

struct song_node * free_list(struct song_node * firstnode){
  struct song_node * tempnode;
  struct song_node * currentnode = firstnode;

  while (currentnode != NULL){
    tempnode = currentnode->next;
    free(currentnode);
    currentnode = tempnode;
  }

  return currentnode;
}

struct song_node * remove_node(struct song_node * firstnode, char theartist[100], char name[100]) {
  struct song_node* tempnode = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(tempnode->artist, theartist);
  strcpy(tempnode->song, name);
  struct song_node * currentnode = firstnode;
  if (firstnode == NULL){
    printf("Song not found!\n");
    return firstnode;
  }
  if (compare(firstnode, tempnode) == 0 && get_length(firstnode) == 1) {
    printf("Song removed!\n");
    return NULL;
  }
  if (compare(firstnode, tempnode) == 0){
    firstnode = firstnode->next;
    printf("Song removed!\n");
    return firstnode;
  }
  struct song_node* dummy = firstnode;
  struct song_node* prev;
  while (dummy && compare(tempnode, dummy) != 0) {
    prev = dummy;
    dummy = dummy->next;
  }
  if (dummy == NULL) {
    printf("Song not found!\n");
    return firstnode;
  }
  if (dummy->next == NULL) {
    prev->next = NULL;
    printf("Song removed!\n");
    return firstnode;
  }
  prev->next = dummy->next;
  printf("Song removed!\n");
  return firstnode;

}



void print_list(struct song_node * firstnode){
  struct song_node * currentnode = firstnode;
  if (currentnode== NULL) {
    printf("length: 0\n\n");
    return;
  }
  while (currentnode != NULL){
    printf(" %s: %s |", currentnode->artist, currentnode->song);
    currentnode = currentnode->next;
  }
  printf(" \n");
  printf("length: %d\n\n", get_length(firstnode));
}

void print_node(struct song_node* node) {
  printf("%s: %s\n",node->artist, node->song);
}

