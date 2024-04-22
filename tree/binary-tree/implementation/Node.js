
/**
 * class to create a node for data structures binary tree.
 */
export default class Node {

  /**
   * @type {any}
   */
  data

  /**
   * @type {Node | null}
   */
  left

  /**
   * @type {Node | null}
   */
  right

  /**
   * @param {any} data
   * @param {Node | null} left
   * @param {Node | null} right
   */
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}