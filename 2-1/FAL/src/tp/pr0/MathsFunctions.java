package tp.pr0;

public class MathsFunctions {
	
	
	public static int factorial (int n) {
		int factorial =1;
		if(n>0) {
			while(n>0) {
				factorial*=n;
				n--;
			}
		} else if(n<0){
			factorial=0;
		}
		return factorial;
	}

	
	public static int combinatorial (int n, int k) {
		int comb;
		
		if(k<0 || n<0) {
			comb= -1;
		} else if(k>n) {
			comb= 0;
		}else {
			comb=factorial(n)/(factorial(k)*factorial(n-k));
		}
		
		return comb;
	}
};

//comb = factorial(n)/(factorial(k)*factorial(n-k));

