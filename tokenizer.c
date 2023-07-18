#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
//hello

int space_char(char c){
  if(c == ' ' || c == '\t' || c == '\n'){
    return 1;
  }else{
    return 0;
  }
}

int non_space_char(char c){
  if(c != ' ' &&  c != '\t' && c != '\n'){
    return 1;
  }else{
    return 0;
  }
}

char *word_start(char* str){
  while(space_char(*str)){
    str++; //increment to the next address in memory
  }if(non_space_char(*str)){
    return str;
  }
  
  return 0;
}

char *word_terminator(char* word){
  while(non_space_char(*word)){
    word++;
  }if(space_char(*word)){
    return word;
  }

  return 0;
}

int count_words(char *str){
  int counter = 0;
  while(*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    counter++;
  }

  return counter;
}

char *copy_str(char* inStr, short len){
  //this + 1 takes the null char '\0' into account
  char* A = malloc(sizeof(char) * (len + 1));// we are dynamically allocating memory for a length
		                             // of char's
		  
  for(int i = 0; i <= len; i++){
    A[i] = inStr[i];
  }

  *(A + (len + 1)) = '\0';
  return A;
}



char **tokenize(char *str){
    int length = count_words(str + 1);
    char** vector = malloc(sizeof(char*) * length);

    for(int i = 0; i < length; i++){
      str = word_start(str);
      char* last = word_terminator(str);
      *(vector + i) = copy_str(str,last - str);
      str = last;
    
    }
    *(vector + length) = NULL;
    return vector;
    
  }

  
void print_tokens(char **tokens){
  while(*tokens){
    printf("%s\n", *tokens);
    tokens += 1;
    }
  
}

void free_tokens(char** tokens){
  int x = 0;
  while(tokens[x] != NULL){
    free(tokens[x]);
    x++;
  }
  free(tokens);
}
