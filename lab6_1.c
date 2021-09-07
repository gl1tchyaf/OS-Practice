#include<stdio.h>
#include<pthread.h>

int arr[50];
pthread_mutex_t lock;
pthread_cond_t cond;
int count = 0;
void * store(void * n){
    int i;
    pthread_mutex_lock(&lock);
    while(count>2){
    	printf("Waiting");
    	pthread_cond_wait(&cond,&lock);
    }
    printf("Adding the values to array from 1 to n \n");
    for(i=0;i<50;i++){
        arr[i]=i;
       count++;
    }
    pthread_mutex_unlock(&lock);
}
void * print(void * n){
    int i;
    pthread_mutex_lock(&lock);
    pthread_cond_signal(&cond);
    printf("Printing the values:\n ");
    for(i=0;i<50;i++){
        printf("%d ",arr[i]);
       count--;
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
}
int main()
{
    pthread_t tid,tid2;
    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_create(&tid,NULL,&store,NULL);
    pthread_create(&tid2,NULL,&print,NULL);

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}
