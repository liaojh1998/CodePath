public class LinkedListNodeImpl<E> implements LinkedListNode<E>{
	//Objects
	private E value;
	private LinkedListNode<E> next;
	//Methods
	public E getValue(){return value;}
	public void setValue(E value){this.value = value;}
	public LinkedListNode<E> getNext(){return next;}
	public void setNext(LinkedListNode<E> next){this.next = next;}
	public void setValuesFromArray(E[] listValues){
		LinkedListNode<E> cur = this;
		for(int i = 0; i < listValues.length; i++){
			cur.setValue(listValues[i]);
			LinkedListNode<E> temp = new LinkedListNodeImpl<E>();
			cur.setNext(temp);
			cur = temp;
		}
	}
}