//
//  11814_EKO.cpp
//
//
//  Created by Haijun Deng on 13-5-31.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Eko
 Input:
 4 7
 20 15 10 17
 Output:
 15

 Input:
 5 20
 4 42 40 26 46
 Output:
 36

 Input:
 254 32039
 0 356 7 215 200 137 492 401 348 208 367 138 178 216 472 60 322 173 52 92 38 216 479 271 247 486 108 189 197 140 251 69 258 482 278 454 328 220 346 32 378 350 248 77 111 163 392 25 259 378 400 162 486 402 337 452 437 208 61 477 398 348 200 8 83 82 254 203 53 138 321 424 248 93 448 186 161 385 109 223 118 439 305 187 194 430 292 465 258 165 434 129 129 89 173 1 371 420 139 351 202 405 370 218 38 205 169 355 156 399 75 296 478 121 469 57 492 316 299 451 287 122 430 37 219 379 122 189 198 263 135 290 104 39 447 55 326 450 115 474 423 220 246 384 417 191 97 163 206 76 309 49 102 346 252 91 495 235 2 212 144 376 445 410 88 54 5 75 188 94 489 436 290 364 72 128 14 413 391 395 166 225 277 401 281 101 103 182 286 172 264 212 286 25 273 103 481 466 496 419 204 402 494 129 87 347 8 169 346 55 54 145 199 279 155 147 403 154 187 200 420 204 362 329 203 475 322 258 111 291 374 228 452 141 333 445 140 184 7 147 492 380 290 302 134 254 396 428 46 270 207 36 225 349
 Output:
 139

 Input:
 5 5
 5 2 1 3 1
 Output:
 1
 */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long n,m;
    scanf("%ld %ld", &n, &m);
    vector<long> woods(n,0);
    long highest=0;
    long long total=0;
    for (int i=0; i<n; i++)
    {
        scanf("%ld", &woods[i]);
        if(highest<woods[i])
            highest=woods[i];
        total+=woods[i];
    }
    if(m==0)
        printf("%ld\n",highest);
    else if(m==total)
        printf("0\n");
    else if(m<total)
    {
        long highend=highest;
        long lowend=0;
        long search=(highend+lowend)/2;
        long long cut=0;
        for (int i=0; i<n; i++)
        {
            if(woods[i]>search)
                cut+=(woods[i]-search);
        }
        while (true)
        {
            //printf("cut = %ld, search = %ld, highend = %ld, lowend = %ld\n", cut, search,highend,lowend);
            if (cut==m)
            {
                printf("%ld\n",search);
                break;
            }
            else if((highend-lowend)==1)
            {
                printf("%ld\n",lowend);
                break;
            }
            else if(cut>m)
            {
                lowend = search;
            }
            else if(cut<m)
            {
                highend = search;
            }
            search=(highend+lowend)/2;
            cut=0;
            for (int i=0; i<n; i++)
            {
                if(woods[i]>search)
                    cut+=(woods[i]-search);
            }
        }
    }
    return 0;
}
