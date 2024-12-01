#pragma once
#include "Header.h"

template <class C>
class PileL
{
private:
	list<C> stack_elements;
public:
	PileL();
	PileL(PileL<C> const& a_copier);

	void print() const;
	void push(C val);
	C pop();
	size_t size()const;
	PileL<C> reverse()const;

	PileL<C> operator=(PileL<C> const& a_copier);
};

template<class C>
inline PileL<C>::PileL()
{
}

template<class C>
inline PileL<C>::PileL(PileL<C> const& a_copier)
{
	//copier la pile `a_copier` dans celle courante, 
	// à l'aide du constructeur de recopie de `list<C>`
	stack_elements = a_copier.stack_elements;
}

template<class C>
inline void PileL<C>::print() const
{
	Rl;
	for (auto it = stack_elements.rbegin() ; it != stack_elements.rend() ; it++ )
		cout << "|" << BLUE << setw(10) << *it << RESET << setw(10) << "|\n";
	cout << "--------------------\n\n";
}

template<class C>
inline void PileL<C>::push(C val)
{
	stack_elements.push_back(val);
}

template<class C>
inline C PileL<C>::pop()
{
	try
	{
		//envoyer une exception dans le cas où on appelle `pop` par une pile vide
		if (stack_elements.empty())
			throw runtime_error("PileL<C>::pop() : Pile vide, dépilement impossible.");
		//récupérer la tête de la pile
		C element_to_pop = stack_elements.back();
		//dépiler
		stack_elements.pop_back();
		return element_to_pop;
	}
	catch(const exception& e)
	{
		wcerr << E_RED << "!!! " << e.what() << E_RESET; Rl;
	}
	return C();
}

template<class C>
inline size_t PileL<C>::size() const
{
	return stack_elements.size();
}

template<class C>
inline PileL<C> PileL<C>::reverse() const
{
	//inverser le contenu de la pile courante dans une nouvelle pile, retournée par la suite
	PileL<C> stack_reversed;
	reverse_copy(stack_elements.begin(), stack_elements.end(), back_inserter(stack_reversed.stack_elements));
	return stack_reversed;
}

template<class C>
inline PileL<C> PileL<C>::operator=(PileL<C> const& a_copier)
{
	stack_elements = a_copier.stack_elements;
	return *this;
}
