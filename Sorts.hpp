/*
@File Sorts.hpp
@Author Kyle Lindteigen
@Assignment: EECS-268 Lab 7
@brief The hpp file for the sorts class that houses all of the different sorts that we are testing
@Date October 31, 2017
*/
#include<iostream>

template<typename T>
void Sorts<T>::bubleSort(T arr[], int size)
{
	T hold;
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				hold=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=hold;
			}//swaps the two if the lower position is less than the upper one
		}
	}
}

template<typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
	T hold;
	int position=0;
	for(int i=0; i<size-1; i++)
	{
		hold=arr[i];
		for(int j=i; j<size; j++)
		{
			if(arr[j]<hold)
			{
				hold=arr[j];
				position=j;
			}
		}
		arr[position]=arr[i];
		arr[i]=hold;
	}//goes through the array and finds the smallest value and then the next smallest and then the next
}

template<typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
	int j=0;
	T hold;
	for(int i=1; i<size; i++)
	{
		j=i;
		while(arr[j]<arr[j-1]&&j!=0)
		{
			hold=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=hold;
			j--;
		}
	}//goes through the array and slowly organizes a larger and larger portion of the array
}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
	Sorts<int> a;
	if(size>1)
	{
		a.mergeSort(arr, size/2);
		a.mergeSort(arr+size/2, (size-(size/2)));
		a.merge(arr, arr+size/2, size/2, (size-(size/2)));
	}
	return;
}

template<typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
	Sorts<int> sort;
	sort.quickSortRec(arr, 0, size-1, 0);//goes straight to the quick sort rec
}

template<typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
	Sorts<int> sort;
	sort.quickSortRec(arr, 0, size-1, 1);//goes straight to the quick sort rec
}

template<typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
{
	T temp[size2+size1];
	int i=0;
	int j=0;
	while(i<size1 && j<size2)
	{
		if(a1[i]<a2[j])
		{
			temp[i+j]=a1[i];
			i++;
		}
		else
		{
			temp[i+j]=a2[j];
			j++;
		}
	}//puts the smaller number first only works if sorted
	while(i<size1)
	{
		temp[i+j]=a1[i];
		i++;
	}
	while(j<size2)
	{
		temp[i+j]=a2[j];
		j++;
	}//these while statements are to add the leftovers for the arrays
	for(int i=0; i<size1+size2; i++)
	{
		a1[i]=temp[i];
	}
}

template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
	T hold;
	int index=0;
	Sorts<int> a;
	index=a.partition(arr, first, last, median);
	if(index==-1)
	{
		return;
	}//if the returned index is this then it knows to return
	if(arr[index]>=arr[last])
	{
		hold=arr[index];
		arr[index]=arr[last];
		arr[last]=hold;
		a.quickSortRec(arr, first, index-1, median);
		a.quickSortRec(arr, index+1, last, median);
	}
	else if(arr[index]<arr[last])
	{
		a.quickSortRec(arr, first, last-1, median);
	}//swaps the value at the index and recursively calls itself
	else
	{
		return;
	}
}

template<typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
	T hold;
	if((arr[first]>arr[last] && arr[last]>arr[((last-first)/2)+first])||(arr[first]<arr[last] && arr[last]<arr[((last-first)/2)+first]))
	{
	}//no change if the last number is in the middle
	else if((arr[last]>arr[first] && arr[first]>arr[((last-first)/2)+first])||(arr[last]<arr[first] && arr[first]<arr[((last-first)/2)+first]))
	{
		hold=arr[first];
		arr[first]=arr[last];
		arr[last]=hold;
	}
	else
	{
		hold=arr[((last-first)/2)+first];
		arr[((last-first)/2)+first]=arr[last];
		arr[last]=hold;
	}//swaps the median value for the last value
}

template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
	Sorts<int> a;
	if(last<=first)
	{
		return(-1);
	}//returns this to know that it is done partitioning
	if(median)
	{
		a.setMedianPivot(arr, first, last);
	}
	T hold;
	int right=last-1;
	while(first!=right)
	{
		if(arr[first]<arr[last])
		{
			first++;
		}
		else
		{
			while(first!=right&&arr[right]>=arr[last])
			{
				right--;
			}
			hold=arr[first];
			arr[first]=arr[right];
			arr[right]=hold;
		}
	}//loops through the array swaps a larger value for a smaller value and then returns the position when they meet up
	return(first);
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		if(arr[i]>arr[i+1])
		{
			cout<<i<<'\n';
			return(0);
		}
	}//goes through the array and if there is a value larger than the next one it is not sorted
	return(1);
}
