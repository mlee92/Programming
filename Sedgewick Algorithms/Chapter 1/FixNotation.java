class FixNotation{
	
	public static String convertRPN(String infix){
		int index = 0;
		String RPN = "";
		Stack ops = new Stack();
		
		while(index < infix.length()){
			String sub = infix.substring(index, index + 1);
			System.out.println(sub);

			int prec = precedence(sub);
			if(prec < 0){
				RPN += sub + " "; 
			} else {

			    if(precedence(sub) == 5){
					while(ops.N > 0 && ops.peek() != null && precedence(ops.peek()) != 1){
						RPN += ops.pop() + " ";
					}
    			}

    			while(ops.N > 0 && ops.peek()!= null && precedence(ops.peek()) < precedence(sub)){
    				RPN += ops.pop() + " ";
    			}
				
				ops.push(sub);
			}
			index++;
		}
		RPN += ops.toString(); 
		RPN = RPN.replace("(", "");
		RPN = RPN.replace(")", "");
		return RPN;

		}
		
	
	public static int precedence(String c){
		int ret = -1;
		if(c.equals("="))
			ret = 0;
		if(c.equals("("))
			ret = 1;
		if(c.equals("-") || c.equals("+"))
			ret = 2;
		if(c.equals("*") || c.equals("/"))
			ret = 3; 
		if(c.equals("^"))
			ret = 4; 
		if(c.equals(")"))
			ret = 5;
		return ret; 
	}
		
	public static void main(String[] args){
	    System.out.println(precedence("*"));
		System.out.println(precedence("-"));
		System.out.println(precedence("c"));
		System.out.println(convertRPN("a+b*(c-d)"));
	}

}