import java.util.*;

public class hindex_db {
  public static void main(String[] args) {
    new hindex_db().run();
  }
  
  void run() {
    Scanner in = new Scanner(System.in);

    int n = in.nextInt();
    int[] A = new int[n];

    for(int i=0;i<n;i++)
      A[i] = in.nextInt();

    Arrays.sort(A);
    
    int H = 0;
    for(int i=0;i<n;i++)
      if(A[n-1-i] >= i+1)
	H = i+1;

    System.out.println(H);
  }
}
