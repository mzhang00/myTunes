void add(struct song_node *library[27], char newartist[100], char newsong[100]);
struct song_node * search_song(struct song_node *library[27], char *artist, char *song);
struct song_node * search_artist(struct song_node *library[27], char *artist);
void print_letter(struct song_node *library[27], char c);
void print_artist(struct song_node *library[27], char *artist);
void print_library(struct song_node *library[27]);
void shuffle(struct song_node *library[27]);
void delete_song(struct song_node *library[27], char *artist, char *song);
void clear(struct song_node *library[27]);
