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
    void Qsort(vector<T>& vec, int left, int right)
	{
		T pivot;
		if(left < right)
		{
			pivot = Partition(vec, left, right);

			Qsort(vec, left, pivot-1);
			Qsort(vec, pivot+1, right);
		}
	}

	T Partition(vector<T>& vec, int left, int right)
	{
		T pivotkey;
		pivotkey = vec.at(low); //此处可以设计算法采用更随机位置的序列值作为起始
		while(low < high)
		{
			while(left < right && vec.at(right) >= pivotkey)
			{
				right--;
			}

			Swap(vec, left, right);

			while(left < right && vec.at(left) <= pivotkey)
			{
				left++;
			}

			Swap(vec, left, right);
		}
		return left;
	}

	void Swap(vector<T>& vec, int left, int right)
	{
		T tempt_value = vec.at(left);
		vec.at(left) = vec.at(right);
		vec.at(right) = tempt_value;
	}

	vector<T> m_sequence;
};

#define QUICKSORT_H
#endif
