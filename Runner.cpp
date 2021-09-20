//
//  Runner.cpp
//  Project 5 - Templates
//
//  Created by Nathenael Dereb
//

#ifndef RUNNER_CPP
#define RUNNER_CPP

#include <cstdlib>
#include "Vector.cpp"
using namespace std;


template <class T>
class Runner {
public:
    // Name: Default Constructor
    // Precondition: None
    // Postcondition: Initiates state/environment
    Runner(Vector<T>*, Vector<T>*);
    
    // Name: mainMenu
    // Desc: Main Menu
    // Precondition: Existing Vectors
    // Postcondition: Handles various menu commands
    int mainMenu();

  
private:
    Vector<T> m_vector1;
    Vector<T> m_vector2;
};

// **** Add class definition below ****
template <class T>
Runner<T> :: Runner (Vector<T>* vec1, Vector<T>* vec2){
  
  m_vector1 = *vec1;
  m_vector2 = *vec2;


  mainMenu();

}

template <class T>
int Runner<T>:: mainMenu(){

 int input;
 bool ask = true;
 Vector<T>* temp1;
 Vector<T>* temp2;
 Vector<char>* char1;
 Vector<char>* char2;

 do{
   
  cout << "Choose an option" << endl;
  cout << "1. Display Vectors" << endl;
  cout << "2. Vector comparison (<)" << endl;
  cout << "3. Vector comparison (==)" << endl;
  cout << "4. Vector addition" << endl;
  cout << "5. Vector multiplication" << endl;
  cout << "6. Compute median" << endl;
  cout << "7. Compute mean" << endl;
  cout << "8. Compute Standard Derivation" << endl;
  cout << "9. Exit" << endl;

  cin >> input;

  if(input == 9)
    {
      ask = false;
      
    }else{

    switch(input)
      {
      case 1:


	m_vector1.Display();
	m_vector2.Display();


	break;
      case 2:

	char1 = m_vector1 < m_vector2;
	cout << "Vector1 < Vector2: ";
	char1->Display();
	delete char1;	

	break;
      case 3:

	char2 = m_vector1 == m_vector2;
	cout << "Vector1 == Vector2: ";
	char2->Display();
	delete char2;
	
	break;
      case 4:

	temp1 = m_vector1 + m_vector2;

	cout << "Vector1 + vector2 = ";
	temp1->Display();
	delete temp1;
	
	break;
      case 5:

	temp2 = m_vector1*m_vector2;

	cout << "Vector1 * Vector2 = ";
	temp2->Display();
	delete temp2;

	break;
      case 6:

	cout << "Vector1 median: ";
	cout << m_vector1.Median() << endl;
	cout << "Vector2 median: ";
	cout << m_vector2.Median() << endl;

	break;
      case 7:

	cout << "Vector1 mean: ";
	cout << m_vector1.Mean() << endl;
	cout << "Vector2 mean: ";
	cout << m_vector2.Mean() << endl;

	break;
      case 8:

	cout << "Vector1 StDev: ";
	cout << m_vector1.StDev() << endl;
	cout << "Vector2 StDev: ";
	cout << m_vector2.StDev() << endl;

	break;
      default:

	cout << "please enter a valid integer between 1 through 9" << endl;

	ask = true;

      }
  }
  }while(ask);

	
 return input;
}



#endif /* Runner_h */


