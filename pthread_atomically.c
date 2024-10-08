#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

long long global_var = 0; 

// child 每個執行 1000萬次
void *child(void *arg) {
    for (long long i = 0; i < 10000000; i++) {
       atomic_fetch_add(&global_var, 1);
        
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];  // 定義 10 個執行緒

    // 創建 10 個子執行緒
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, child, NULL);
    }

    // 等待所有執行緒完成
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Global variable value: %lld\n", global_var);

    printf("按任意鍵結束程式...\n");
    getchar(); // 等待使用者按下任意鍵後才結束


    return 0;
}