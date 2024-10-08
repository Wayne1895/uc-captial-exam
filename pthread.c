#include <stdio.h>
#include <pthread.h>

long long global_var = 0; 
pthread_mutex_t mutex;  // 定義互斥鎖

// child 每個執行 1000萬次
void *child(void *arg) {
    for (long long i = 0; i < 10000000; i++) {
        
        pthread_mutex_lock(&mutex);// 互斥鎖上鎖

        global_var++;
        
        pthread_mutex_unlock(&mutex);// 解鎖
        
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];  // 定義 10 個執行緒
    pthread_mutex_init(&mutex, NULL);  // 初始化互斥鎖

    // 創建 10 個子執行緒
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, child, NULL);
    }

    // 等待所有執行緒完成
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Global variable value: %lld\n", global_var);

    
    pthread_mutex_destroy(&mutex);// 銷毀互斥鎖

    printf("按任意鍵結束程式...\n");
    getchar();


    return 0;
}