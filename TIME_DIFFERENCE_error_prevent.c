#include <stdio.h>
#include <stdlib.h>

//將時間轉換成秒
int TimeToSecond(int time) {
    int hours = time / 10000;  //取得小時
    int mins = (time % 10000) / 100; //取得分鐘
    int secs = time % 100;  //取得秒

    return hours * 3600 + mins * 60 + secs;  //總秒數
}

//取得時間並避免輸入的時間有問題
int getTime(const char* promt){
    int time;
    while(1){
        printf("%s", promt);
         if(scanf("%d", &time) !=1 || time < 0){
            printf("輸入錯誤，請再次輸入\n");
            while (getchar() != '\n');  // 清除緩衝區中的不正確輸入
            continue;
        }
        else {
            while (getchar() != '\n');  // 清除多餘的換行符
            return time;
        }
    }

}

int main() {
    int time1, time2;
    
    time1 = getTime("請輸入第一個時間(以正整數表示): ");
    time2 = getTime("請輸入第二個時間(以正整數表示): ");

    int second1 = TimeToSecond(time1);
    int second2 = TimeToSecond(time2);

    int difference = abs(second1 - second2);
    printf("兩個時間的秒數差為: %d 秒\n", difference);
    
    printf("按任意鍵結束程式...\n");
    getchar(); // 等待使用者按下任意鍵後才結束

    return 0;
}