//
//  Vector.cpp Project 5 - Templates
//
//  Created by Nathenael Dereb on 2/8/21.
//


#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

template <class T> 
struct Node {
public:
  Node(T value) {
    m_value = value;
    next = nullptr;
  }
  
  Node(T value, Node* _next) {
    m_value = value;
    next = _next;
  }
  
  T getValue() {
    return m_value;
  }
  
  Node<T>* getNextNode() {
    return next;
  }
  
  void setNextNode(Node<T>* newNode) {
    next = newNode;
  }
  
private:
  T m_value;
  Node<T>* next;
};


template <class T>
class Vector {
public:
  // Name: Default Constructor
  // Precondition: None (Must be templated)
  // Postcondition: Creates a vector using a linked list
  Vector();
   
  // Name: Destructor
  // Desc: Frees memory
  // Precondition: Existing Vector
  // Postcondition: Destructs existing Vector
  ~Vector();  

  // Name: Copy Constructor
  // Desc: Copies an existing vector
  // Precondition: Existing Vector
  // Postcondition: Two identical vectors (in separate memory spaces)
  // Hint: Utilize overloaded [] operator
  Vector (Vector<T> const& source);
  
  // Name: Overloaded Assignment operator
  // Desc: Assingns a vector
  // Precondition: Existing Vector
  // Postcondition: Assigns a vector
  // Hint: Utilize overloaded [] operator
  Vector<T>* operator=(Vector<T>* source);  
  
  // Name: Overloaded [] operator
  // Desc: to retrive use [indx]
  // Precondition: Existing Vector
  // Postcondition: Returns the value of the element at the given index
  T operator[](int indx);
    
  // Name: Insert
  // Desc: insert a node to the end of the vector
  // Precondition: Existing Vector
  // Postcondition: A vector with the newly added value
  void Insert(T);  
    
  // Name: SortedInsert
  // Desc: Inserts a node into the vector at it's correct position (sorted ascendingly)
  // Precondition: Existing Vector
  // Postcondition: sorted vector (low to high)
  void SortedInsert(T);
      
  // Name: Remove
  // Desc: removes a node from the vector
  // Precondition: Existing Vector
  // Postcondition: A vector that holds the results of the vectors added
  void Remove(int indx);
    
  // Name: Overloaded + operator | Vector Addition
  // Desc: Adds two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: A vector that holds the results of the vectors added
  Vector<T>* operator+(Vector<T>& source);
    
  // Name: Overloaded * operator | Vector Multiplication
  // Desc: Multiplys two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: returns a vector that holds the results of the vectors multiplied
  Vector<T>* operator*(Vector<T>& other);
    
  // Name: Overloaded < operator | Vector Comparision
  // Desc: Compares two vectors [using the < operator] and returns the result
  // Precondition: Existing Vector -> vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
  Vector<char>* operator<(Vector<T>& other);
      
  // Name: Overloaded == operator | Vector Comparision
  // Desc: Compares two vectors [using the == operator] and returns the result
  // Precondition: Existing Vector, vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
  Vector<char>* operator==(Vector<T>& other);
    
  // Name: Size
  // Desc: number of nodes in Vector
  // Precondition: Existing Vector
  // Postcondition: returns the size of the vector
  int Size();  
    
  // Name: Display
  // Desc: displays the contents of the vector
  // Precondition: Existing Vector
  // Postcondition: prints to console the contents of Vector
  void Display();
    
  // Name: median
  // Desc: Computes the median of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the median value
  float Median();  
    
  // Name: Mean
  // Desc: Computes the mean of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the mean value
  float Mean();
    
  // Name: StDev
  // Desc: Computes the standard derivation of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the standard derivation
  float StDev();
      
private:
    Node<T>* m_head;
};


// **** Add class definition below ****

// Name: Default Constructor
// Precondition: None (Must be templated)
// Postcondition: Creates a vector using a linked list
template <class T>
Vector<T>:: Vector(){

  m_head = nullptr;

}

// Name: Destructor
// Desc: Frees memory
// Precondition: Existing Vector
// Postcondition: Destructs existing Vector
template <class T>
Vector<T>:: ~Vector(){

  Node<T>* curr = m_head;

  while (curr != nullptr)
    {
       m_head = curr;
       curr = curr->getNextNode();
       delete m_head;
       m_head = nullptr;
    }

  
  m_head = nullptr;
  
}

