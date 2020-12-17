#include "hw1.h"
#include "helpers1.h"



// Declare all helper functions for hw1 in this file
int lProcess(int isVerbose) {
    char * line = NULL;
    
    size_t len = 0;
    ssize_t lineSize = 0;

    int totalCount = 0;

  
    while (1) {
        lineSize = getline(&line, &len, stdin);
        if (lineSize == -1) {
            if (totalCount == 0) {
                //Error
                return 2;
            } else {
                break;
            }

        }
        
        if (isVerbose) {
            fprintf(stderr, "%s", line);
        }

        totalCount++;

    }

    if (isVerbose) {
        fprintf(stderr, "%c", '\n');
    }
    

    printf("%s %d\n", TOTAL_LINES_OPTION, totalCount);    

    return 0;
    
    

}


int cProcess(int isVerbose) {

    char * line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    int totalCount = 0;

    while (1) {
        lineSize = getline(&line, &len, stdin);
        if (lineSize == -1) {
            if (totalCount == 0) {
                //Error
                return 2;
            } else {
                break;
            }

        }

        if ((line[0] != '\n') && (line[0] != '/')) {
                    
            if (isVerbose) {
                fprintf(stderr, "%s", line);
            }
            totalCount++;
        }


    }

    if (isVerbose) {
        fprintf(stderr, "%c", '\n');
    }

    printf("%s %d\n", NON_EMPTY_LINES_OPTION, totalCount);

    return 0;
}



int wProcess(int isVerbose) {

    char * line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    int totalCount = 0;
    ssize_t  maxWidth = 0;
    char * content = malloc(100);

    int isCommented = 0;

    while (1) {
        lineSize = getline(&line, &len, stdin);
        if (lineSize == -1) {
            if (totalCount == 0) {
                //Error
                return 2;
            } else {
                break;
            }

        }

        char * start = strstr(line, "/*");
        
        if (start != NULL) {
            isCommented = 1;
        }



        if ((line[0] != '/')   && (strstr(line, "//") == NULL) &&(!isCommented) && ((lineSize-1) > maxWidth)) {
            strncpy(content, line, lineSize);
            maxWidth = (lineSize-1);
        }
        totalCount++;

        char * end = strstr(line, "*/");
        if (end != NULL) {
            isCommented = 0;
        }

   }

    if (isVerbose) {
            fprintf(stderr, "%s\n", content);
    }

    printf("%s %zu\n\n", MAX_LINE_WIDTH_OPTION, maxWidth);
 
   
   return 0;
}


int countA(char * line, int count) {
    /*
    if (line[0] == '\n') {
        return count;
    } else {
        char * comparisons[] = {"=", "+=", "*=", "/=",  "-=", "|=", "&=", ">>=", "<<=", "^="};
        int i;
        char * start = NULL;
        for (i = 0; i < 10; i++) {
            start = strstr(line, comparisons[i]);
            if (start != NULL) {
              start = (char*)start;
              if ((start[0] != '=') || ((start[0] == '=') && (start[-1] == ' ') && (start[1] == ' '))) {
                  count++;
                  int skip = 2;
                  if ((start[0] == '<') || (start[0] == '>')) {
                      skip = 3;
                  } else if (start[0] == '=') {
                      skip = 1;
                  }
                  return countA(&start[skip], count);
            
        }
    }
            return count; 
    }
    return count;





        char * comparisons[] = {"=", "+=", "*=", "/=",  "-=", "|=", "&=", ">>=", "<<=", "^="};
        int i;
        char * start = NULL;
        char * tmp = malloc(100);
        for (i = 0; i < 10; i++) {
            start = strstr(line, comparisons[i]);
            strcpy(tmp, start);
            while ((start != NULL) && (strlen(tmp) > 0)) {
    
              if ((tmp[0] != '=') || ((tmp[0] == '=') && (tmp[-1] == ' ') && (tmp[1] == ' '))) {
                  count++;
                  int skip = 2;
                  if ((tmp[0] == '<') || (tmp[0] == '>')) {
                      skip = 3;
                  } else if (tmp[0] == '=') {
                      skip = 1;
                  }

                tmp = strstr(&tmp[skip], comparisons[i]);      
                }
            }
    }
     free(tmp);      
    
     return count; 

     */

    char * comparisons[] = {"=", "+=", "*=", "/=",  "-=", "|=", "&=", ">>=", "<<=", "^="};
    int i;
    char * start = NULL;
    for (i = 0; i < 10; i++) {
        start = strstr(line, comparisons[i]);
        while ((start != NULL)) {
            
            if ((start[0] != '=') || ((start[0] == '=') && (start[-1] == ' ') && (start[1] == ' '))) {
                count++;
            }
            int skip = 2;
            if ((start[0] == '<') || (start[0] == '>')) {
                skip = 3;
            } else if (start[0] == '=') {
                skip = 1;
            }
            start = strstr(&start[skip], comparisons[i]);
        }
    }

    
    return count;
}



