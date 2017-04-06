#include "search.h"

// implement the three functions here

template <typename T>
SearchResultType<T> bin_search_func(const std::vector<T> &veclist, const T &key, int lo, int hi);
//Used in recursive binary search

template <typename T>
SearchResultType<T> linear_search(const std::vector<T> &list, const T &value){
	bool find = false;
	long j = 0;
	T val = list[0];
	size_t n = 0;
	for (n = 0; n < list.size(); n++) {
	//Loops through vector one by one and tests each element
		if (list[n]==value) {
		//If value is found, returns true, the location, and the value at that location
			find = true;
			j = n;
			val = list[n];
			return SearchResultType<T>(find, val, j);
		};
	};
	//Returns false and the last element in the vector if the value is not found
	j = n-1;
	val = list[j];
	return SearchResultType<T>(find, val, j);
};

template <typename T>
SearchResultType<T> iterative_binary_search(const std::vector<T> &list, const T &value){
	bool find = false;
	long j;
	T val;
	long low = 0;
	long high = list.size() - 1;
	long mid;
	while (low <= high) {
		mid = (low+(high-low)/2);
		//Finds the midpoint between low and high
		if (value < list[mid]) {
			high = mid-1;
			//Lowers the value of high if the value is lower than the midpoint
		}
		else if (value > list[mid]) {
			low = mid+1;
			//Raises the value of low if the value is higher than the midpoint
		}
		else {
		//returns true and the proper location if the value is found
			find = true;
			j = mid;
			val = list[mid];
			return SearchResultType<T>(find, val, j);
		};
	};
	//Returns false and the last location searched if the value is not found
	j = mid;
	val = list[mid];
	return SearchResultType<T>(find, val, j);
};

template <typename T>
SearchResultType<T> recursive_binary_search(const std::vector<T> &list, const T &value){
	return bin_search_func(list, value, 0, list.size()-1);
	//Calls function for recursive search
};

template <typename T>
SearchResultType<T> bin_search_func(const std::vector<T> &veclist, const T &key, int lo, int hi) {
	bool find = false;
	long j;
	int low = lo;
	int high = hi;
	int mid = (low + (high-low)/2);
	//Calculates midpoint based on given low and high
	T val=veclist[mid];
	if (low>=high) {
		if (val!=key) return SearchResultType<T>(false, val, mid);
		else return SearchResultType<T>(true, val, mid);
		//If low is equal or geater than high, then the search is over
		//If the value is found, returns true and the location
		//If the value is not found, returns false and the last location searched
	}
	if (key < veclist[mid]) {
		return bin_search_func(veclist, key, low, mid-1);
		//Lowers the value of high if the value is lower than the midpoint
	}
	else if (key > veclist[mid]) {
		return bin_search_func(veclist, key, mid+1, high);
		//Raises the value of low if the value is higher than the midpoint
	}
	else {
		//Returns true and the proper location if the value is found
		find = true;
		val = veclist[mid];
		j = mid;
		return SearchResultType<T>(find, val, j);
	};
};