import readline from "node:readline/promises";
import Node from "./Node.js";
import Queue from "../../../queue/Queue.js";


/**
 * Implementation of Binary Tree data structure
 * @author aadarshp31
 */
export default class BinaryTree {

  /**
   * private method to help write output
   */
  static #prompt = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  /**
   * Root node of the binary tree
   * @type {Node | null}
   */
  root;

  constructor(rootNode = null) {
    this.root = this.#buildTree(rootNode);
  }

  /**
   * Method to create binary tree
   * @param {Node | null} rootNode root node of the input 
   */
  #buildTree(rootNode) {
    if (rootNode === null) {
      return null;
    }

    const root = new Node(rootNode.data);

    root.left = this.#buildTree(rootNode.left);
    root.right = this.#buildTree(rootNode.right);

    return root;
  }

  /**
   * Builds binary tree using CLI
   * @param {Node | null} rootNode
   * @returns {Promise<Node | null>} rootNode of the resulting tree
   */
  static async buildUsingCli(rootNode = null) {
    const data = await BinaryTree.#prompt.question(`> Enter value: `);

    if (data === 'null') {
      return null;
    }

    rootNode = new Node(data);

    console.log(`\n${rootNode.data}->left: `);
    rootNode.left = await BinaryTree.buildUsingCli(rootNode.left);

    console.log(`\n${rootNode.data}->right: `);
    rootNode.right = await BinaryTree.buildUsingCli(rootNode.right);

    return rootNode;
  }

  /**
   * Pre order traversal of the elements of the binary tree
   * @param {Node | null} rootNode 
   */
  preOrderTraversal(rootNode = this.root) {
    if (rootNode === null) {
      return;
    }

    BinaryTree.#prompt.write(`${rootNode.data} `);
    this.preOrderTraversal(rootNode.left);
    this.preOrderTraversal(rootNode.right);
  }

  /**
   * In order traversal of the elements of the binary tree
   * @param {Node | null} rootNode 
   */
  inOrderTraversal(rootNode = this.root) {
    if (rootNode === null) {
      return;
    }

    this.inOrderTraversal(rootNode.left);
    BinaryTree.#prompt.write(`${rootNode.data} `);
    this.inOrderTraversal(rootNode.right);
  }

  /**
   * Post order traversal of the elements of the binary tree
   * @param {Node | null} rootNode 
   */
  postOrderTraversal(rootNode = this.root) {
    if (rootNode === null) {
      return;
    }

    this.postOrderTraversal(rootNode.left);
    this.postOrderTraversal(rootNode.right);
    BinaryTree.#prompt.write(`${rootNode.data} `);
  }


  /**
   * Level order / Breadth first traversal of binary tree
   * @param {Node | null} rootNode 
   */
  levelOrderTraversal(rootNode = this.root) {
    if (rootNode === null) {
      return null;
    }

    const queue = new Queue();
    queue.enque(rootNode);
    queue.enque('null');

    while (!queue.empty()) {
      /**
       * @type {Node} 
       */
      const temp = queue.dequeue();

      if (temp === 'null') {
        console.log();

        if (!queue.empty()) {
          queue.enque('null');
        }
      } else {
        BinaryTree.#prompt.write(`${temp.data} `);
        queue.enque(temp.left);
        queue.enque(temp.right);
      }
    }
  }


  /**
   * Gets the max height of the binary tree
   * @param {Node | null} root
   */
  maxHeight(root = this.root) {
    // max height is zero for root element null
    if (root === null) {
      return 0;
    }

    // max height is zero for single element in the tree
    if (root.left === null && root.right === null) {
      return 0;
    }

    const leftMax = this.maxHeight(root.left);
    const rightMax = this.maxHeight(root.right);
    return Math.max(leftMax, rightMax) + 1;
  }

}