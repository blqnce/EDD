*************************************

Autor: Esteban Alfonso Navas Suarez
Organizacion : Pontificia Universidad Javeriana
Fecha: 5/03/2025

**************************************



#include <stdlib.h>
#include <iostream>
using namespace std;

// Definicion de un nodo de un arbol binario

struct node {
	int data;
	struct node *left; 
	struct node *right;
};

// Implementacion para crear un nuevo nodo de un arbol binario

struct node *newNode (int data){
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
};

// Declaracion de las funciones necesarias

void traversePreOrder (struct node *temp);
void traverseInOrder(struct node *temp);
void traversePostOrder (struct node *temp);

int main(){

	// Se crea el arbol binario, en caso de querer cambiar el contenido del arbol binario se modifica desde aqui

	struct node *root = newNode(7);
	root->left = newNode(3);
	root->left->left = newNode(0);
	root->left->left->left = newNode(-3);
	root->left->left->right = newNode(1);
	root->left->right = newNode(5);
	root->left->right->left = newNode(4);
	root->left->right->left = newNode(6);		
	root->right = newNode(20);
	root->right->left = newNode(15);
	root->right->right = newNode(25);
	root->right->right->right = newNode(30);
	
	
	// Se imprime el arbol con los ordenamientos PreOrder, InOrder y PostOrder
	
	cout << "Preorder traversal:";
	traversePreOrder(root);
	cout << "\nInorder traversal:";
	traverseInOrder(root);
	cout << "\nPostorder traversal:";
	traversePostOrder(root);
	cout << "\n";
}

// Funcion que permite el ordenamiento PreOrder	
	
void traversePreOrder (struct node *temp) {
	if (temp != NULL) {
		cout << " " << temp->data;
		traversePreOrder (temp->left);
		traversePreOrder(temp->right);
	}
}

// Funcion que permite el ordenamiento InOrder

void traverseInOrder(struct node *temp) {
	if (temp != NULL) {
		traverseInOrder(temp->left);
		cout << " " << temp->data;
		traverseInOrder(temp->right);
	}
}

// Funcion que permite el ordenamiento PostOrder

void traversePostOrder (struct node *temp){
	if (temp!= NULL){
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout << " " << temp->data;
	}
}
