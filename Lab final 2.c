#include<stdio.h>
#include<pthread.h>

int a,b,c;
long int sum=0;

void * input(){

    printf("Enter two number: ");
    scanf("%d%d",&a,&b);

}
void * choice(){

    int c;
    printf("Enter choice: 1 to qdd and 2 to sub");
    scanf("%d",&c);

}
void * calc(){

    if(c==1){
    sum=a+b;
    return (void *) sum;
}
    else if(c==2){
    sum=a-b;
    return (void *) sum;
}
    else{
    printf("Wrong Input");
}

}

int main()
{
    void *out;
    pthread_t tid,tid2,tid3;
    pthread_create(&tid,NULL,&input,NULL);
    pthread_create(&tid2,NULL,&choice,NULL);
    pthread_create(&tid3,NULL,&calc,NULL);
    printf("\nMain thread\n");

    pthread_join(tid,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,&out);
    printf("%ld\n",(long)out);
    return 0;
}