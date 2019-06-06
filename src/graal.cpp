#include"../include/graal.h"

using byte = unsigned char;
using Compare = bool(*)(const void*, const void*);
using Predicate = bool(*)(const void*);
using Equal = bool(*)(const void*, const void*);

namespace graal{

	const void* min(const void* first, const void* last, std::size_t size, Compare cmp){
		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last;
		byte small[size];
		byte comp[size]; 
		byte* ret;

		std::memcpy(small, pfirst, size);
		while(pfirst < plast){
			std::memcpy(comp, pfirst, size);
			if(cmp(comp,small) == true){
				std::memcpy(small, comp, size);
				
			}
			ret = small;
			pfirst += size;
		}

		return ret;
	}

	void reverse(void* first, void* last, std::size_t size){
		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last - size;
		byte aux[size];

		std::memcpy(aux, pfirst,size);

		while(pfirst < plast){

			std::memcpy(pfirst, plast, size);
			std::memcpy(plast, aux, size);

			pfirst += size;
			plast -= size;

			std::memcpy(aux, pfirst, size);
		}
	}

	void* copy(const void* first, const void* last, const void* d_first, std::size_t size){

		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last;
		byte* pd_first = (byte*)d_first;

		while(pfirst < plast){
			std::memcpy(pd_first, pfirst, size);

			pfirst += size;
			pd_first += size;
		}
		return pd_first;
	}

	void* clone(const void* first, const void* last, std::size_t size){

		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last;
		byte* array = new byte[plast - pfirst];

		byte* ret = &array[0];
		while(pfirst < plast){
			std::memcpy(array, pfirst, size);
			array += size;
			pfirst += size;
		}
		return ret;

	}

	const void* find_if(const void* first, const void* last, std::size_t size, Predicate p){
		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last - size;
		byte pred[size];
		byte* ret;
		std::memcpy(pred, plast, size);

		while(pfirst < plast){

			if(p(pfirst)){
				std::memcpy(pred, pfirst, size);
				break; 
			}

			pfirst += size;
		}
		ret = pfirst;	

		return ret;

	}

	const void* find(const void* first, const void* last, std::size_t size, const void* value, Equal eq){

		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last - size;
		byte comp[size];
		byte* ret;
		std::memcpy(comp, plast, size);

		while(pfirst < plast){

			if(eq(pfirst, value)){
				std::memcpy(comp, pfirst, size);
				break;
			}

			pfirst += size;
		}
		ret = pfirst;	

		return ret;
	}

	bool all_of(const void* first, const void* last, std::size_t size, Predicate p){

		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last;

		while(pfirst < plast){

			if(p(pfirst)){

			}
			else{
				return false;
			}
			pfirst += size;
		}
		return true;

	}
	bool any_of(const void* first, const void* last, std::size_t size, Predicate p){

		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last;

		while(pfirst < plast){

			if(p(pfirst)){
				return true;
			}

			pfirst += size;
		}
		return false;

	}
	bool none_of(const void* first, const void* last, std::size_t size, Predicate p){

		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last;

		while(pfirst < plast){

			if(p(pfirst)){
				return false;
			}

			pfirst += size;
		}
		return true;
	}


	bool equal(const void* first1, const void* last1, const void* first2, std::size_t size, Equal eq){

		byte* pfirst1 = (byte*)first1;
		byte* plast1 = (byte*)last1;
		byte* pfirst2 = (byte*)first2;

		while(pfirst1 < plast1){
			if(eq(pfirst1, pfirst2)==true){}
			else{
				return false;
			}

			pfirst2 += size;
			pfirst1 += size;
		}
		return true;
	}

	bool equal(const void* first1, const void* last1, const void* first2, const void* last2, std::size_t size, Equal eq){

		byte* pfirst1 = (byte*)first1;
		byte* plast1 = (byte*)last1;
		byte* pfirst2 = (byte*)first2;
		byte* plast2 =  (byte*)last2;

		while((pfirst1 < plast1) and (pfirst2 < plast2)){
			if(eq(pfirst1, pfirst2)==true){}
			else{
				return false;
			}

			pfirst2 += size;
			pfirst1 += size;
		}
		return true;
	}


	void* partition(void* first, void* last, std::size_t size, Predicate p){

		byte* pfirst = (byte*)first;
		byte* plast = (byte*)last;
		byte* pleft = (byte*)first;
		byte* pright = ((byte*)first) + size;
		byte aux[size];

		while(pright < plast){
			std::memcpy(aux, pleft, size);

			if(p(pleft)==false){
				while(true){
					if(pright >= plast){
							return pleft;
						}
					if(p(pright)==true){

						std::memcpy(pleft, pright, size);
						std::memcpy(pright, aux, size);

						break;

					}
					
					pright += size;
				}
			}

			pleft += size;
			pright += size;
		}
		return pleft;
	}

}