/* buffer.h */
typedef int buffer_item;
#define BUFFER_SIZE 25
 
/* main.c */
 
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
 
#define TRUE 1
 
/* The mutex lock */
pthread_mutex_t mutex;
 
/* the semaphores */
sem_t full, empty;
 
/* the buffer */
buffer_item buffer[BUFFER_SIZE];
 
/* buffer counter */
int counter;

int numberToBeProduced;
int numberProduced = 0;
int runningThreads = 0;
 
pthread_t tid,tid0, tid1;
       //Thread ID
pthread_attr_t attr; //Set of thread attributes
 
void *producer(void *param); /* the producer thread */
void *consumer0(void *param); /* the consumer thread */
void *consumer1f(void *param); /* the consumer thread */

 
void initializeData() {
 
   /* Create the mutex lock */
   pthread_mutex_init(&mutex, NULL);
 
   /* Create the full semaphore and initialize to 0 */
   sem_init(&full, 0, 0);
 
   /* Create the empty semaphore and initialize to BUFFER_SIZE */
   sem_init(&empty, 0, BUFFER_SIZE);
 
   /* Get the default attributes */
   pthread_attr_init(&attr);
 
   /* init buffer */
   counter = 0;
}
 
/* Producer Thread */
void *producer(void *param) {
   buffer_item item;
 
   while(TRUE) {
      /* sleep for a random period of time
      int rNum = rand() / RAND_DIVISOR;*/
      sleep(1);

      /* acquire the empty lock */
      sem_wait(&empty);
      /* acquire the mutex lock */
      pthread_mutex_lock(&mutex);
      while(numberToBeProduced-1>=numberProduced){
      item = numberProduced;
         if(insert_item(item)) {
            fprintf(stderr, " Producer report error condition\n");
         }
         else {
            printf("producer produced %d\n", item);
         }
      numberProduced++;
      }
      /* release the mutex lock */
      pthread_mutex_unlock(&mutex);
      /* signal full */
      sem_post(&full);
   }
}
 
/* Consumer Thread */
void *consumer0(void *param) {
   buffer_item item;
   int consID = 0;
   int loopCheck = 1;
   //printf("loopbroken \n");
   while(loopCheck ==1) {
      /* sleep for a random period of time
      int rNum = rand() / RAND_DIVISOR;*/
      sleep(1);
 
      /* aquire the full lock */
      sem_wait(&full);
      /* aquire the mutex lock */
      pthread_mutex_lock(&mutex);
      if(remove_item(&item)) {
         fprintf(stderr, "Consumer report error condition \n");
         printf(" the item causing the error is %d \n",item);

      }
      else {

         printf("ConsumerID: %d. Item: %d.\n",consID, item);
      }

      if(item <= 0){
         printf("ConsumerID: %d. Nothing to consume. \n",consID);
         printf("The program will exit\n");
         exit(0);
      }

       /* release the mutex lock */
      pthread_mutex_unlock(&mutex);
      /* signal empty */
      sem_post(&empty);

   }
}

void *consumer1(void *param) {
   buffer_item item;
   int consID = 1;
   int loopCheck = 1;
   //printf("loopbroken \n");
   while(loopCheck ==1) {
      /* sleep for a random period of time
      int rNum = rand() / RAND_DIVISOR;*/
      sleep(1);
 
      /* aquire the full lock */
      sem_wait(&full);
      /* aquire the mutex lock */
      pthread_mutex_lock(&mutex);
      if(remove_item(&item)) {
         fprintf(stderr, "Consumer report error condition \n");
         printf(" the item causing the error is %d \n",item);

      }
      else {

         printf("consumerid: %d. item number: %d \n",consID, item);
      }
      //printf("looping: %d id: %d \n", item, consID);


      if(item <= 0){
         printf("ConsumerID: %d. Nothing to consume. \n",consID);
         printf("The program will exit\n");
         exit(0);
      }
      /* release the mutex lock */
      pthread_mutex_unlock(&mutex);
      /* signal empty */
      sem_post(&empty);
   }
}
 
/* Add an item to the buffer */
int insert_item(buffer_item item) {
   /* When the buffer is not full add the item
      and increment the counter*/
   if(counter < BUFFER_SIZE) {
      buffer[counter] = item;
      counter++;
      return 0;
   }
   else { /* Error the buffer is full */
      return -1;
   }
}
 
/* Remove an item from the buffer */
int remove_item(buffer_item *item) {
   /* When the buffer is not empty remove the item
      and decrement the counter */
   if(counter > 0) {
      *item = buffer[(counter-1)];
      counter--;
      return 0;
   }
   else { /* Error buffer empty */
      return -1;
   }
}
 
int main(int argc, char *argv[]) {
   /* Loop counter */
   int i;

 
   numberToBeProduced = 25;
 
   /* Initialize the app */
   initializeData();

   pthread_create(&tid,&attr,producer,NULL);   


   pthread_create(&tid0,&attr,consumer0,NULL);
   pthread_create(&tid1,&attr,consumer1,NULL);

   (void) pthread_join(tid0, NULL);
   (void) pthread_join(tid1, NULL);

   return(0);
}