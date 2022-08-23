/**
 * You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:
 * 
 * Characters ('a' to 'i') are represented by ('1' to '9') respectively.
 * Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
 * Return the string formed after mapping.
 * 
 * The test cases are generated so that a unique mapping will always exist.
 * 
 * 
 * Example 1:
 * Input: s = "10#11#12"
 * Output: "jkab"
 * Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
 * 
 * Example 2:
 * Input: s = "1326#"
 * Output: "acz"
 * 
 * 
 * Constraints:
 * 1 <= s.length <= 1000
 * s consists of digits and the '#' letter.
 * s will be a valid string such that mapping is always possible.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * freqAlphabets(char * s){
    int s_len = strlen(s);
    char* out = (char*)malloc(sizeof(char)*(s_len+1));
    memset(out, '\0', s_len+1);

    for(int i=0; i<s_len; ++i)
    {
        switch(s[i])
        {
            case '1':
                if(i+2<s_len && s[i+2]=='#')
                {
                    switch(s[i+1])
                    {
                        case '0':
                            strcat(out, "j");
                            break;
                        case '1':
                            strcat(out, "k");
                            break;
                        case '2':
                            strcat(out, "l");
                            break;
                        case '3':
                            strcat(out, "m");
                            break;
                        case '4':
                            strcat(out, "n");
                            break;
                        case '5':
                            strcat(out, "o");
                            break;
                        case '6':
                            strcat(out, "p");
                            break;
                        case '7':
                            strcat(out, "q");
                            break;
                        case '8':
                            strcat(out, "r");
                            break;
                        case '9':
                            strcat(out, "s");
                            break;
                        default:
                            puts("error1");
                            break;
                    }
                    i+=2;
                }
                else
                {
                    strcat(out, "a");
                }
                break;
            case '2':
                if(i+2<s_len && s[i+2]=='#')
                {
                    switch(s[i+1])
                    {
                        case '0':
                            strcat(out, "t");
                            break;
                        case '1':
                            strcat(out, "u");
                            break;
                        case '2':
                            strcat(out, "v");
                            break;
                        case '3':
                            strcat(out, "w");
                            break;
                        case '4':
                            strcat(out, "x");
                            break;
                        case '5':
                            strcat(out, "y");
                            break;
                        case '6':
                            strcat(out, "z");
                            break;
                        default:
                            puts("error2");
                            break;
                    }
                    i+=2;
                }
                else
                {
                    strcat(out, "b");
                }
                break;
            case '3':
                strcat(out, "c");
                break;
            case '4':
                strcat(out, "d");
                break;
            case '5':
                strcat(out, "e");
                break;
            case '6':
                strcat(out, "f");
                break;
            case '7':
                strcat(out, "g");
                break;
            case '8':
                strcat(out, "h");
                break;
            case '9':
                strcat(out, "i");
                break;
            default:
                puts("error3");
                break;
        }
    }
    return out;
}

