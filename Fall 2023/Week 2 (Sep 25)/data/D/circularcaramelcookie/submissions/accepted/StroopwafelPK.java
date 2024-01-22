import java.util.*;
public class StroopwafelPK{

   public static void main(String [] args){
      Scanner ir = new Scanner(System.in);
      int  testcase = ir.nextInt();
      StroopwafelPK str = new StroopwafelPK(testcase);
      System.out.println(str.solution());
   }

   static int squares(int r2){
      //number of squares in a circle with square radius r2
      int r = (int) Math.sqrt(r2);
      int count = 0;
      int x = r;
      for (int y = 1; y <= r; y++){
         int y2 = y * y;
         while  (x * x + y2 > r2)
            x--;
         count += x;
      }
      return 4 * count;
   }

///////////////////////////////////////////////////

   int sq;

   public StroopwafelPK (int sqIn){
      sq = sqIn + 1;
   }

   double solution(){
      int low2 = (int) (sq/ Math.PI);
      int high2 = low2 + 2 * (int) Math.sqrt(low2) + 2;
      while (high2 > low2 + 1){
         int mid = (high2 + low2)/2;
         if (squares(mid) < sq)
            low2 = mid;
         else high2 = mid;
      }
      return Math.sqrt(high2);
   }

}