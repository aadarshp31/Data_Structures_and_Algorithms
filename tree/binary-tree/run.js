import { buildTreeCli } from "./implementation.js";

const root = null;

const binaryTree = await buildTreeCli(root);

console.log({ binaryTree });
process.exit(0);