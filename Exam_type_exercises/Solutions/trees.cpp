using namespace std;
#include <iostream>

struct node {
	struct node* left;
	struct node* right;
	int data;
};

// Function to create a new Binary node
struct node* newNode(int data)
{
	struct node* temp = new node;

	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

// Function to print Leaf Nodes at a given level
void PrintLeafNodes(struct node* root, int level, int& sum)
{
	if (root == NULL)
		return;

	if (level == 1) {
		    cout << root->data << " ";
            sum += root->data;
        //}
	}
	else if (level > 1) {
		PrintLeafNodes(root->left, level - 1, sum);
		PrintLeafNodes(root->right, level - 1, sum);
	}
}


// TEST CASES - initial Binary Graph definition
struct node* initial_graph_test_5(){
    struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
    return root;
}
struct node* initial_graph_test_6(){
    struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
    root->right->left->left = newNode(5);
    root->right->left->left->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->right->right->right = newNode(9);
    return root;
}

//print
void print_ordered(struct node* root) {
  if (root != NULL) {
    print_ordered(root->left);
    cout << root->data << endl;
    print_ordered(root->right);
  }
}
static void print_spaces(int depth) {
  for(int i=0;i<depth;i++) 
      cout << "  ";
}
void print_indented(struct node* root) { 
  static int depth=0;
  depth++;
  if (root != NULL) {
    print_indented(root->right);
    print_spaces(depth);
    cout << root->data << endl;
    print_indented(root->left);
  }
  depth--;
}

// Preorder traversal
void preorderTraversal(struct node* node) {
  if (node == NULL)
    return;

  cout << node->data << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(struct node* node) {
  if (node == NULL)
    return;

  postorderTraversal(node->left);
  postorderTraversal(node->right);
  cout << node->data << "->";
}

int tree_height(struct node* root) {
    if (!root)
        return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

// Main code
int main()
{
    int testNumber=1;
    cout << "Enter test number --> ";
    cin>> testNumber;

    struct node* root;

    if (testNumber==5){
        root = initial_graph_test_5(); 
    }
    else if (testNumber==6){
        root = initial_graph_test_6();  
    }
    else {
        cout << "Not valid input" << endl;
        return -1;
    }

    // Print the graph to check it
    print_indented(root);
 
    // Print the graph nodes in pre-order
    cout << "Pre-order:";
    preorderTraversal(root);
    cout << endl;
    
    // Print the graph nodes in post-order
    cout << "Post-order:";
    postorderTraversal(root);
    cout << endl;

    // Print the graph high 
    cout << "Tree high:";
    cout << tree_height(root) << endl;

    // Enter the level to print/sum
	int level = 4;
    cout << "Enter level --> ";
    cin>> level;

    int sum=0;

    // iteration print and sum at level l
	PrintLeafNodes(root, level, sum);
    cout << endl;
    cout << "sum=" << sum << endl;

	return 0;
}
