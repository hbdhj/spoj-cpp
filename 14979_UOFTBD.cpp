//
//  14979_UOFTBD.cpp
//  
//
//  Created by Haijun Deng on 13-5-22.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 Input:
 8
 aa bb
 Somebody's Something of Whatever
 stone of jordan
 Wirt's Leg
 FLAMING TURNIP
 Damaged Goods
 Sword
 Fish shaped volatile organic compounds
 
 Output:
 Set
 Magic
 Set
 Not sure, take anyways
 Normal
 Normal
 Normal 
 Explanation of Sample:
 The first and third items begin with possessives, so they must be Set items. The second item is three words long, and ends in "of [something]" so it must be Magic. The fourth item could be either Rare or Magic. The fifth item begins with "Damaged" so it's Normal. The last two items don't fit the descriptions of Set, Rare, or Magic, so they must be Normal also.
 1. Set items always belong to some famous dead person, so they always begin with a word that ends in "'s" (e.g. Andrew's). No other items are special enough to begin this way.
 2. Rare items always have names that are two words long.
 3. Magic items always have names that are between two and four words long. If, and only if, a Magic item has more than two words in its name, then the last two words are "of [something]" (e.g. of Doom).
 4. If the first word is "Damaged", the item is a Normal item. Furthermore, any item that could not possibly be Magic, Rare, or Set must also be Normal. No other items are Normal.
 You may not have played Diablo, but hopefully you still know that a "word" is a maximal substring of non-space characters. Also, letter case is irrelevant.
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int t;
    string tmp;
    cin>>t;
    getline(cin, tmp);
    while (t--)
    {
        string str, word;
        getline(cin, str);
        int i=0;
        while(str[i])
        {
            str[i]=tolower(str[i]);
            i++;
        }
        //printf("input = %s", str.c_str());
        vector<string> words;
        stringstream ss(str);
		while(ss >> word) 
        {
            words.push_back(word);
        }
        bool bSet=false, bMagic=false, bRare=false;
        if((words.size()>1)&&(words[0][words[0].length()-1]=='s')&&(words[0][words[0].length()-2]=='\'') )
        {
            bSet=true;
        }
        if((words.size()==2)&&(words[0]!="damaged"))
        {
            bRare=true;
            //if(words[words.size()-2]!="of")
                bMagic=true;
        }
        if((words.size()>2)&&(words.size()<5)&&(words[words.size()-2]=="of"))
        {
            bMagic=true;
        }
        if(words[0]=="damaged")
            bRare=bMagic=false;
        if(bSet)
            cout<<"Set"<<endl;
        else
        {
            if(bMagic&&!bRare)
            {
                cout<<"Magic"<<endl;
            } 
            else if(!bMagic&&bRare)
            {
                cout<<"Rare"<<endl;
            } 
            else if(bMagic&&bRare)
            {
                cout<<"Not sure, take anyways"<<endl;
            } 
            else
            {
                cout<<"Normal"<<endl;
            }    
        }
    }
    return 0;
}