#ifndef MP3_H
#define MP3_H

#define MAX_TAG 6

typedef struct
{
    char tag[10];
    char info[100];
} Details;

typedef enum
{
    Op_invalid = -1,
    Op_view,
    Op_edit,
    Op_help
} Operation;

void bigEndian(void*, int);

/* view functions */
void reader_mp3(char *filename, Details *detail);

/* edit functions */
char *option_frame(char *);
void editor_mp3(char *, char *, char *);

/* help */
void help();

#endif
