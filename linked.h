struct song_node
{
  char artist[100];
  char song[100];
  struct song_node *next;
};

struct song_node *insert_front(struct song_node *firstnode, char newartist[100], char newname[100]);
struct song_node * insert_order(struct song_node * front, char artist[100], char name[100]);
void print_list(struct song_node * firstnode);
int get_length(struct song_node* node);
struct song_node * find_rand(struct song_node * node);
struct song_node * find_song(struct song_node * firstnode, char name[100], char theartist[100]);
struct song_node * find_artist(struct song_node * node, char theartist[100]);
struct song_node * find_rand(struct song_node * node);
struct song_node * remove_node(struct song_node * firstnode, char theartist[100], char name[100]);
struct song_node * free_list(struct song_node * firstnode);
void print_node(struct song_node* node);
