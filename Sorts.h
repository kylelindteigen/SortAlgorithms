/*
@File Sorts.h
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 7
@brief header file for the sort function that holds all of the sort public functions and private helper functions
@Date October 31, 2017
*/
#ifndef SORTS_H
#define SORTS_H

template<typename T>
class Sorts
{
	public:

		/* 
		@pre  enter an arrray with it's size
		@post  swaps a value with the one after it if it is larger untill all the values are in place
		@param arr[] an array of values to be sorted
		@param size size of the array
		*/

		static void bubleSort(T arr[], int size);

		/* 
		@pre  enter an arrray with it's size
		@post  finds the smallest value and then the next and the next untill the values are sorted
		@param arr[] an array of values to be sorted
		@param size size of the array
		*/

		static void selectionSort(T arr[], int size);

		/* 
		@pre  enter an arrray with it's size
		@post  slowly organizes a larger and larger array until the whole thing is organized
		@param arr[] an array of values to be sorted
		@param size size of the array
		*/

		static void insertionSort(T arr[], int size);

		/* 
		@pre  enter an arrray with it's size
		@post reduces the array untill you are down to two size one arrays and then merges all of the arrays
		@param arr[] an array of values to be sorted
		@param size size of the array
		*/

		static void mergeSort(T arr[], int size);

		/* 
		@pre  enter an arrray with it's size
		@post partitions the array down until the array is sorted
		@param arr[] an array of values to be sorted
		@param size size of the array
		*/

		static void quickSort(T arr[], int size);

		/* 
		@pre  enter an arrray with it's size
		@post same as quick sort except it finds a median value
		@param arr[] an array of values to be sorted
		@param size size of the array
		*/

		static void quickSortWithMedian(T arr[], int size);

		/* 
		@pre  enter an arrray with it's size
		@post  checks if the array passed in is sorted
		@param arr[] an array of values to be checked
		@param size size of the array
		@return returns true if it is sorted and false if not
		*/

		static bool isSorted(T arr[], int size);
	private:

		/* 
		@pre  passes in two sorted arrays and their sizes
		@post merges the two arrays
		@param a1 array that is sorted to be combined
		@param a2 array that is sorted to be combined
		@param size1 size of a1
		@param size2 size of a2
		*/

		static void merge(T* a1, T* a2, int size1, int size2);

		/* 
		@pre array passed in to sort the first and last values and whether or not you need to calculate the median
		@post uses the index from the partition and swaps it
		@param arr[] an array of values to be sorted
		@param first the first value in the array
		@param last the last value in the array
		@param median bool that tells if you need to calculate the median
		*/

		static void quickSortRec(T arr[], int first, int last, bool median);

		/* 
		@pre array to have the median switched with the last
		@post swaps the last value with the median value
		@param arr[] to have median switched
		@param first first value in the array
		@param last last value in the array
		*/

		static void setMedianPivot(T arr[], int first, int last);

		/* 
		@pre array passed in to be partitioned
		@post partitions the array
		@param arr[] an array of values to be partitioned
		@param first first value in the array
		@param last last value in the array
		@param median bool that tells if you need to calculate the median
		@return returns the index for the point where the small and large values meet
		*/

		static int partition(T arr[], int first, int last, bool median);
};
#include "Sorts.hpp"
#endif
