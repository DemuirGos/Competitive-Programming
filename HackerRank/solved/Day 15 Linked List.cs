

	public static  Node insert(Node head,int data)
	{
            if(head==null){
                head=new Node(data);
                return head;
            }
            else if(head.next == null){
                head.next=new Node(data);
                return head;
            }
            else {
                insert(head.next,data);
            }
            return head;
    }

