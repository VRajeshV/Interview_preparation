/*printing of even and odd numbers by different threads*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

static int var = 1;
//sem_t lock;
pthread_mutex_t lock;

// void *print_even(void * arg)
// {
//     while(var <= 200)
//     {
//         //sem_wait(&lock);
//         pthread_mutex_lock(&lock);
//         printf("%d\n", var++);
//         //sem_post(&lock);
//         pthread_mutex_unlock(&lock);
//     }
//     pthread_exit(NULL);
// }

// void *print_odd(void * arg)
// {
     
//      while(var <= 199)
//      {
//         //sem_wait(&lock);
//         pthread_mutex_lock(&lock);
//         printf("%d\n", var++);
//         pthread_mutex_unlock(&lock);
//         //sem_post(&lock);
//      }
//     pthread_exit(NULL);
// }

void * thread(void * arg)
{
    while(var <= 200)
    {
        pthread_mutex_lock(&lock);
      //  printf("%d locking...\n", (int)pthread_self());
        printf("%d\n", var++);
      //  printf("%d unlocking...\n", (int)pthread_self());
        pthread_mutex_unlock(&lock);
        /*sleeping for 100 microseconds*/
        usleep(100);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t tid1, tid2;
    int ret = 0;

    //sem_init(&lock, 0, 1);
    pthread_mutex_init(&lock, NULL);
    // ret = pthread_create(&tid1, NULL, print_odd, NULL);
    // if(ret)
    //     perror("pthread_create:");

    // ret = pthread_create(&tid2, NULL, print_even, NULL);
    // if(ret)
    //     perror("pthread_create:");
   
      ret = pthread_create(&tid1, NULL, thread, NULL);
    if(ret)
        perror("pthread_create:");

    ret = pthread_create(&tid2, NULL, thread, NULL);
    if(ret)
        perror("pthread_create:");
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    //sem_destroy(&lock);
    pthread_mutex_destroy(&lock);
    return 0;
}
