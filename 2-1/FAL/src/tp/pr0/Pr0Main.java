package tp.pr0;

public class Pr0Main {

   public static void writeGreeting(String name) {
      System.out.println("Hello, " + name);
   }

   public static void main(String args[]) {
      //Pr0Main.writeGreeting("Bender Bending Rodríguez");
	   for (int i = 0; i < 6; ++i) {
			  for (int j = 0; j <= i; ++j) {
				  System.out.print(MathsFunctions.combinatorial(i,j) + " ");
			  }
			  System.out.println();
		 }
   }
}