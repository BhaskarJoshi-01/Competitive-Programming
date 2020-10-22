public class Prime {
  public static boolean isPrime(int num) {
  if(num>1){ int i =2;
    while(i*i<=num)
      {
       if(num % i==0)
         return false;
       i++;
    }
    return true;}
    else return false;
    
}}
