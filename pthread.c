#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

long long global_var = 0;
bool flag= false; 
pthread_mutex_t mutex;  // 定義互斥鎖

// child 每個執行 1000萬次
void *child(void *arg) {

    while(!flag); //等待旗標

    for (long long i = 0; i < 10000000; i++) {
        
        pthread_mutex_lock(&mutex);// 互斥鎖上鎖

        global_var++;
        
        pthread_mutex_unlock(&mutex);// 解鎖
        
    }
    pthread_exit(NULL);
}

int main() {
    clock_t start_time = clock();

    pthread_t threads[10];  //宣告10個執行緒陣列
    pthread_mutex_init(&mutex, NULL);  // 初始化互斥鎖

    //創建10個執行child函數的執行緒
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, child, NULL);
    }

    flag = true;

    // 等待所有執行緒完成
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Global variable value: %lld\n", global_var);

    
    pthread_mutex_destroy(&mutex);// 銷毀互斥鎖

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("程式執行時間: %.2f 秒\n", time_taken);
    
    printf("按任意鍵結束程式...\n");
    getchar();


    return 0;
}