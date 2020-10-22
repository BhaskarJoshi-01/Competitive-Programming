public class ClockwiseOpener {

    public static int[] snail(int[][] array) {
      int w=0;
      int[] B = {};
       int[] A = new int[(array.length) *(array.length)];
     if(array.length == 1&& array[0].length==0)
       {
       return B;
       }
       
     else if (array.length!=0)
      while(w<array.length*array.length)
      for(int i=0;i<array.length;i++){
        
           
        for(int k =i;k<array.length - i;k++)
         
        { A[w]=array[i][k];
          w++;
          
        }
         
        for(int k=i+1;k<array.length-i;k++)
        {  A[w]= array[k][array.length-i-1];
           w++;
        }
         for(int k=1+i;k<array.length-i;k++)
          {
           A[w]=array[array.length -i-1][array.length -1- k]; 
             w++;
        }
       for(int k =i+1; k<array.length -i-1;k++)
         
          {A[w]= array[array.length - k -1][i];
          w++;
          
          
           
        } 
        }
     

return A;}}