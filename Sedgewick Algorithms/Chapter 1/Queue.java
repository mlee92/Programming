
class Queue{
	
	class Node{
		String val;
		Node next; 
		
		public Node(String s, Node n){
			val = s;
			next = n;
		}
	}
	
	private Node first;
	private Node last;
	public int N = 0;
	
	public Queue(){
		
	}
	
	public void enqueue(String str)
	{ 
		Node oldlast = last;
		last = new Node(str, null);
		if (isEmpty()) first = last;
		else oldlast.next = last;
		N++;
	}
	
	public String dequeue(){
		String val = first.val;
		first = first.next;
		if(isEmpty()) last = null; 
		N --; 
		return val;
	}
	
	public boolean isEmpty(){
		return first == null;
	}
	
	public int getSize(){
		return N; 
	}
	
	public void printK(int k){
		Node copy = first;
		for(int i = 1; i < k; i++){
			copy = copy.next; 
		}
		System.out.println("The " + k + "th from the last string is " + copy.val);
	}
	
	public String toString(){
		String str = "";
		Node copy = first; 
		for(int i = 1; i < N; i++){
			str += copy.val + " ";
			copy = copy.next;
		}
		str += last.val;
		return str; 
	}
	
	public static void main(String[] args){
		Queue q = new Queue();
		q.enqueue("33");
		q.enqueue("44");
		System.out.println(q.toString());
	}
	
}