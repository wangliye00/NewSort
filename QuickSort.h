#ifndef QUICKSORT_H

#include <vector>

using namespace std;

template<typename T>
class QuickSort
{
public:
	QuickSort(vector<T> vec):m_sequence(vec){}

	virtual ~QuickSort(){}

	void Run()
	{
		Qsort(m_sequence, 0, m_sequence.size()-1);
	}
private:
    void Qsort(vector<T>& vec, int low, int high)
	{
		T pivot;
		if(low < high)
		{
			pivot = Partition(vec, low, high);

			Qsort(vec, low, pivot-1);
			Qsort(vec, pivot+1, high);
		}
	}

	T Partition(vector<T>& vec, int low, int high)
	{
		T pivotkey;
		pivotkey = vec.at(low); //此处可以设计算法采用更随机位置的序列值作为起始
		while(low < high)
		{
			while(low < high && vec.at(high) >= pivotkey)
			{
				high--;
			}

			Swap(vec, low, high);

			while(low < high && vec.at(low) <= pivotkey)
			{
				low++;
			}

			Swap(vec, low, high);
		}
		return low;
	}

	void Swap(vector<T>& vec, int low, int high)
	{
		T tempt_value = vec.at(low);
		vec.at(low) = vec.at(high);
		vec.at(high) = tempt_value;
	}

	vector<T> m_sequence;
};

#define QUICKSORT_H
#endif