// Name: Copy Constructor
// Desc: Copies an existing vector
// Precondition: Existing Vector
// Postcondition: Two identical vectors (in separate memory spaces)
// Hint: Utilize overloaded [] operator
template <class T>
Vector<T>:: Vector (Vector<T> const& source){

  
  Node<T>* curr = m_head; 
  
  for(int i = 0; i < source.Size(); i++)
    {
      T val= source[i];
      
      Node<T>* temp = new Node<T>(source[i]);
      curr->setNextNode(temp);

    }

  
  
 
}

// Name: Overloaded Assignment operator
// Desc: Assingns a vector
// Precondition: Existing Vector
// Postcondition: Assigns a vector
// Hint: Utilize overloaded [] operator

template <class T>
Vector<T>* Vector<T>:: operator=(Vector<T>* source){

  T val;
  
  if(*this != source)
    {

    for(int i = 0; i < source->Size(); i++)
      {
	val = source[i];
	
	*this->Insert(val);
      }
    
  }

  return *this;
}


// Name: Overloaded [] operator
// Desc: to retrive use [indx]
// Precondition: Existing Vector
// Postcondition: Returns the value of the element at the given index

template <class T>
T Vector<T>:: operator[](int indx){

  Node<T>* curr = m_head;
  T val;
  
  for(int i = 0; i < indx; i++)
    {
      curr = curr->getNextNode();
    }

  val = curr->getValue();
  
  return val;
}

// Name: Insert
// Desc: insert a node to the end of the vector
// Precondition: Existing Vector
// Postcondition: A vector with the newly added value
template <class T>
void Vector<T>:: Insert(T value){

  
  Node<T>* temp = new Node<T>(value);
  Node<T>* curr = m_head;

  
  if(m_head == nullptr)
    {
      m_head = temp;
      
    }else{
    
    while(curr->getNextNode() != nullptr)
      {
	curr = curr->getNextNode();
      }

    curr->setNextNode(temp);


  }
  

}

// Name: SortedInsert
// Desc: Inserts a node into the vector at it's correct position (sorted ascendingly)
// Precondition: Existing Vector
// Postcondition: sorted vector (low to high)
template <class T>


void Vector<T>:: SortedInsert(T value){
  
  Node<T>* curr = m_head; // current position 
  Node<T>* nxt;// next position
  Node<T>* LinkedList; // to creat new node
  Node<T>* temp; // to add a node in front 
  

if (m_head == nullptr)
    {

      
      LinkedList = new Node<T>(value);
      m_head = LinkedList;

    }else{

    if(value < m_head->getValue())
      {
	
	LinkedList = new Node<T>(value);
	temp = m_head;
	m_head = LinkedList;
	m_head->setNextNode(temp);

   

      }else{
            
      for(curr = m_head; curr != nullptr; curr = curr->getNextNode())
	{
	  
	  if(value > curr->getValue() )
	    {
	      if(curr->getNextNode() == nullptr)
		{
		        
		  LinkedList = new Node<T>(value);

		  curr->setNextNode(LinkedList);
		  
	       	}else{

		nxt = curr->getNextNode();

		if(value < (nxt->getValue()) && value > (curr->getValue()))
		  {
		
		
                    LinkedList = new Node<T>(value, nxt);
		    curr->setNextNode(LinkedList);
		  }
       
	      }



	    }


	}
   
    }
   

 }


}
 

// Name: Remove
// Desc: removes a node from the vector
// Precondition: Existing Vector
// Postcondition: A vector that holds the results of the vectors added
template <class T>
void Vector<T>:: Remove(int indx)
{

  Node<T>* curr, prev, temp = m_head;
  
  for(int i = 1; i < indx; i++)
    {
      temp->next;

    }

  prev = temp;
  temp = temp->getNextNode();
  curr = temp->getNextNode();
  
  prev->getNextNode() = curr;


}

// Name: Overloaded + operator | Vector Addition
// Desc: Adds two vectors and returns the result
// Precondition: Existing Vector, vectors can be of different size
// Postcondition: A vector that holds the results of the vectors added

