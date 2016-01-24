
class LinkedList{
	class Node{
		String val;
		Node next;
		
		public Node(String s, Node n){
			val = s;
			next = n;
		}
	}
	
	public static void delete(Node first){
		Node copy = first;
		first = null;
		while(copy.val != null){
			first = new Node(copy.val, first);
			copy = copy.next;
		}
	}
	
	public static void deleteK(int K, Node first){
		Node copy = first;
		first = null;
		while(copy.val != null && K > 0){
			first = new Node(copy.val, first);
			copy = copy.next;
			K --; 
		}
		copy = copy.next;
		while(copy.val != null){
			first = new Node(copy.val, first);
		}
	}
	
	public static boolean find(String key, Node first){
		while(first.val.indexOf(Key) == -1 && first.next != null){
			first = first.next; 
		}
		return first.val.indexOf(Key) != -1; 
	}
}