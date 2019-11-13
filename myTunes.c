#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked.h"
#include "myTunes.h"

void add(struct song_node *library[27], char newartist[100], char newsong[100])
{
    int index = newartist[0] - 'a';
    if (index < 0 || index > 25)
    {
        index = 26;
    }
    library[index] = insert_order(library[index], newartist, newsong);
}

struct song_node * search_song(struct song_node *library[27], char *artist, char *song){
  int i = artist[0] - 'a';
  if (i < 0 || i > 25) {
    i = 26;
  }
  struct song_node * res = find_song(library[i], song, artist);
  if(res) {
      printf("Song found! :) \n");
  } else {
      printf("Song not found! :( \n");
  }
  return res;
}

struct song_node * search_artist(struct song_node *library[27], char *artist){
  int i = artist[0] - 'a';
  if (i < 0 || i > 25) {
    i = 26;
  }
  struct song_node * res = find_artist(library[i], artist);
  if(res) {
      printf("Artist found! :) \n");
  } else {
      printf("Artist not found! :( \n");
  }
  return res;
}

void print_letter(struct song_node *library[27], char c){
  int index = c - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  if(library[index]) {
    printf("Letter Found!\n");
  }
  else{
    printf("Letter Not Found!\n");
  }
  print_list(library[index]);
}

void print_artist(struct song_node *library[27], char *artist) {
  struct song_node * tempnode = search_artist(library, artist);
  printf("| ");
  while (tempnode && strcmp(tempnode->artist, artist) == 0) {
    printf("%s: %s | ", tempnode->artist, tempnode->song);
    tempnode = tempnode->next;
  }
  printf("\n\n");
}

void print_library(struct song_node *library[27]) {
  int counter = 0;
  for (int i = 0; i < 27; i++) {
    if(library[i]) {
      print_list(library[i]);
      counter++;
    }
  }
  if(counter == 0) {
    printf("|\n");
  }
}

void shuffle(struct song_node *library[27]) {
  int i = 0;
  while (i < 27) {
    if (library[i]) {
      i = 100;
    }
    i++;
  }
  if (i != 101) {
    printf("No songs found!\n");
    return;
  }
  int counter = 3;
  while (counter) {
    int r = rand() % 27;
    if (library[r]) {
      print_list(find_rand(library[r]));
      counter--;
    }
  }
}

void delete_song(struct song_node *library[27], char *artist, char *song){
  int index = artist[0] - 'a';
  if (index < 0 || index > 25) {
    index = 26;
  }
  library[index] = remove_node(library[index], artist, song);
}

void clear(struct song_node *library[27])
{
    int i = 0;
    for (i = 0; i < 27; i++)
    {
        library[i] = free_list(library[1]);
    }
}
