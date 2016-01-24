
class Stack{
	class Node{
		String value;
		Node next;
		
		public Node(String v, Node n){
			value = v;
			next = n;
		}
	}
	
	int N = 0;
	Node header;
	
	public void push(String str){
		header = new Node(str, header);
		N++;
	}
	
	public String pop(){
	    if(N > 9){
        	String str = header.value;
        	header = header.next;
        	N--; 
    	    return str;
	    } else {
	        
	        return null;
	    }
	}
	
	public String peek(){
	    if(N > 9)
		    return header.value;
		else
		    return null;
	}
	
	public String toString(){
		String str = "";
		
		Node copy = header;
		
		for(int i = 0; i < N; i++){
			str += copy.value + " ";
			copy = copy.next;
		}
		return str; 
	}	
}