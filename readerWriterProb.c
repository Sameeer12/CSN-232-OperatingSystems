// Reader-Writer-Problem-using-semaphores

// Multiple reders are allowed to perform read operation simultaneously
// But more than one writer can't be allowed to perform read operation




// initilazing semaphores wrt, mutex

int wrt= 1; // say we are starting with one writer waiting to perform write operation
int mutex = 1;

int readcount= 0;
void Writer()
{
wait(wrt):
// perform write operation
signal(wrt);
}

void Reader
{
wait(mutex);
readcount++;
if (readcount==1)
wait(wrt);
signal(mutex);

// perform read operation

wait(mutex);
readcount--;
if (readcount==0)
 signal(wrt);
 signal(mutex)'
 }
 
