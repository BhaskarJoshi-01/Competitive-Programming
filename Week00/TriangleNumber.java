public class TriangleNumber {

  public static Boolean isTriangleNumber(long number) {
    int flag=0;
    for(int i =0;i<number;i++)
      {if(number ==i*(i+1)/2)
        flag= 1;}
       if(flag==1)
         return true;
       else 
         return false;
      
  }
    
}
