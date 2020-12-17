// Ludovico Verniani
// 66045694

#include "hw1.h"
// You may define any helper functions you want. Place them in helpers.c/.h

// Main program
int main(int argc, char *argv[]) {
    // Insert your hw1 code here
    int l = 0;
    int c = 0;
    int w = 0;
    int a = 0;
    int L = 0;
    int f = 0;

    int v = 0;


    //printf("%d\n%s\n", argc, argv[1]);
    
     if (argc == 3) {
        //Second arguemt process
        if (!strcmp(argv[2], "-v")) {
            v = 1;
        } else {
            //Error
             vProcess(USAGE_MSG);
            return 1;
        }

    } 
     
    if ((argc < 2) || (argc > 3)) {
        //Error
         vProcess(USAGE_MSG);
        return 1;

    }


        //First argument process
            if (!strcmp(argv[1], "-l")) { 
               return lProcess(v);
            } else if (!strcmp(argv[1], "-c")) {
                return cProcess(v);
            } else if (!strcmp(argv[1],"-w")) {
               return wProcess(v);
            } else if (!strcmp(argv[1], "-a")) {
                return aProcess(v);
            } else if (!strcmp(argv[1],"-L")) {
                return LProcess(v);
            } else if (!strcmp(argv[1], "-f")) {
                return fProcess(v);
            } else {
                //Error
                 vProcess(USAGE_MSG);
                return 1;
            }
    

   
 
       
    return 0;
}
