public class MatrixAdd {
  public static int[][] matrixAddition(int[][] a, int[][] b) {
    for(int i=0;i<a.length;i++)
      for(int j =0;j<a.length;j++)
        {
         a[i][j]=a[i][j]+b[i][j];
        }
    return a;
  }
}
