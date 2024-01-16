class Node {
  constructor(data){
    this.data = data;
    this.next = null;
  }

}


class LinkedList{
  root = null;

  constructor(rootNodeData){

    if(rootNodeData === undefined){
      return;
    }

    this.root = new Node(rootNodeData);
  }

  append(data){
    const newNode = new Node(data);

    if(this.root === null){
      this.root = newNode;
      return;
    }

    let curr = this.root;

    while(curr.next !== null){
      curr = curr.next;
    }

    curr.next = newNode;
  }

  push(data){
    const newNode = new Node(data);

    if(this.root === null){
      this.root = newNode;
      return;
    }

    newNode.next = this.root;
    this.root = newNode; 
  }

  reverse(){
    if(this.root === null || this.root.next === null){
      return;
    }

    let curr = this.root;
    let prevNode = null;
    let nextNode = null;
    
    while(curr.next !== null){
      nextNode = curr.next;
      curr.next = prevNode;
      prevNode = curr;
      curr = nextNode;
    }

    curr.next = prevNode;
    this.root = curr;
  }

  print(){
    if(this.root === null){
      return;
    }

    let curr = this.root;
    const result = [];

    while(curr.next !== null){
      result.push(curr.data);
      curr = curr.next;
    }
    
    result.push(curr.data);
    console.info(...result);
  }

  get length(){
    if(this.root === null){
      return 0;
    }

    if(this.root.next === null){
      return 1;
    }

    let curr = this.root;
    let result = 0;

    while(curr !== null){
      result++;
      curr = curr.next;
    }

    return result;
  }

  insertAt(position, data){

    if(position < 1 || position > this.length + 1){
      throw new Error('Position must be between 1 and list\'s length + 1');
    }

    if(position === 1){
      this.push(data);
      return;
    }

    if(position === this.length + 1){
      this.append(data);
      return;
    }


    let curr = this.root;
    let pos = 1;
    let prev = null;

    while(curr.next !== null){
      if(pos === position){
        const newNode = new Node(data);
        newNode.next = prev.next;
        prev.next = newNode;
        return;
      }

      pos++;
      prev = curr;
      curr = curr.next;
    }

    if(pos === position){
      const newNode = new Node(data);
      newNode.next = prev.next;
      prev.next = newNode;
    }
  }

}

(() => {
  const ll = new LinkedList(1);
  ll.append(2);
  ll.append(3);
  ll.append(4);
  ll.append(5);
  ll.append(6);
  ll.append(7);
  ll.append(8);
  ll.append(9);

  ll.print();

  // ll.push(0);
  ll.append(10);

  ll.print();
  
  // ll.reverse();

  ll.insertAt(5, 100);
  
  ll.print();
  console.log({length: ll.length})
})()