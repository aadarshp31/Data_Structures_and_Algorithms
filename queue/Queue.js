

export default class Queue {
  /**
   * @type {Array<any>}
   */
  list;

  constructor() {
    this.list = [];
  }

  /**
   * Check whether the queue is empty
   * @returns {boolean} boolean indicating whether the queue is empty
   */
  empty() {
    return this.list.length === 0;
  }


  /**
   * Gets the front item in the queue
   * @returns {*} item present in the front of the queue
   */
  front() {
    return this.list[0];
  }

  /**
   * Adds an item to the queue
   * @param {any} item item to be put on queue
   */
  enque(item) {
    if (!item) {
      return;
    }

    this.list.push(item);
  }

  /**
   * Removes first added item from the queue
   * @returns {*} element present in the front of the queue
   */
  dequeue() {
    return this.list.shift();
  }
}