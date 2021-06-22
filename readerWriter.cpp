#include <pthread.h>
#include <stdio.h>
using namespace std;

int wrt;
int mutex;
int cnt;
int numreader;

void wait(int &s)
{
    while(s<=0);
    s--;
}

void signal(int &s)
{
    ++s;
}

void *writer(void *wno)
{   
    wait(wrt);
    cnt = cnt*2;
    printf("Writer %d modified cnt to %d\n",(*((int *)wno)),cnt);
    signal(wrt);
    return NULL;
}
void *reader(void *rno)
{   
    wait(mutex);
    numreader++;
    if(numreader == 1)
        wait(wrt); 
    
    signal(mutex);
    
    printf("Reader %d: read cnt as %d\n",*((int *)rno),cnt);

    
    wait(mutex);
    numreader--;
    if(numreader == 0)
        signal(wrt); 
    
    signal(mutex);
    return NULL;
}

int main()
{   
    wrt=1;
    mutex=1;
    cnt=1;
    numreader=0;
    pthread_t read[10],write[5];

    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

    for(int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, reader, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, writer, (void *)&a[i]);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    // pthread_mutex_destroy(&mutex);
    // sem_destroy(&wrt);

    return 0;
    
}