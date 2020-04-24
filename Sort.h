template<typename T>
void bubbleSort(T *arr, std::size_t size) {
    for (std::size_t i = 0; i < size - 1; ++i) {
        for (std::size_t j = 0;j < size - i - 1;++j) {
            if (arr[j] > arr[j + 1]) {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

template<typename T>
void sortIns(T *arr, std::size_t size) {
    for (std::size_t i = 0;i < size - 1;++i) {
        std::size_t i_min = i;
        for (std::size_t j = i + 1;j < size;++j) {
            if (arr[j] < arr[i_min])i_min = j;
        }
        auto tmp = arr[i];
        arr[i] = arr[i_min];
        arr[i_min] = tmp;
    }
}

template<typename T>
void ShellSort(T *arr, int n) {
    int d = n / 2;
    while (d > 0)
    {
        for (std::size_t i = 0; i < n - d; ++i)
        {
            auto j = i;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                auto temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;
                j--;
            }
        }
        d = d / 2;
    }
}
template<typename T>
void QSort(T* arr, std::size_t size) {
	int i = 0;
	int j = size - 1;
	T mid = arr[size / 2];
	do {
		while (arr[i] < mid)++i;
		while (arr[j] > mid)--j;
		if (i <= j) {//
			auto tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			++i;
			--j;
		}
	} while (i<=j);//!
	if (j > 0) qsort(arr, size - j);
	if (i < size)qsort(arr + i,size - i);
}
template<typename T>
inline void arr_merge(T*arr, T* A, int m, int N) {
	std::size_t i = 0;
	std::size_t j = N - 1;
	std::size_t c = 0;
	std::size_t d = N - 1;
	for (int k = 0;k < N / (2 * m);++k) {
		if (k % 2 == 0) {
			while ((i < (k + 1)*m) && (j >= N - (k + 1)*m)) {
				if (arr[i] < arr[j]) {
					A[c] = arr[i];
					++i;
				}
				else {
					A[c] = arr[j];
					--j;
				}
				++c;
			}
			while (i < (k + 1)*m) {
				A[c] = arr[i];
				++i;
				++c;
			}
			while (j >= N - (k + 1)*m) {
				A[c] = arr[j];
				--j;
				++c;
			}
		}
		else
		{
			while ((i < (k + 1)*m) && (j >= N - (k + 1)*m)) {
				if (arr[i] > arr[j]) {
					A[d] = arr[j];
					--j;
				}
				else {
					A[d] = arr[i];
					++i;
				}
				--d;
			}
			while (i < (k + 1)*m) {
				A[d] = arr[i];
				++i;
				--d;
			}
			while (j >= N - (k + 1)*m) {
				A[d] = arr[j];
				--j;
				--d;
			}
		}
	}
}
template<typename T>
void simple_merge(T* arr, int N) {//������� �������
	T* A = new T[N]();
	//int i = 0, j = N - 1;
	int m = 1;//���������� ��������� ��� ������ ���� 1|12|31|42|32|24|321|32 ��� m=1;
	int count = 0;//���������� �������� �� ��,����� ������ ����� ������������, arr ��� �
	int f = true;
	while (m < N) {
		if (f) {// ������� ����� �������
			arr_merge(arr, A, m, N);
			printArr(A, N);
		}
		else {//������� ������ ������
			arr_merge(A, arr, m, N);
			printArr(arr, N);
		}
		++count;
		f = !f;
		m *= 2;
	}
}
template<typename T>
void FindBorder(T* arr, int N,int &i,int &j) {
	while ((i < N - 1) && (arr[i] <= arr[i + 1])) ++i;
	while ((j > 0) && (arr[j] <= arr[j - 1]))--j;
}
template<typename T>
void nat_arr_merge(T* arr,T* A,int N){
	int i = 0;//start index for input array
	int j = N - 1;//end index for input array
	int c = 0;//start index for A
	int d = N - 1;//end index for A
	int iB = 0;//border for i
	int jB = N - 1;//border for j
	do {
		FindBorder(arr, N, iB, jB);
		while ((i <= j) && (i <= iB) && (j >= jB)) {
			if (arr[i] < arr[j]) {
				A[c] = arr[i];
				++i;
				++c;
			}
			else {
				A[c] = arr[j];
				--j;
				++c;
			}
		}
		while ((i <= j) && (i <= iB)) {
			A[c] = arr[i];
			++i;
			++c;
		}
		while ((j >= i) && (j >= jB)) {
			A[c] = arr[j];
			--j;
			++c;
		}//end of the merger of series 1 and 2
		if (i <= j) {
			iB = i;
			jB = j;
            FindBorder(arr, N, iB, jB);
			while ((i <= j) && (i <= iB) && (j >= jB)) {
				if (arr[i] < arr[j]) {
					A[d] = arr[i];
					++i;
					--d;
				}
				else {
					A[d] = arr[j];
					--j;
					--d;
				}
			}
			while ((i <= j) && (i <= iB)) {
				A[d] = arr[i];
				++i;
				--d;
			}
			while ((j >= i) && (j >= jB)) {
				A[d] = arr[j];
				--j;
				--d;
			}//end of the merger of series 3 and 4
			iB = i;
			jB = j;
		}
	} while (i <= j);
}
template<typename T>
void naturalDoubleMergeSort(T* arr, int N) {
	T* A = new T[N];
	bool f = true;//flag
	while (true) {
		int iB = 0;//border for index i
		int jB = N - 1;//border for index j
		if (f) {
            FindBorder(arr, N, iB, jB);
			if (iB == N-1){
			    delete[]A;
			    A= nullptr;
                return;
			} //
			nat_arr_merge(arr, A, N);
			f = !f;
		}
		else {
            FindBorder(A, N, iB, jB);
			if (iB == N-1) {
				for (int i = 0;i < N;++i)arr[i] = A[i];
				delete[] A;
				A= nullptr;
				return;
			}
			nat_arr_merge(A, arr, N);
			f = !f;
		}
	}
}
template<typename T>
void merge(T* A, int N) {//Knut
	auto arr = new T[N * 2];
	for (int i = 0;i < N;++i)arr[i] = A[i];
	bool s = false;
	int i = 0;
	int j = N - 1;
	int k = N;
	int l = 2 * N - 1;
	int d = 1;
	bool f = true;
	while (true) {//step 2
		if (!s) {
			i = 0;
			j = N - 1;
			k = N;
			l = 2 * N - 1;
			d = 1;
			f = true;
		}
		else {
			i = N;
			j = 2 * N - 1;
			k = 0;
			l = N - 1;
			d = 1;
			f = 1;
		}
			while (true) {//step 3
				if (i == j) {
					arr[k] = arr[i];
					if (!f) {
						s = 1 - s;
						break;//go to step 2.
					}
					else {
						for (int i = 0;i < N;++i)A[i] = arr[i];
						return;
					}
				}
				if (arr[i] > arr[j]) {
					arr[k] = arr[j];//step 8
					k = k + d;
					--j;//step 9
					if (arr[j + 1] <= arr[j])continue;//return to step 3
					while (true) {//step 10
						arr[k] = arr[i];
						k = k + d;
						++i;//step 11
						if (arr[i - 1] > arr[i])break;//true: step 10 false:step 12
					}
				}
				else {//step 4
					arr[k] = arr[i];
					k = k + d;
					++i;//step 5
					if (arr[i - 1] <= arr[i])continue;//return to step 3
					while (true) {
						arr[k] = arr[j];//step 6
						k = k + d;
						--j;//step 7
						if (arr[j+1] > arr[j])break;//go to step 12
					}
				}
					f = 0;//step 12
					d = -d;
					auto tmp = k;
					k = l;
					l = tmp;
					continue;//return to step 3
			}
		}
}