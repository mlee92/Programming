    
class LinkedList2{
	
	class Node{
		String val;
		Node next; 
		
		public Node(String s, Node n){
			val = s;
			next = n;
		}
	}
	
	public static void removeAfter(Node node){
		if(node.val == null || node.next == null){
			break;
		} else{
			node = node.next.next;
		}
	}
	
	public static void insertAfter(Node p, Node q){
		if(!(p == null) && !(q == null)){
			Node nNode = new Node(p.val, null);
			while(p.val != null){
				nNode = new Node(p.val, nNode);
			}
			nNode.next = q; 
		}
	}
	
	public static int max(Node first){
		int MX = 0; 
		int i = Integer.parseInt(first.val);
		
		if(MX < i) MX = i; 
		if(first.next != null){
			max(first.next);
		}
		return MX; 
	}
}