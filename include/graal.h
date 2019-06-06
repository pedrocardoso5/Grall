#ifndef GRAAL_H
#define GRAAL_H

#include<iostream>
#include<vector>
#include<cstring>
#include <iterator>         
#include <functional>          
#include <algorithm>            

//Faltou serem feitas as funções uniq() e qsort()

using Compare = bool(*)(const void*, const void*);
using Predicate = bool(*)(const void*);
using Equal = bool(*)(const void*, const void*);

namespace graal{

	const void* min(const void* first, const void* last, std::size_t size, Compare cmp);

	void reverse(void* first, void* last, std::size_t size);

	void* copy(const void* first, const void* last, const void* d_first, std::size_t size);

	void* clone(const void* first, const void* last, std::size_t size);

	const void* find_if(const void* first, const void* last, std::size_t size, Predicate p);

	const void* find(const void* first, const void* last, std::size_t size, const void* value, Equal eq);

	bool all_of(const void* first, const void* last, std::size_t size, Predicate p);
	bool any_of(const void* first, const void* last, std::size_t size, Predicate p);
	bool none_of(const void* first, const void* last, std::size_t size, Predicate p);


	bool equal(const void* first1, const void* last1, const void* first2, std::size_t size, Equal eq);
	bool equal(const void* first1, const void* last1, const void* first2, const void* last2, Equal eq);
	bool equal(const void* first1, const void* last1, const void* first2, const void* last2, std::size_t size, Equal eq);
	bool equal(const void* first1, const void* last1, const void* first2);



	void* partition(void* first, void* last, std::size_t size, Predicate p);


}
#endif