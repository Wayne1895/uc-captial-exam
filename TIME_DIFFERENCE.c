#include <stdio.h>
#include <stdlib.h>

int TimeToSecond(int time) {
    int hours = time / 10000;  //取得小時
    int mins = (time % 10000) / 100; //取得分鐘
    int secs = time % 100;  //取得秒

    return hours * 3600 + mins * 60 + secs;  //總秒數
}

int main() {
    int time1, time2;
    printf("請輸入第一個時間(以正整數表示): ");
    scanf("%d", &time1);
    printf("請輸入第二個時間(以正整數表示): ");
    scanf("%d", &time2);

    int second1 = TimeToSecond(time1);
    int second2 = TimeToSecond(time2);

    int difference = abs(second1 - second2);

    printf("兩個時間的秒數差為: %d 秒\n", difference);
    
    printf("按任意鍵結束程式...\n");
    getchar(); // 這裡清除緩衝區中未讀取的換行符號
    getchar(); // 等待使用者按下任意鍵後才結束

    return 0;
}