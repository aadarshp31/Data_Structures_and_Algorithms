import readline from "node:readline/promises";
import Node from "./Node.js";

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

}