#include <stdio.h>
#include <time.h>
// 60000000 = 1m
#define endtime 240000 // 4m

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

int main(){
    SDL_Surface *window, *string; // ウィンドウを示すポインタを宣言
    //SDL_Surface *num[10];
    SDL_Surface *num;
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){ // エラー処理
        printf("failed to initialize SDL.\n");
        exit(-1);
    }
    
    if((window = SDL_SetVideoMode(320,240,32,SDL_SWSURFACE))==NULL){ //ウィンドウ生成
        printf("failed to initialize videomode.\n");
        exit(-1);
    }
    //SDL_FillRect(window, NULL, 0xffffff); // ウィンドウを白で
    SDL_FillRect(window, NULL, SDL_MapRGB(window->format,0,0,0)); // 黒に塗りつぶす
    //SDL_WM_SetCaption("中間報告会","timer"); // タイトルバー

    TTF_Font* font;
    font = TTF_OpenFont("LEMONCHI.ttf",24);
    SDL_Color white = {0xFF,0xFF,0xFF}; // フォントを白に指定
    /*num[0] = TTF_RenderUTF8_Blended(font,"0",white);
    num[1] = TTF_RenderUTF8_Blended(font,"1",white);
    num[2] = TTF_RenderUTF8_Blended(font,"2",white);
    num[3] = TTF_RenderUTF8_Blended(font,"3",white);
    num[4] = TTF_RenderUTF8_Blended(font,"4",white);
    num[5] = TTF_RenderUTF8_Blended(font,"5",white);
    num[6] = TTF_RenderUTF8_Blended(font,"6",white);
    num[7] = TTF_RenderUTF8_Blended(font,"7",white);
    num[8] = TTF_RenderUTF8_Blended(font,"8",white);
    num[9] = TTF_RenderUTF8_Blended(font,"9",white); */
    num = TTF_RenderUTF8_Blended(font,"0",white);

    SDL_Rect src_rect = {0,0,num->w,num->h}; // コピー元
    SDL_Rect dst_rect = {0,0}; // コピー先
    SDL_BlitSurface(num,&src_rect,window,&dst_rect);

    SDL_UpdateRect(window,0,0,320,240); // 更新
    SDL_Flip(window);

    clock_t start, end, judge;
    int i, flag, endflag;
    flag = 1;
    endflag = 1;

    while(endflag){
        start = clock();
        while(flag){
            judge = clock();
            if(judge >= start + 1000){ // 一秒毎
                flag = 0; // ループを抜ける
            }
        }
        if(start >= 60000000){
            endflag = 0;
        }
        flag = 1;
    }
    printf("１分\n");
    TTF_CloseFont(font);
    SDL_FreeSurface(window); // サーフェースを解放
    SDL_Quit(); // 終了処理
    return 0;
}
