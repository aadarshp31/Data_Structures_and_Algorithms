import BinaryTree from "./BinaryTree.js";
import Node from "./Node.js";

const root = null;

/**
 * @type {Node}
 */
const input = {
  data: 1,
  left: {
    data: 2,
    left: {
      data: 3,
      left: null,
      right: null
    },
    right: {
      data: 4,
      left: null,
      right: null
    }
  },
  right: {
    data: 5,
    left: {
      data: 6,
      left: null,
      right: null
    },
    right: {
      data: 7,
      left: null,
      right: null
    }
  }
}


console.info(`> Creating binary tree...`);
// const binaryTree = new BinaryTree(input);
const rootNode = await BinaryTree.buildUsingCli();

const binaryTree = new BinaryTree(rootNode);

console.info(`\n> Pre Order traversal`);
binaryTree.preOrderTraversal();

console.info(`\n> In Order traversal`);
binaryTree.inOrderTraversal();

console.info(`\n> Post Order traversal`);
binaryTree.postOrderTraversal();

process.exit(0);