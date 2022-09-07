/**
 * You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. 
 * Return the destination city, that is, the city without any path outgoing to another city.
 * 
 * It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
 * 
 * 
 * Example 1:
 * Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * Output: "Sao Paulo" 
 * Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. 
 * Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
 * 
 * 
 * Example 2:
 * Input: paths = [["B","C"],["D","B"],["C","A"]]
 * Output: "A"
 * Explanation: All possible trips are: 
 * "D" -> "B" -> "C" -> "A". 
 * "B" -> "C" -> "A". 
 * "C" -> "A". 
 * "A". 
 * Clearly the destination city is "A".
 * 
 * Example 3:
 * Input: paths = [["A","Z"]]
 * Output: "Z"
 * 
 * 
 * Constraints:
 * 1 <= paths.length <= 100
 * paths[i].length == 2
 * 1 <= cityAi.length, cityBi.length <= 10
 * cityAi != cityBi
 * All strings consist of lowercase and uppercase English letters and the space character.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    char** table = (char**)malloc(sizeof(char*)*pathsSize);
    for(int i=0; i<pathsSize; ++i)
    {
        table[i] = (char*)malloc(sizeof(char)*11);
        memset(table[i], '\0', 11);
        table[i] = paths[i][0];
    }
    bool no_match_flag;
    for(int i=0; i<pathsSize; ++i)
    {
        no_match_flag = true;
        for(int j=0; j<pathsSize; ++j)
        {
            if((strlen(paths[i][1])==strlen(table[j]))&& !strncmp(paths[i][1],table[j],strlen(paths[i][1])))
            {
                no_match_flag = false;
                break;
            }
        }
        if(no_match_flag) return paths[i][1];
    }
    return NULL;
}
*/

char * destCity(char *** paths, int pathsSize, int* pathsColSize){
    bool no_match_flag;
    for(int i=0; i<pathsSize; ++i)
    {
        no_match_flag = true;
        for(int j=0; j<pathsSize; ++j)
        {
            if(!strcmp(paths[i][1],paths[j][0]))
            {
                no_match_flag = false;
                break;
            }
        }
        if(no_match_flag) return paths[i][1];
    }
    return NULL;
}