/**
 * There is no Collection.cpp for this assignment.
 * Move all the functions from Collection.cpp to this file except Operator>> 
 * Covert the Collection class to a templated form. (Stress_ball should be replaced with typename "Obj".
 *   Stress_ball_colors and Stress_ball_sizes should be replaced with typename "F2").
 * This file has to be uploaded to mimir.
 */

#ifndef Collection_H
#define Collection_H
#include <string>
#include <iostream>
using namespace std;

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

class Empty_Collection{};
template<class Obj, typename F1, typename F2>
class Collection {
	Obj *array;
	int size;
	int capacity;
	
	void resize() {
		
		capacity = capacity*2;
		if( capacity == 0){
			capacity = 2;
		} 
		// creates temp pointer to transfer all the old data to the new resized array
		Obj *temp = new Obj[capacity];
		for(int i = 0; i < size; i++) {
			temp[i] = array[i];
		}
		// memory leak fix
		delete []array;
		array = temp;
	};
	
	public:
		Collection() {
			size = 0;
			capacity = 0;
			array = nullptr;
		};
			
		Collection(int sze) {
			size = 0;
			capacity = sze;
			array = new Obj[capacity];
		};
			
		Collection(const Collection &T) {
			size = T.size;
			capacity = T.capacity;
			array = new Obj[capacity];
			for (int i = 0; i < size; i++) {
				array[i] = T.array[i];
			}
		};

		Collection(Collection&& c): size(c.size), capacity(c.capacity), array(c.array){
			c.array = NULL;
			c.size = 0;
			c.capacity = 0;
		};
			
		Collection& operator=(const Collection& T) {
			if(this != &T) {
				if(array != nullptr) {
					delete []array;
				}
				size = T.size;
				array = new Obj[capacity];
				for(int i = 0; i < size; i++) {
					array[i] = T.array[i];
				}
			}
				return *this;
			};
			
		Collection& operator=(Collection&& c) {
			
			if(this != &c) {
				make_empty();
				size = c.size;
				capacity = c.capacity;
				array = c.array;
				c.array = NULL;
				c.size = 0;
				c.capacity = 0;
			}
			return *this;
		};
			
		~Collection() {
			make_empty();
		};
			// inserts new item into current stress ball, resizes array if full
		void insert_item(const Obj &sb) {
			if(size == capacity) {
				resize();
			} else if (array == nullptr) {
				array = new Obj[capacity];
			}
			array[size] = sb;
			size++;
			
		};
			// checks if item is within current stress ball
		bool contains(const Obj &sb) const{
			for(int i = 0; i < size; i++) {
				if(array[i] == sb){
					return true;
				}
			}
			return false;
		};
			
		Obj remove_any_item(){
			// checks if the array is already empty and throws an error if it is
			if(is_empty()) {
				throw Empty_Collection();
			}
			int indx = rand()% size;
			Obj sb = array[indx];
			remove_this_item(sb);
			return sb;
		};
			
		void remove_this_item( const Obj &sb) {
			// checks if the array is already empty and throws an error if it is
			if(size == 0){
				throw Empty_Collection();
			}
			int indx = -1;
			for (int i = 0; i < size; i++) {
				if(array[i] == sb) {
					indx = i;
					break;
				}
			}
			if( indx == -1) {
				return;
			}
			for(int i = indx; i < size; i++) {
				array[i] = array[i+1];
			}
			size--;
		};
			
		void make_empty(){
				 
				array = nullptr;
				size = 0;
				capacity = 0;
				 
			};
			
		bool is_empty() const{
			return size == 0;
		};
			
		int total_items() const {
			return size;
		};
			
		int total_items(F2 s) const{
			int cnt = 0;
			for (int i = 0; i < size; i++){
				if(array[i].get_size() == s) {
					cnt++;
				}
			}
			return cnt;
		};
			
		int total_items(F1 c) const{
			int cnt = 0;
			for (int i = 0; i < size; i++){
				if( array[i].get_color() == c){
					cnt++;
				}
			}
			return cnt;
		};
			
		void print_items() const{
			for(int i = 0; i < size; i++) {
				cout << array[i] << endl;
			}
		}
			
		Obj& operator[](int i) {
			return array[i];
		};
			
		const Obj& operator[](int i) const{
			return array[i];
		};
		
};
	template <class Obj, typename F1, typename F2>
	ostream& operator<<(ostream& o,const Collection<Obj, F1, F2> &c){
				
		for (int i = 0; i < c.total_items(); i++) {
				o << c[i] << endl;
		}
		return o;
	};
	template <class Obj, typename F1, typename F2>	
	Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2> &c1, const Collection<Obj, F1, F2> &c2) {
			Collection<Obj, F1, F2> c3 = c1;
			for (int i = 0; i < c2.total_items(); i++) {
				c3.insert_item(c2[i]);
			}
			return c3;
	};
			
	template <class Obj, typename F1, typename F2>	
	void swap(Collection<Obj, F1, F2> &c1, Collection<Obj, F1, F2> &c2) {
		Collection<Obj, F1, F2> temp = move(c1);
		c1 = move(c2);
		c2 = move(temp);
	};
	
	template <class Obj, typename F1, typename F2>	
	void bubble_sort(Collection<Obj, F1, F2> &c) {
		int n = c.total_items();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n-i-1; j++) {
				if(c[j].get_size()>c[j+1].get_size()) {
					swap(c[j], c[j+1]);
				}
			}
		}
	};
	template <class Obj, typename F1, typename F2>	
	void insertion_sort(Collection<Obj, F1, F2> &c) {
			for (int k = 1; k < c.total_items(); k++) {
				int temp = k;
				int j = k;
				for(; j > 0 && c[temp].get_size() < c[j-1].get_size(); j--) {
					c[j] = c[j-1];
				}
				c[j] = c[temp];
			}
		};
	template <class Obj, typename F1, typename F2>
	void selection_sort(Collection<Obj, F1, F2> &c){
		int smallest_value;
				
		for(int i = 0; i < c.total_items(); i++) {
			smallest_value = i;
			for(int j = i; j < c.total_items(); j++) {
				if(c[j].get_size() < c[smallest_value].get_size()) {
					smallest_value = j;
				}
			}
			swap(c[i],c[smallest_value]);
		}
	};
	template <class Obj, typename F1, typename F2>
	void sort_by_size (Collection<Obj, F1, F2> &c, Sort_choice sort) {
		switch (sort) {
			case Sort_choice::bubble_sort:
			bubble_sort(c);
			break;
			case Sort_choice::insertion_sort:
			insertion_sort(c);
			break;
			case Sort_choice::selection_sort:
			selection_sort(c);
			break;
		}
	};
			
			

//your code...
//Templated class collection
//Methods from Collection.cpp
#endif