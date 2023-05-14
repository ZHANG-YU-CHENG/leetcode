/**
 * You own a Goal Parser that can interpret a string command. 
 * The command consists of an alphabet of "G", "()" and/or "(al)" in some order. 
 * The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". 
 * The interpreted strings are then concatenated in the original order.
 * 
 * Given the string command, return the Goal Parser's interpretation of command.
 * 
 * 
 * Example 1:
 * Input: command = "G()(al)"
 * Output: "Goal"
 * Explanation: The Goal Parser interprets the command as follows:
 * G -> G
 * () -> o
 * (al) -> al
 * The final concatenated result is "Goal".
 * 
 * Example 2:
 * Input: command = "G()()()()(al)"
 * Output: "Gooooal"
 * 
 * Example 3:
 * Input: command = "(al)G(al)()()G"
 * Output: "alGalooG"
 * 
 * 
 * Constraints:
 * 1 <= command.length <= 100
 * command consists of "G", "()", and/or "(al)" in some order.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * interpret(char * command){
    char* out = (char*)malloc(sizeof(char)*100);
    memset(out, '\0', 100); //must initialize to '\0' to prevent buffer overflow error on leetcode
    for(int i=0; i<strlen(command); ++i)
    {
        switch(command[i])
        {
            case 'G':
                strcat(out,"G");
            break;
            case '(':
                if(command[i+1]==')')
                {
                    strcat(out, "o");
                    ++i;
                }
                else
                {
                    strcat(out, "al");
                    i+=3;
                }
            break;
        }
    }
    return out;
}