#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int sum=0;
sem_t lock;
void * runner(void * any)
{
    int n,i=0;
    printf("\nChild Thread\n");
    printf("Enter n: ");
    scanf("%d",&n);
    sem_wait(&lock);
    for(i=0;i<n+1;i++){
    	sum=sum+i;
    }
    sem_post(&lock);
    printf("Sum: %d\n",sum);
}
int main()
{
    void *sum1,*sum2;
    int i=0,num;
    sem_init(&lock,0,2);
    printf("Enter how many thread you want: ");
    scanf("%d",&num);
    pthread_t tid[num];
    printf("\nMain thread\n");
    for(i=0;i<num;i++){
    	pthread_create(&tid[i],NULL,&runner,NULL);
    	pthread_join(tid[i],NULL);
    }
    
    

    
    return 0;
}
