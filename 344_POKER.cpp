//
//  344_POKER.cpp
//  
//
//  Created by Haijun Deng on 13-6-24.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 TASK: poker
 LOGIC: 
 1. royal flush - ace, king, queen, jack and ten, all in the same suit
 2. straight flush - five cards of the same suit in sequence, such as 10,9,8,7,6 of clubs; ace can be counted both as the highest card or as the lowest card - A,2,3,4,5 of hearts is a straight flush. But 4,3,2,A,K of hearts is not a straight flush - it's just a flush.
 3. four of a kind - four cards of the same rank, such as four kings.
 4. full house - three cards of one rank plus two cards of another rank
 5. flush - five cards of the same suit (but not a straight flush)
 6. straight - five cards in order - just like the straight flush, but mixed suits
 7. three of a kind - three cards of one rank and two other cards
 8. two pairs - two cards of one rank, two cards of another rank, and one more card
 9. pair - two cards of the same rank
 10. high card - none of the above
 
 Input:
 11
 AH KH QH TH JH
 AD 2D 3D 4D 5D
 2S 2H 2D 2C 4D
 QH QD 2S QC 2C
 4C 3C 2C AC KC
 4C 9C TC AC KC
 5H AS 2C 3D 4C
 5H 5D 5C 7H KS
 2H 2S 4C 4S 5D
 KH 5S 3C 5C 7D
 AH 4S 9C TD 3H
 
 Output:
 royal flush
 straight flush
 four of a kind
 full house
 flush
 flush
 straight
 three of a kind
 two pairs
 pair
 high card
 */
#include <iostream>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char card[4];
        int cards[5][16];
        memset(cards,0,sizeof(cards));
        int card_num=5;
        while (card_num--) 
        {
            scanf("%s", card);
            //printf("%c %c, ", card[0], card[1]);
            int c=0,n=0;
            switch (card[1]) {
                case 'H':
                    c=0;
                    break;
                case 'D':
                    c=1;
                    break;
                case 'C':
                    c=2;
                    break;
                case 'S':
                    c=3;
                    break;
                default:
                    /*printf("L78 ERROR!\n");
                    exit(1);*/
                    break;
            }
            cards[c][0]++;
            switch (card[0]) {
                case 'A':
                    cards[c][1]=1;
                    cards[c][14]=1;
                    cards[4][1]++;
                    break;
                case 'T':
                    cards[c][10]=1;
                    cards[4][10]++;
                    break;
                case 'J':
                    cards[c][11]=1;
                    cards[4][11]++;
                    break;
                case 'Q':
                    cards[c][12]=1;
                    cards[4][12]++;
                    break;
                case 'K':
                    cards[c][13]=1;
                    cards[4][13]++;
                    break;
                default:
                    n=card[0]-'0';
                    /*if ((n<2)||(n>9)) {
                        printf("L108 ERROR!\n");
                        exit(2);
                    }*/
                    cards[c][n]=1;
                    cards[4][n]++;
                    break;
            }
            cards[4][0]++;
        }
        
        //printf("\n");
        for (int i=0; i<5; i++) 
        {
            int max = 0;
            int cur = 0;
            
            if(cards[i][0]<2)
                cards[i][15]=cards[i][0];
            else
            {
                for (int j=1; j<15; j++) 
                {
                    if (cards[i][j]&&cards[i][j+1]) 
                        cur++;
                    else
                        cur=0;
                    if (cur>max)
                        max=cur;
                    //printf("cards[i][j] = %d, cards[i][j+1] = %d, cur=%d, max = %d\n", cards[i][j], cards[i][j+1], cur, max);
                }
                cards[i][15]=max+1;
            }
            
        }
        bool checked = false;
        /*for (int i=0; i<5; i++) 
        {
            for (int j=0; j<16; j++) 
            {
                printf("%d, ",cards[i][j]);
            }
            printf("\n");
        }*/
        for (int i=0; i<4; i++) 
        {
            if (cards[i][1]&&cards[i][10]&&cards[i][11]&&cards[i][12]&&cards[i][13])
            {
                printf("royal flush\n");
                checked = true;
                break;
            }
            else if ((cards[i][0]==5)&&(cards[i][15]==5))
            {
                printf("straight flush\n");
                checked = true;
                break;
            }
            else if (cards[i][0]==5)
            {
                printf("flush\n");
                checked = true;
                break;
            }
        }   
        if(!checked)
        {
            if (cards[4][15]==5)
            {
                printf("straight\n");
                checked = true;
            }
        }
        if (!checked)
        {
            int rands[5];
            memset(rands, 0, sizeof(rands));
            for (int i=1; i<14; i++)
            {
                if(cards[4][i])
                    rands[cards[4][i]]++;
            }
            /*for (int i=1; i<5; i++)
            {
                printf("rands[%d] = %d\n", i, rands[i]);
            }*/
            if (rands[4]) 
            {
                printf("four of a kind\n");
            }
            else if(rands[3]&&rands[2])
            {
                printf("full house\n");
            }
            else if(rands[3])
            {
                printf("three of a kind\n");
            }
            else if(rands[2]==2)
            {
                printf("two pairs\n");
            }
            else if(rands[2])
            {
                printf("pair\n");
            }
            else
            {
                printf("high card\n");
            }
        }
    }
    return 0;
}