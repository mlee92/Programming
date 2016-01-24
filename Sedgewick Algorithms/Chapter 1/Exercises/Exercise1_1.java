import java.util.*;

class Exercise1_1{
	public static boolean ThreeIntEqual(int a, int b, int c){
		return (a == b) && (b == c);
	}
	
	public static boolean DoubleXYRange(double x, double y){
		return (0 <= x) && (x <= 1) && (0 <= y) && (y <= 1); 
	}
	
	public static String toBinaryString(int N){
		String str = "";
		for(int n = N; n > 0; n/= 2){
			str = ((n) % 2) + str; 
		}		
		return str; 
	}
	
	public static void print2DBoolArr(boolean[][] mat){
		for(boolean[] row : mat){
			for(boolean b : row){
				if(b)
					System.out.print("*");
				else 
					System.out.print(" ");
			}
			System.out.println();
		}
	}
	
	public static boolean[][] transponseBoolMat(boolean[][] mat, int N, int M){
		boolean[][] trans = new boolean[M][N];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				trans[j][i] = mat[i][j]; 
			}
		}
		return trans; 
	}
	
	public static int lg(int N){
		int len = 0; 
		for(int n = N; n != 1; n/= 2){
			len ++; 
		}		
		return len; 
	}
	
	public static int[] histogram(int[] a, int M){
		int[] arr = new int[M]; 
		for(int i = 0; i < M; i++){
			arr[i] = i * a[i]; 
		}
		return arr; 
	}
	public static double lnFact = 0.0; 
	public static void lnNfactorial(int N){
		if(N > 1){
			lnFact += Math.log(N);
			lnNfactorial(N - 1); 
		}
	}
	
	public static void sortThree(int a, int b, int c){
	    if(a <= b && b <= c){
	        System.out.println(a + ", " + b + ", " + c); 
	    } 
	    else {
	       if(b < a) 
	            sortThree(b, a, c);
	       else if(c < b){
	           sortThree(a, c, b);
	       }
	    }
	}
	

	public static void main(String[] args){
		System.out.println(ThreeIntEqual(0, 0, 0));
		System.out.println(ThreeIntEqual(0, 2, 0));
		
		System.out.println(DoubleXYRange(0.2, 0.3));
		System.out.println(DoubleXYRange(0.2, 1.2));
		
		System.out.println(toBinaryString(5));
		System.out.println(toBinaryString(16));
		
		boolean[][] bMat = {{false, true, false}, {true, true, true}, {true,false,true}};
		
		print2DBoolArr(bMat);
		print2DBoolArr(transponseBoolMat(bMat, 3, 3));
		
		System.out.println(lg(10));
		
		int[] hist = {2, 3, 5, 7}; 
		System.out.println(Arrays.toString(histogram(hist, hist.length))); 
		lnNfactorial(5);
		System.out.println(lnFact);
		
		sortThree(3, 2, 1);
		
		System.out.println(binomial(3, 2, 0.25));
	}
}