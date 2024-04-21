import readline from 'readline/promises';

export class Node {
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
   * 
   * @param {*} data 
   * @param {Node | null} left 
   * @param {Node | null} right 
   * @returns {Node} node object
   */
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = null;
    this.right = null;
  }

}

const prompt = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

/**
 * Builds a binary tree usign CLI i.e. user's input 
 * @param {Node | null} rootNode 
 * @author aadarshp31
 */
export async function buildTreeCli(rootNode) {

  const rootData = await prompt.question('> Enter the data: ');
  if (rootData === "null") {
    return null;
  }

  rootNode = new Node(rootData);

  console.log(`> Enter data to be inserted to left of ${rootData}: `);
  rootNode.left = await buildTreeCli(rootNode.left);

  console.log(`> Enter data to be inserted to right of ${rootData}: `);
  rootNode.right = await buildTreeCli(rootNode.right);

  return rootNode;
}