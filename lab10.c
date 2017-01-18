// Lab 10 ExTalker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <ncurses.h>
#define MAXWORDS 100
#define WORDLEN 11
#define DEBUG 0   // set to 0 to disable debug output
#define AVATAR '<'

char* MAP[5][10];

// reads words from the file
// into wl and trims the whitespace off of the end
int readWords(char* wl[MAXWORDS], char* filename);

//modifies s to trim white space off the right side
void trimws(char* s) ;

//prints the words in 5 columns
void generate_map(char* wl[MAXWORDS], int length);

void draw_character(int x, int y, char* use);

void draw_character1(int x, int y, char use);

void capitalize(char b[]);

void printSentence(char* wl[MAXWORDS], int pos);

int main(int argc, char* argv[]) {
 char* wordlist[MAXWORDS];
 char* sentance[100];
 sentance[0] = "";
 char temp[15];
 int wordCount, yPos = 0, xPos = 1, q, wordPos = 0, length = 0, button = 1, pressed = 0;
 int i, t, bDown, bUp, bLeft, bRight, b, b1, jDown,jUp, jLeft, jRight, j1, j2, a_pos = 0, sentance_pos = 0;
 wordCount = readWords(wordlist, argv[1]);

 if (DEBUG) {
  printf("Read %d words from %s \n",wordCount, argv[1]);
  for (i = 0; i< wordCount; i++) {
   printf("%s,", wordlist[i]);
   
   }
  printf("\n");
  }
  wordlist[76] = " ";
  wordlist[77] = " ";
  wordlist[78] = " ";
  wordlist[79] = " ";
  wordlist[80] = " ";

 //most of your code goes here.
 scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,", &t, &bDown, &bUp, &bLeft, &bRight, &b, &b1, &jDown, &jUp, &jLeft, &jRight, &j1, &j2);
 q = t / 200;
 initscr();
 refresh();
 
 generate_map(wordlist, wordCount);
 draw_character1(15, 0, AVATAR);
 
 do{
  scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,", &t, &bDown, &bUp, &bLeft, &bRight, &b, &b1, &jDown, &jUp, &jLeft, &jRight, &j1, &j2);
  
  if(t / 200 == q + 1){//checks if it is time to move left or right
   q = t / 200;
   if(jDown == 1 && yPos < wordCount/5 - 1){
    yPos++;
    draw_character1(15 * xPos, yPos - 1, ' ');
    draw_character1(15 * xPos, yPos, AVATAR);
    wordPos++;
   }
   if(jUp == 1 && yPos > 0){
    yPos--;
    draw_character1(15 * xPos, yPos + 1, ' ');
    draw_character1(15 * xPos, yPos, AVATAR);
    wordPos--;
   }
   if(jRight == 1 && xPos < 5){
    xPos++;
    draw_character1(15 * (xPos - 1), yPos, ' ');
    draw_character1(15 * xPos, yPos, AVATAR);
    wordPos = wordPos + 16;
   }
   if(jLeft == 1 && xPos > 1){
    xPos--;
    draw_character1(15 * (xPos + 1), yPos, ' ');
    draw_character1(15 * xPos, yPos, AVATAR);
    wordPos = wordPos - 16;
   }
   if(bLeft == 1){
		sentance[sentance_pos] = wordlist[wordPos];
		sentance_pos++;
		pressed++;
   }
   if(bUp == 1){
	   sentance[sentance_pos] = " ";
	   sentance_pos++;
	   sentance[sentance_pos] = wordlist[wordPos];
	   sentance_pos++;
	   pressed++;
   }
   if(bDown == 1 && sentance_pos > -1){
	   sentance[sentance_pos-1] = "";
	   sentance_pos--;
	   pressed++;
	   for(i=0;i<100;i++){
		   mvprintw(18, i, "%s", " ");
	   }
   }
  }
  //Make a string array and assign the words and then print them using a for loop and the length. 
  //Delete by using strcpy to copy a "" to the previous spot in the array
  if(button == pressed){
	  length = 0;
	  for(i=0;i<sentance_pos;i++){
		mvprintw(18, length, "%s", sentance[i]);
		refresh();
		length += strlen(sentance[i]);
	  }
  button++;
  }
  
	
 
 } while(1);
 
 endwin();
 return 0;
 }

void trimws(char* s) {
        int len = strlen(s) ;
        int x;
        if (len ==0) return;
        x = len-1;
        while (isspace(s[x]) && (x>=0)) {
                s[x] = '\0';
                x--;
                }
        }



int readWords(char* wl[MAXWORDS], char* filename) {
 int numread =0;
 char line[WORDLEN];
 char *p;
 FILE* fp = fopen(filename,"r");
 if(fp == NULL)
 {
  perror("fopen()");
  return 0;
 }
 while (!feof(fp)) {
  p  =fgets(line, WORDLEN, fp);
  if (!feof(fp) && p !=NULL) {
   trimws(line);
   wl[numread] = (char *)  malloc(strlen(line)+1);
   strcpy(wl[numread], line);
   numread++;
   }
  } 
 fclose(fp);
 return numread; 
 }
 
void generate_map(char* wl[MAXWORDS], int length){
 int row, col, i = 0;
 for(col = 0;col<5;col++){
  for(row=0;row<length/5 + 1;row++){
	  //if(wl[i] == NULL)
		  //draw_character(col * 15, row, "");
	  draw_character(col * 15, row, wl[i]);
	  i++;
  }
 }
}

void draw_character(int x, int y, char* use)
{
 mvprintw(y,x,"%15s", use);    
 refresh();
}

void draw_character1(int x, int y, char use)
{
 mvprintw(y,x,"%c", use);    
 refresh();
}

void capitalize(char b[]){
	b[0] = toupper(b[0]);
}

void printSentence(char* wl[MAXWORDS], int pos){
	int i, length = 0;
	for(i=0;i<pos;i++){
		mvprintw(18, length, "%s", wl[i]);
		length += strlen(wl[i]);
	}	
	
}



