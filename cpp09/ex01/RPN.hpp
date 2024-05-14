#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<deque>

/*
	A - RPN is treated in kinda LIFO : depoping in reverse order (vs storing) 
	until you get an operator that is applied to the last 2 depoped numbers.

	B - Subjects are BAD and USELESSLY IMPRECISE again
	french : only DIGIT lower than 10
	english : only NUMBERS lower than 10
	Il s'agirait de bien faire les sujets svp. Chiffres only? Nombres aussi??
	Quid des nombres négatifs? Acceptés jusque -9 ou -10, -inf?
	Quel type pour stocker les nombres (ie. quel niveau d'ovlf) : int, long int?
	On aurait pas pu parler en valeur absolue, donner une type (genre char), ou 
	meme donner clairement l'intervalle?
	Je ne vois pas l'interet logique/intellectuel à une telle imprécision qui ne
	peut que créer des distorsions en corrections, sans interet pédagogique ici. 

	=> Pour respecter le sujet tel que je le lis un peu naivement, il faudrait
	accepter [ -inf ; 9 ]. Or, -inf n'est pas gérable. 
	=> Je vais donc essayer d'interpréter la consigne : avec les exemples je 
	comprends qu'il ne faudrait gérer que les positifs [ 0 ; 10 ], ce qui permet
	d'ailleurs de stocker la data en char !!
	Mais par précaution on va etre un peu plus large en acceptant du negatif, 
	en restant sur le meme intervalle inversé : [ -9 ; 9 ]. La consigne laisserait
	entendre que ya pas de limite en negatif mais il m'en faut une. 
	Par précaution le résultat sera double. Pas de check de perte de précison je
	pense qu'on fait deja plus que ce qui est (maladroitement) demandé.

	Cela oblige a utiliser a stocker les valeurs en string, dans une stack. 
	
	Process logic : 
		1 - stock rpn data into stack
			-> check format : operator or or -+digit, checks ovlf, use sstream
		2 - pop in reverse (lifo) until you get an operator
		3 - apply the operator between last 2 numbers that have been popped
		4 - push back the result into stack
		5 - repeat until you get only one data number into stack
			-> if it is not achievable, error !
				- last data is an operator, only number, only operator, bad order etc

	Class logic:
		Program treats a single operation per execution so the object would only
		do one calculation per execution : 
			- fulfill data in RPN only on parametric construction
			- default constructor or any setter not avaible
		I could have implement the calculation in the constructor but ew I don't 
		feel comfortable with that so there is another public member function

	Stack.top() returns a reference but does not pop
	stack.pop() delete the value and returns void
	=> I try to copy top then remove it from the stack : it also rm the copy
	since its a reference. I tried few ways it is still the same
	Can't use std::copy (it requieres iterator)
	Maybe by allocating but eww

*/

class RPN
{
	public:

		~RPN();
		RPN(const std::string data);	// thrower
		RPN(const RPN & src);
		RPN & operator=(const RPN & rhs);

		void	printStack(); // for debugging, it empties the stack
		void	calculate();	//throw

	private:

		RPN();	// unusable default constructor

		double	doOperation(double lhs, double rhs, char op) const;
		double	extractStrFromStackToDouble();	//throw
		bool	isValidOperator(std::string val) const;
		bool	isValidDigit(std::string val) const;

		std::stack<std::string>	_stack;
};


#endif
