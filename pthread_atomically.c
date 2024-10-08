#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>

long long global_var = 0;
bool flag = false;

// child 每個執行 1000萬次
void *child(void *arg) {

    while(!flag); //等待旗標

    for (long long i = 0; i < 10000000; i++) {
       atomic_fetch_add(&global_var, 1); //atomically加1
        
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, child, NULL);
    }

    flag = true; //開啟旗標

    
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Global variable value: %lld\n", global_var);

    printf("按任意鍵結束程式...\n");
    getchar(); 


    return 0;
}