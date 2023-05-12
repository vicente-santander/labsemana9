#include <iostream>
#include <vector> //ejercicio 3

using namespace std;

class Rectangle { // ejercicio 1 
    private:
        double width;
        double height;
    public:
        void setWidth(double w) {
            width = w;
        }
        void setHeight(double h) {
            height = h;
        }
        double getWidth() {
            return width;
        }
        double getHeight() {
            return height;
        }
        double getArea() {
            return width * height;
        }
};

class Point { //ejercicio 2 y3
    private:
        double x;
        double y;
    public:
        Point(double xVal, double yVal) {
            x = xVal;
            y = yVal;
        }
        void setX(double xVal) {
            x = xVal;
        }
        void setY(double yVal) {
            y = yVal;
        }
        double getX() {
            return x;
        }
        double getY() {
            return y;
        }
};

class LinkedList { //ejercicio 4
    private:
        struct Node {
            int data;
            Node* next;
        };
        Node* head;
    public:
        LinkedList() {
            head = NULL;
        }
        void insert(int data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }
        bool search(int data) {
            Node* currentNode = head;
            while (currentNode != NULL) {
                if (currentNode->data == data) {
                    return true;
                }
                currentNode = currentNode->next;
            }
            return false;
        }
        void remove(int data) {
            if (head == NULL) {
                return;
            }
            if (head->data == data) {
                head = head->next;
                return;
            }
            Node* currentNode = head;
            while (currentNode->next != NULL) {
                if (currentNode->next->data == data) {
                    currentNode->next = currentNode->next->next;
                    return;
                }
                currentNode = currentNode->next;
            }
        }
        void print() {
            Node* currentNode = head;
            while (currentNode != NULL) {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
};

class BinaryTree { //ejercicio 5
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;
        };
        Node* root;
        void insertNode(Node* currentNode, int data) {
            if (data < currentNode->data) {
                if (currentNode->left != NULL) {
                    insertNode(currentNode->left, data);
                } else {
                    currentNode->left = new Node;
                    currentNode->left->data = data;
                    currentNode->left->left = NULL;
                    currentNode->left->right = NULL;
                }
            } else {
                if (currentNode->right != NULL) {
                    insertNode(currentNode->right, data);
                } else {
                    currentNode->right = new Node;
                    currentNode->right->data = data;
                    currentNode->right->left = NULL;
                    currentNode->right->right = NULL;
                }
            }
        }
        bool searchNode(Node* currentNode, int data) {
            if (currentNode == NULL) {
                return false;
            }
            if (currentNode->data == data) {
                return true;
            }
            if (data < currentNode->data) {
                return searchNode(currentNode->left, data);
            } else {
                return searchNode(currentNode->right, data);
            }
        }
        void printInOrder(Node* currentNode) {
            if (currentNode == NULL) {
                return;
            }
            printInOrder(currentNode->left);
            cout << currentNode->data << " ";
            printInOrder(currentNode->right);
        }
    public:
        BinaryTree() {
            root = NULL;
        }
        void insert(int data) {
            if (root == NULL) {
                root = new Node;
                root->data = data;
                root->left = NULL;
                root->right = NULL;
            } else {
                insertNode(root, data);
            }
        }
        bool search(int data) {
            return searchNode(root, data);
        }
        void print() {
            printInOrder(root);
            cout << endl;
        }
        
};

int main() {
    Rectangle rect; //ejercicio 1

    rect.setWidth(5.0);
    rect.setHeight(7.0);

    cout << "Width: " << rect.getWidth() << endl;
    cout << "Height: " << rect.getHeight() << endl;
    cout << "Area: " << rect.getArea() << endl;
    
    cout << "-------------------------" << endl;
    
    Point p(2.5, 3.0); //ejercicio 2

    cout << "Initial Point: (" << p.getX() << ", " << p.getY() << ")" << endl;

    p.setX(4.0);
    p.setY(1.5);

    cout << "Updated Point: (" << p.getX() << ", " << p.getY() << ")" << endl;
    
    cout << "-------------------------" << endl;
    
    vector<Point> polygon; //ejercicio 3

    polygon.push_back(Point(0.0, 0.0));
    polygon.push_back(Point(1.0, 0.0));
    polygon.push_back(Point(1.0, 1.0));
    polygon.push_back(Point(0.0, 1.0));

    for (int i = 0; i < polygon.size(); i++) {
        cout << "Point " << i << ": (" << polygon[i].getX() << ", " << polygon[i].getY() << ")" << endl;
    }
    
    cout << "-------------------------" << endl;
    
    LinkedList list; //ejercicio 4
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.print(); // debe imprimir "15 10 5"

    cout << "Search for 10: "; 
    if(list.search(10) == true){
    	cout << "exists" << endl;
	}else{
		cout << "does not exist" << endl;
	}
    cout << "Search for 20: "; 
	if(list.search(20) == true){
    	cout << "exists" << endl;
	}else{
		cout << "does not exist" << endl;
	}
	
    list.remove(10);
    list.print(); // debe imprimir "15 5"
    
    cout << "-------------------------" << endl;
    
    BinaryTree tree; //ejercicio 5
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);
    tree.print(); // debe imprimir "2 3 4 5 7 8 9"

    cout << "Search for 4: "; // existe
	if (tree.search(4)) {
	    cout << "exists" << endl;
	} else {
	    cout << "does not exist" << endl;
	}
    if (tree.search(6)) { // no existe
	    cout << "exists" << endl;
	} else {
	    cout << "does not exist" << endl;
	}
    
    
    
    


    return 0;
}