template <class T>
Vector<T>* Vector<T>::operator+(Vector<T>& source){

  int size1 = source.Size();

  Vector<T>* result = new Vector<T>();

  for(int i = 0; i < size1; i++)
    {
      T sum = operator[](i) + source[i];
      result->Insert(sum);
    }


  return result;
}

// Name: Overloaded * operator | Vector Multiplication
// Desc: Multiplys two vectors and returns the result
// Precondition: Existing Vector, vectors can be of different size
// Postcondition: returns a vector that holds the results of the vectors multiplied
template <class T>
Vector<T>* Vector<T>:: operator*(Vector<T>& other){

  int size2 = other.Size();

  Vector<T>* MulResult = new Vector<T>();

  for(int i = 0; i < size2; i++)
    {
      T mul = operator[](i) * other[i];
      MulResult->Insert(mul);

    }


  return MulResult;
  
}

// Name: Overloaded < operator | Vector Comparision
// Desc: Compares two vectors [using the < operator] and returns the result
// Precondition: Existing Vector -> vectors need to be of the same size
// Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison

template <class T>
Vector<char>* Vector<T>::operator<(Vector<T>& other){

   
  T result;
  int size = other.Size();
  Vector<char>* resultVec = new Vector<char>;
  
  for(int i = 0; i < size; i++)
    {
      
      if (operator[](i) >= other[i])
	{
	  result = 'F';
	 resultVec->Insert(result);
	  
	}else{

	result = 'T';
	
	resultVec->Insert(result);
      }

    }
      return resultVec;
      
  
}

// Name: Overloaded == operator | Vector Comparision
// Desc: Compares two vectors [using the == operator] and returns the result
// Precondition: Existing Vector, vectors need to be of the same size
// Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
template <class T>
Vector<char>* Vector<T>::operator==(Vector<T>& other){

  char result;
  Vector<char>* resultVec = new Vector<char>;
  
  for(int i = 0; i < other.Size(); i++)
    {
      if(operator[](i) == other[i])
	{
	  result = 'T';
	  resultVec->Insert(result);

	}else{

	result = 'F';
	resultVec->Insert(result);
      }
    }

  return resultVec;
}

// Name: Size
// Desc: number of nodes in Vector
// Precondition: Existing Vector
// Postcondition: returns the size of the vector
template <class T>
int Vector<T>:: Size(){

  int size = 1;
  Node<T>* curr = m_head;
  
  while(curr->getNextNode() != nullptr)
    {
      curr = curr->getNextNode();
      size++;
    }


  return size;
}

// Name: Display
// Desc: displays the contents of the vector
// Precondition: Existing Vector
// Postcondition: prints to console the contents of Vector
template <class T>
void Vector<T>:: Display(){

  Node<T>* curr = m_head;
  
  for(curr = m_head; curr != nullptr; curr = curr->getNextNode())
    {
      cout << curr->getValue() << ", ";
    }

    cout << endl; 

}

// Name: median
// Desc: Computes the median of the vector
// Precondition: Existing Vector
// Postcondition: returns the median value
template <class T>
float Vector<T>:: Median(){


  T val = 0;  
  Node<T>* curr = m_head;
  int size = Size()/2;
  
  for(int i = 1; i <= size; i++)
    {
      
     curr = curr->getNextNode();
      
    }

  val += curr->getValue();
  curr = curr->getNextNode();

  val += curr->getValue();
  
  return float(val/2);
}

// Name: Mean
// Desc: Computes the mean of the vector
// Precondition: Existing Vector
// Postcondition: returns the mean value
template <class T>
float Vector<T>:: Mean(){
  
  Node<T>* curr = m_head;
  float sum;
  
  while(curr != nullptr)
    {

      sum += curr->getValue();
      curr = curr->getNextNode();
    }

  return float(sum/Size());
}

// Name: StDev
// Desc: Computes the standard derivation of the vector
// Precondition: Existing Vector
// Postcondition: returns the standard derivation
template <class T>
float Vector<T>:: StDev(){

  
  float StDev = 0, mean = Mean();
  int size = Size();
  
  Node<T>* temp = m_head;
  
  for(int i = 0; i < size; i++)
    {

      StDev += pow(temp->getValue() - mean, 2);
      temp = temp->getNextNode();

    }

  
  return sqrt(StDev / 10);
}


#endif /* VECTOR_CPP */
