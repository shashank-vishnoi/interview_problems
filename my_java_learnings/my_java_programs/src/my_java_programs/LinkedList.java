package my_java_programs;

public class LinkedList {

  protected Node list;
  
  LinkedList()
  {
    list = null;
  }
  void insert(int data)
  {
    if(list == null)
      list = new Node(data);
    else{
      Node temp_list = list;
      while(temp_list.getNextNode() != null)
      {
        temp_list = temp_list.getNextNode();
      }
      temp_list.setNextNode(new Node(data));
    }
  }
  void delete(int val)
  {
    Node temp_list = list;
    Node prev_node=null;
    while((Integer)temp_list.getData() != val)
    {
      prev_node = temp_list;
      temp_list=temp_list.getNextNode();
    }
    if(temp_list == list)
      list=list.getNextNode();
    else{
      prev_node.setNextNode(temp_list.getNextNode());
      temp_list=null;
    }
    
  }
  
  void reverse()
  {
    Node prev = null;
    Node temp = list;
    while(temp != null)
    {
      Node temp_node = temp.getNextNode(); 
      temp.setNextNode(prev); 
      prev= temp; 
      temp=temp_node; 
     }
    list=prev;
  }
  
  boolean is_loop_exsist()
  {
    Node slow=list, fast=list;
    while(slow.getNextNode() != null && fast.getNextNode().getNextNode() != null)
    {
      slow=slow.getNextNode();fast=fast.getNextNode().getNextNode();
      if(slow == fast)
        break;
      
    }
    if(slow == fast)
      return true;
    return false;
  }
  
  boolean find_and_remove_loop()
  {
    if(is_loop_exsist() == false)
    {
      System.out.println("No loop found!");
      return false;
    }
    Node slow=list, fast=list;
    while(slow.getNextNode() != null && fast.getNextNode().getNextNode() != null)
    {
      slow=slow.getNextNode();fast=fast.getNextNode().getNextNode();
      if(slow == fast)
        break;
      
    }
    if(slow != fast)
      return false;
    slow=list;
    Node track_prev=null;
    while(slow != fast)
    {
      track_prev=fast;
      slow=slow.getNextNode();fast=fast.getNextNode();
    }
    System.out.println("Culprit node:" + slow.getData());
    track_prev.setNextNode(null);
        return false;
    
  }
  
  void display()
  {
    Node temp_list = list;
    while(temp_list != null)
    {
      System.out.println((temp_list.getData()));
      temp_list=temp_list.getNextNode();
    }
  }
  
  public static void main(String[] args) {
    // TODO Auto-generated method stub
    LinkedList list = new LinkedList();
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();
    System.out.println("----------------------------");
    //list.delete(40);
    list.reverse();
    list.insert(50);
    list.insert(60);
    list.display();
    list.list.getNextNode().getNextNode().getNextNode().getNextNode().getNextNode().setNextNode(list.list.getNextNode().getNextNode());
    System.out.println("After Making Loop->");
    //list.display();
    System.out.println("Loop:" + list.is_loop_exsist());
    list.find_and_remove_loop();
    System.out.println("After Removing Loop->");
    list.display();
  }

}
