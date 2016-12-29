public interface LinkedListNode<E> {

    /* getter/setter for this node's value */
    E getValue();
    void setValue(E value);

    /* getter/setter for the subsequent node, or null if this is the last node */
    LinkedListNode<E> getNext();
    void setNext(LinkedListNode<E> next);

    /**
     * Initialize this node and all of its subsequent nodes from
     * an array of values, starting with the head value at index 0
     *
     * @param listValues - the ordered values for the whole list
     */
    void setValuesFromArray(E[] listValues);

}