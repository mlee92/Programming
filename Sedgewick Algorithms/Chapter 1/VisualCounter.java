
class VisualCounter{
	private int count;

	public VisualCounter(int N, int max){
		while(N != 0){
			if(count == max)
				break; 
			int incDec = (int)(Math.Random() * 2); 
			if(incDec == 1) { increment(); }
			else if(incDec == 0) { decrement(); }
			N --;
		}
		System.out.println("N = " + N + ", max = " + max + ", " + count); 
	}
	
	public void increment(){
		count++;
	}
	
	public void decrement(){
		count --;
	}
	
	public static void main(String[] args){
		VisualCounter vc = new VisualCounter(200, 50); 
	}
}