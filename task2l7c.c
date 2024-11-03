 #include <stdio.h>

 void count(char *filename, int *lines, int *words, int *characters) {
     FILE *fp = fopen(filename, "r");
    char ch, prev_ch = ' ';  

    *lines = *words = *characters = 0;

     if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
      return;
    }
      while ((ch = fgetc(fp)) != EOF) {
     (*characters)++;  

       if (ch == '\n') {
     (*lines)++;  
        }
       if (ch == ' ' || ch == '\n' ) {
        if (prev_ch != ' ' && prev_ch != '\n' ) {
         (*words)++;  
            }
        }
        prev_ch = ch;
    }
     if (prev_ch != ' ' && prev_ch != '\n') {
        (*words)++;
    }

    fclose(fp);

   printf("Lines: %d\n", *lines);
    printf("Words: %d\n", *words);
    printf("Characters: %d\n", *characters);

}

int main() {
    char *filename = "task2test.txt";  
    int lines, words, characters;

    count(filename, &lines, &words, &characters);  

    

    return 0;
}
