/**

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". 
We will call such a concatenation the transformation of a word.
Return the number of different transformations among all words we have.

 

Example 1:

Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".
Example 2:

Input: words = ["a"]
Output: 1
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 12
words[i] consists of lowercase English letters.

 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int uniqueMorseRepresentations(char ** words, int wordsSize){
    const char* morseTable[] = {".-","-...","-.-.","-..",".","..-.","--.","....",
        "..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...",
        "-","..-","...-",".--","-..-","-.--","--.."};

    char** transformations = (char**)malloc(sizeof(char*)*wordsSize);
    for(int i=0; i<wordsSize; ++i)
    {
        transformations[i] = (char*)malloc(sizeof(char)*50);
    }
    int transformationsId = 0;

    int wordLen = 0;
    char tmp[50] = {0};
    for(int i=0; i<wordsSize; ++i)
    {
        wordLen = strlen(words[i]);
        tmp[0] = '\0';
        for(int j=0; j<wordLen; ++j)
        {
            strcat(tmp, morseTable[words[i][j] - 'a']);
        }
        
        if(transformationsId == 0)
        {
            strcpy(transformations[transformationsId], tmp);
            ++transformationsId;
        }
        else
        {
            int push = 1;
            for(int j=0; j<transformationsId; ++j)
            {
                if((strlen(tmp) == strlen(transformations[j])) && (strcmp(tmp, transformations[j]) == 0))
                {
                    push = 0;
                    break;
                }
            }
            if(push)
            {
                strcpy(transformations[transformationsId], tmp);
                ++transformationsId;              
            }  
            push = 1;          
        }

    } 
    
    for(int i=0; i<wordsSize; ++i)
        free(transformations[i]);
    free(transformations);

    return transformationsId;
}