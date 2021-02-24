// Sleeping-Barber's-Problem-using-Semaphores
// Barber sleeps if no customers waiting
// Customers leave if no chairs for waiting
// Waiting customers can't leave until haircut done.
     
int mutex = 1;
int barber_sleeping=1;
int customer_queue=0; 
int cut_done =0;

int wait(int S){
while(S<=0);   // busy waiting
return S--;
}

int signal(S){
return S++;
}


Barber Code

wait(mutex)
if (customers_waiting == 0) {
  signal(mutex);
  wait(barber_sleeping);
  wait(mutex);
}
customers_waiting--;
signal(mutex);
signal(customer_queue);
do_cut_hair();
signal(cut_done);


Customer Code
wait(mutex);
if (customers_waiting == n) {
   signal(mutex);
   return;
}
customers_waiting++;
if (customers_waiting == 1) {
  signal(barber_sleeping);
}
signal(mutex);
wait(customer_queue);
get_hair_cut();
wait(cut_done);
