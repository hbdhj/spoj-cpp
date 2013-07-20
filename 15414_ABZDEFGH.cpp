//
//  15414_ABZDEFGH.cpp
//  
//
//  Created by Haijun Deng on 13-7-20.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string.h>

int main()
{
    int n=0;
    int char_id=0;
    char str[30];
    int dict[26];
    memset(dict, 0, sizeof(dict));
    scanf("%d", &n);
    printf("n = %d\n", n);
    while (n--) {
        scanf("%s", str);
        char_id=0;
        while (str[char_id]!='\0') {
            dict[(str[char_id]-'a')%26]++;
            char_id++;
        }
    }
    for (int i=0; i<26; i++) {
        //printf("dict[%d] = %d\n", i, dict[i]);
        if (dict[i]) 
            printf("%c", 'a'+i);
    }
    printf("\n");
    return 0;
}