int aProcess(int isVerbose) {

    char * line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    int totalCount = 0;
    int aCount = 0;

    while (1) {
        lineSize = getline(&line, &len, stdin);
        if (lineSize == -1) {
            if (totalCount == 0) {
                //Error
                return 2;
            } else {
                break;
            }

        }

        int pastCount = aCount;
        

        aCount += countA(line, 0);

        if (pastCount != aCount) {
            if (isVerbose) {
                int i;
                for (i=0; i < (aCount - pastCount); i++) {
                    fprintf(stderr, "%s", line);
                }
            }
        }
        totalCount++;

    }

    if (isVerbose) {
        fprintf(stderr, "%c", '\n');
    }

    printf("%s %d\n", ASSIGNMENT_COUNT_OPTION, aCount);
    return 0;
}


int LProcess(int isVerbose) {

    char * line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    int totalCount = 0;
    int loopCount = 0;

    int isCommented = 0;

    while (1) {
        lineSize = getline(&line, &len, stdin);
        if (lineSize == -1) {
            if (totalCount == 0) {
                //Error
                return 2;
            } else {
                break;
            }

        }
        totalCount++;

        char * start = strstr(line, "/*");
        if (start != NULL) {
            isCommented = 1;
        }





        if ((!isCommented) && (strstr(line, "//") == NULL)) {
            char * comparisons[] = {" for ", " do ", " while "};
            int i;
            for (i = 0; i < 3; i++) {    
                char * start = strstr(line, comparisons[i]);
                if ((start != NULL) && (strstr(start, "{"))) {
                    if (isVerbose) {
                        fprintf(stderr, "%s", line);
                    }
                    loopCount++;
                } 
            }
        }

        char * end = strstr(line, "*/");
        if (end != NULL) {
            isCommented = 0;
        }
    }

    if (isVerbose) {
        fprintf(stderr, "%c", '\n');
    }

    printf("%s %d\n\n",   LOOP_COUNT_OPTION,  loopCount);
    return 0;
}


int fProcess(int isVerbose) {

    char * line = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;

    int totalCount = 0;
   int fCount = 0;

    while (1) {
        lineSize = getline(&line, &len, stdin);
        if (lineSize == -1) {
            if (totalCount == 0) {
                //Error
                return 2;
            } else {
                break;
            }

        }

        if ((line[0] != '/') && (line[0] != ' ')) {
            if ((strstr(line, "(") != NULL) && (strstr(line, ")") != NULL) && (strstr(line, "{") != NULL)) {
               if (isVerbose) {
                    fprintf(stderr, "%s", line);
                }
                fCount++;
            }

        }

   
        
        totalCount++;

    }

    if (isVerbose) {
        fprintf(stderr, "%c", '\n');
    }


    printf("%s %d\n", FUNC_DEF_COUNT_OPTION, fCount);
    return 0;
}



int vProcess(char * content) {
    fprintf(stderr, "%s", content);
    return 0; 
}
