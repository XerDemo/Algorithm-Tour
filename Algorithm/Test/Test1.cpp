//#include <stdio.h>
//#include<string.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//int main()
//{
//    char str[] = "There are two";
//    char m[1000][50];
//    char * token = strtok(str," ");
//    int i = 0;
//    int cnt = 0;
//    while (token != NULL) {
//        strcpy(m[i], token);
//        token = strtok(NULL," ");
//        i++;
//        cnt++;
//    }
//////    printf("*****");
////    for (int i = 0; i < cnt; ++ i){
////        puts(m[i]);
////    }
//
//    int k;
//    for (int j = 1; j < cnt; ++j) {
//        char * temp = m[i];
//        for (k = j ; k > 0 ; --k ) {
//            if (strcmpi(m[k],m[k-1]) < 0){
//                strcpy(temp, m[k]);
//                strcpy(m[k],m[k-1]);
//                strcpy(m[k-1], temp);
//            }
//        }
//        strcpy(m[k], temp);
//
//    }
//
//    for (int i = 0; i < cnt; ++ i){
//        for (int j = 0; j < strlen(m[i]); ++j) {
//            if (m[i][j] >= 'A' && m[i][j] <= 'Z'){
//                m[i][j] += 32;
//            }
//        }
//        puts(m[i]);
//    }
//    return 0;
//}