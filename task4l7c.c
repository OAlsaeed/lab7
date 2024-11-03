#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3

void encrypt(char *input, char *output) {
  for (int i = 0; input[i] != '\0'; i++){ 
  char c = input[i];
    if (c >= 'A' && c <= 'Z') {
   output[i] = (c - 'A' - SHIFT + 26) % 26 + 'A'; 
  } else if (c >= 'a' && c <= 'z') {
    output[i] = (c - 'a' - SHIFT + 26) % 26 + 'a'; 
   } else {
    output[i] = c; 
        }
    }
    output[strlen(input)] = '\0'; 
}

void decrypt(char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) { 
     char c = input[i];
     if (c >= 'A' && c <= 'Z') {
       output[i] = (c - 'A' + SHIFT) % 26 + 'A'; 
      } else if (c >= 'a' && c <= 'z') {
      output[i] = (c - 'a' + SHIFT) % 26 + 'a'; 
      } else {
       output[i] = c; 
        }
    }
    output[strlen(input)] = '\0'; 
}

void encrypt_from_file(char *input_file, char *output_file) {
   FILE *infile = fopen(input_file, "r");
    if (infile == NULL) {
    printf("Error! Could not open input file.\n");
     return;
    }
  FILE *outfile = fopen(output_file, "w");
      
  if (outfile == NULL) {
        printf("Error! Could not open output file.\n");
        fclose(infile);
        return;
    }
    char line[1000];
    while (fgets(line, sizeof(line), infile)) {
        char encrypted[1000];
        encrypt(line, encrypted);
        fputs(encrypted, outfile);
    }
    fclose(infile);
    fclose(outfile);
}

void decrypt_from_file(char *input_file, char *output_file) {
    FILE *infile = fopen(input_file, "r");
    if (infile == NULL) {
     printf("Error! Could not open input file.\n");
        return;
    }
    FILE *outfile = fopen(output_file, "w");
    if (outfile == NULL) {
      printf("Error! Could not open output file.\n");
       fclose(infile);
        return;
    }
    char line[1000];
    while (fgets(line, sizeof(line), infile)) {
        char decrypted[1000];
        decrypt(line, decrypted);
        fputs(decrypted, outfile);
    }
    fclose(infile);
    fclose(outfile);
}

int main() {
    int choice;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
         case 1: {
            int input_choice;
            printf("Select input method:\n");
            printf("1. From file\n");
	    printf("2. Enter string\n");
            printf("Enter your choice: ");
            scanf("%d", &input_choice);
            getchar();
            if (input_choice == 1) {
            char input_file[1000], output_file[1000];
              printf("Enter input file name: ");
              fgets(input_file, sizeof(input_file), stdin);
              if (input_file[strlen(input_file) - 1] == '\n') {
             input_file[strlen(input_file) - 1] = '\0';
                 }
           printf("Enter output file name: ");
              fgets(output_file, sizeof(output_file), stdin);
             if (output_file[strlen(output_file) - 1] == '\n') {
             output_file[strlen(output_file) - 1] = '\0';
              }
            encrypt_from_file(input_file, output_file);
           printf("Encryption complete. Encrypted data saved to %s\n", output_file);
            } else if (input_choice == 2) {
            char input[1000], encrypted[1000];
            printf("Enter a string to encrypt: ");
            scanf(" %[^\n]s", input);
            encrypt(input, encrypted);
              printf("Encrypted string: %s\n", encrypted);
                }
                break;
            }
            case 2: {
                int input_choice;
             printf("Select input method:\n");
             printf("1. From file\n");
             printf("2. Enter string\n");
             printf("Enter your choice: "); 
	     scanf("%d", &input_choice);
             getchar();
             if (input_choice == 1) {
             char input_file[1000], output_file[1000];
              printf("Enter input file name: ");
              fgets(input_file, sizeof(input_file), stdin);
              if (input_file[strlen(input_file) - 1] == '\n') {
               input_file[strlen(input_file) - 1] = '\0';
                }
               printf("Enter output file name: ");
               fgets(output_file, sizeof(output_file), stdin);
               if (output_file[strlen(output_file) - 1] == '\n') {
                   output_file[strlen(output_file) - 1] = '\0';
                 }
               decrypt_from_file(input_file, output_file);
                printf("Decryption complete. Decrypted data saved to %s\n", output_file);
                } else if (input_choice == 2) {
                char input[1000], decrypted[1000];
                printf("Enter a string to decrypt: ");
                scanf(" %[^\n]s", input);
                decrypt(input, decrypted);
                printf("Decrypted string: %s\n", decrypted);
                }
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

