
// class Node {
//   data = null;
//   next = null;

//   constructor(data){
//     if(data === undefined){
//       return;
//     }

//     this.data = data;
//     this.next = null;
//   }

//   // get next(){
//   //   this.next;
//   // }

//   // set next(node){
//   //   this.next = node;
//   // }
// }

// class LinkedList{
//   root = null;

//   constructor(rootData){
//     if(rootData === undefined){
//       return;
//     }
//     this.root = new Node(rootData);
//   }

//   print(){
//     let curr = this.root;
//     const result = [];

//     while(curr.next !== null){
//       result.push(curr.data);
//       curr = curr.next;
//     }

//     result.push(curr.data);
//     console.log(...result);
//   }

//   append(data){
//     const newNode = new Node(data);

//     if(this.root === null){
//       this.root = newNode;
//       return;
//     }
    
//     let curr = this.root;

//     while(curr.next !== null){
//       curr = curr.next;
//     }

//     curr.next = newNode;
//   }

//   push(data){
//     const newNode = new Node(data);

//     if(this.root === null){
//       this.root = newNode;
//       return;
//     }

//     const oldNext = this.root.next;
//     newNode.next = oldNext;
//     this.root.next = newNode;
//   }

// }

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

    const oldNext = this.root.next;
    newNode.next = oldNext;
    this.root.next = newNode;
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

  ll.push(0);
  ll.append(10);

  ll.print();

  ll.reverse();
  
  ll.print();
  console.log({length: ll.length})
})()