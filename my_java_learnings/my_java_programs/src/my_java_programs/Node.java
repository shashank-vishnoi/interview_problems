package my_java_programs;

public class Node {
  
  private Object data;
  private Node next;
  
  Node()
  {
    next=null;
    data=null;
  }
  Node(Object d)
  {
    data=d;
    next=null;
  }
  
  void setData(Object d)
  {
    data = d;
  }
  Object getData()
  {
    return data;
  }
  
  void setNextNode(Node node)
  {
    next = node;
  }
  Node getNextNode()
  {
      return next;
  }

}
