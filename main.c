#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "linked.h"
#include "myTunes.h"

int main(){
  srand(time(NULL));

  struct song_node * songs = NULL;
  printf("============LINKED LIST============\n");
  printf(">> Testing insert_front...\n");
  printf("initial length: %d\n", get_length(songs));
  songs = insert_front(songs, "queen","bohemian rhapsody");
  songs = insert_front(songs, "radiohead","creep");
  songs = insert_front(songs, "m83","outro");
  songs = insert_front(songs, "m83", "intro");
  songs = insert_front(songs, "radiohead", "karma police");
  songs = insert_front(songs, "ac/dc", "highway to hell");
  print_list(songs);

  printf(">> Freeing list...\n");
  songs = free_list(songs);
  print_list(songs);

  printf(">> Testing insert_order...\n");
  printf("initial length: %d\n", get_length(songs));
  songs = insert_order(songs, "queen", "bohemian rhapsody");
  songs = insert_order(songs, "radiohead", "creep");
  songs = insert_order(songs, "m83", "outro");
  songs = insert_order(songs, "m83", "intro");
  songs = insert_order(songs, "radiohead", "karma police");
  songs = insert_order(songs, "ac/dc", "highway to hell");
  print_list(songs);

  printf(">> Freeing list...\n");
  songs = free_list(songs);
  print_list(songs);

  printf(">> Inserting nodes...\n");
  songs = insert_order(songs, "queen", "bohemian rhapsody");
  songs = insert_order(songs, "radiohead", "creep");
  songs = insert_order(songs, "m83", "outro");
  print_list(songs);

  printf(">> Testing find_song...\n");
  struct song_node * RH = (struct song_node *) malloc(sizeof(struct song_node));
  RH = find_song(songs, "creep", "radiohead");
  print_node(RH);
  printf("\n");

  printf(">> Testing find_artist...\n");
  struct song_node * B = (struct song_node *) malloc(sizeof(struct song_node));
  B = find_artist(songs, "m83");
  print_node(B);
  printf("\n");

  printf(">> Inserting nodes...\n");
  songs = insert_order(songs, "queen", "bohemian rhapsody");
  songs = insert_order(songs, "radiohead", "creep");
  songs = insert_order(songs, "m83", "outro");
  songs = insert_order(songs, "m83", "intro");
  songs = insert_order(songs, "radiohead", "karma police");
  songs = insert_order(songs, "ac/dc", "highway to hell");
  print_list(songs);

  printf(">> Finding a random song...\n");
  struct song_node * randomSong = (struct song_node *) malloc(sizeof(struct song_node));
  randomSong = find_rand(songs);
  print_list(randomSong);

  printf(">> Removing nodes...\n");
  songs = remove_node(songs, "queen", "bohemian rhapsody");
  songs = remove_node(songs, "radiohead", "karma police");
  songs = remove_node(songs, "m83", "intro");
  songs = remove_node(songs, "ray.", "lee.");
  print_list(songs);

  printf("============MUSIC songlib============\n");

  struct song_node * songlib[27];
  for (int i = 0; i < 27; i++) {
    songlib[i] = NULL;
  }

  printf(">> Testing add...\n");
  add(songlib, "queen","bohemian rhapsody");
  add(songlib, "radiohead","creep");
  add(songlib, "m83","outro");
  add(songlib, "m83", "intro");
  add(songlib, "radiohead", "karma police");
  add(songlib, "ac/dc", "highway to hell");
  print_library(songlib);

  printf(">> Testing search_song...\n");
  search_song(songlib, "radiohead", "creep");
  search_song(songlib, "ray.", "lee.");
  printf("\n");

  printf(">> Testing search_artist...\n");
  search_artist(songlib, "radiohead");
  printf("\n");
  search_artist(songlib, "6ix9ine");
  printf("\n");

  printf(">> Testing print_letter...\n");
  print_letter(songlib, 'a');

  printf(">> Testing print_artist...\n");
  print_artist(songlib, "radiohead");

  printf(">> Testing print_library...\n");
  print_library(songlib);

  printf(">> Testing shuffle...\n");
  shuffle(songlib);

  printf(">> Testing delete_song...\n");
  printf("before: ");
  print_library(songlib);
  delete_song(songlib, "queen", "bohemian rhapsody");
  printf("after: ");
  print_library(songlib);

  printf(">> Testing clear...\n");
  printf("before: ");
  print_library(songlib);
  clear(songlib);
  printf("after: ");
  print_library(songlib);

  return 0;
}

