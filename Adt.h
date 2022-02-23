class Adt
{
	public:
		Adt();
		Adt(int);
		
		int getSize(); /// --------> Working fine 
		int getLength(); /// --------> Working fine 
		
		void display(); /// --------> Working fine 
		void displayL();
		
		void add(int); /// --------> Working fine 
		void append(int); /// --------> Working fine 

		void insert(int,const int); /// --------> Working fine 
		
		int search(int); /// --------> Working fine 
		
		void deleteByIndex(int); /// --------> Working fine 
		void deleteByValue(int);  /// --------> Working fine 

		int _max(void);/// --------> Working fine 
		int _min(void);/// --------> Working fine 

		int sMax(void);/// --------> Working fine 
		int sMin(void);/// --------> Working fine 

		void reverse();/// --------> Working fine 

		void shiftR(int); ///shift right by n places. /// --------> Working fine 
		void shiftL(int); ///shift left by n places.
		
		void help();
		
		
		~Adt();
	
	
	private:
		int *m_rootP;
		int m_size;
		int m_length;
		
		void setSize(int); /// --------> Working fine 
		void setLength(int); /// --------> Working fine 
		int* onePlace(int); /// --------> Working fine 
		void increment(int); /// --------> Working fine 
};




Adt :: Adt () {}

Adt :: Adt (int t_siz) : m_size(t_siz) 
{
	m_length={0};
	m_rootP = new int[t_siz];
	help();
}


int Adt :: getSize() 
{
	return m_size;
}
void Adt :: setSize(int t_size) 
{
	m_size = (t_size < 0) ? 0 : t_size;
}
int Adt :: getLength() /// --------> Working fine 
{
	return m_length;
}
void Adt :: setLength(int t_length) 
{
	m_length = (t_length < 0) || (t_length > getSize()) ? 0 : t_length;
}

void Adt :: displayL()
{
	int tmpLength = getLength();
	if(tmpLength == 0)
		std::cout<<"Empty Array\n";
	else
		for(int itr = 0; itr < tmpLength; ++itr)
		{
			std::cout<<m_rootP[itr]<<" ";
		}
	std::cout<<'\n';
}
void Adt :: display() 
{
	for(int itr = 0; itr < getSize(); ++itr)
	{
		std::cout<<m_rootP[itr]<<" ";
	}
	std::cout<<'\n';
}

void Adt :: add(int t_value) 
{
	int tmpLen = getLength();
	int tmpSize = getSize();
	
	if(tmpLen < tmpSize)
	{
		m_rootP[tmpLen] = t_value;
		setLength(tmpLen+1);
	}
	else
	{
		append(t_value);
	}
	
}

void Adt :: append(int t_value) 
{
	int tmpLen = getLength();
	int tmpSize = getSize();
	
	if(tmpLen < tmpSize)
	{
		add(t_value);
	}
	else
	{
		//int *tmpP = new int [tmpSize+1];
		int *tmpP = onePlace(1);
		int itr;
		for(itr = 0; itr < tmpSize; ++itr)
		{
			tmpP[itr] = m_rootP[itr];
		}
		tmpP[itr] = t_value;
		
		delete[] m_rootP;
		m_rootP = tmpP;
		tmpP = nullptr;
		/*
		setSize(tmpSize+1);
		setLength(tmpLen+1);
		*/
		increment(1);
	}
}


void Adt :: insert(int t_index, const int t_value) ///  index , value    
{
	int tempSize = getSize();
	int tempLength = getLength();
	
	if(tempLength >= tempSize)
	{
		int *tmpA = onePlace(tempSize+1);
		int itr;
		for(itr = 0; itr < t_index; ++itr)
		{
			tmpA[itr] = m_rootP[itr];
		}
		tmpA[itr] = t_value;
		for(int itr1 = itr+1; itr1 < tempSize+1; ++itr1)
		{
			tmpA[itr1] = m_rootP[itr1-1];
		}
		
		delete[] m_rootP;
		m_rootP = tmpA;
		tmpA = nullptr;
		
		increment(1);
	}
	else if (tempLength < tempSize)
	{
		int itr2;
		for(itr2 = tempSize-1; itr2 > t_index; --itr2)
		{
			m_rootP[itr2] = m_rootP[itr2-1];
		}
		m_rootP[itr2] = t_value;
		setLength(tempLength+1);
	}
	return;
}

int Adt :: search(int t_value)
{
	for(int itr = 0; itr < getLength(); ++itr)
	{
		if(m_rootP[itr] == t_value)
			return itr;
	}
	return {-1};
}

void Adt :: deleteByIndex(int t_index)
{
		
	int tmpSize = getSize();
	int *tmpArr = onePlace(tmpSize-1); //new int [tmpSize-1];
	
	int itr;
	for( itr = 0; itr < t_index; ++itr)
	{
		tmpArr[itr] = m_rootP[itr];
	}
	for( itr = t_index; itr < tmpSize-1; ++itr)
	{
		tmpArr[itr] = m_rootP[itr+1];
	}
	
	delete[] m_rootP;
	m_rootP = tmpArr;
	tmpArr = nullptr;
	increment(-1);
	/*
	setSize(tmpSize-1);
	setLength(getLength()-1);
	*/
}

void Adt :: deleteByValue(int t_value)
{
	int tmpIndex = search(t_value);
	if(tmpIndex == -1)
	{
		std::cout<<"\n---> value is not present in the array \n";
		return;
	}
	else
		deleteByIndex(tmpIndex);
	
}

int Adt :: _max(void)
{
	int tmpLen = getLength();
	int max = INT_MIN;
	for(int itr = 0; itr < tmpLen; ++itr)
	{
		if(m_rootP[itr] > max)
		{
			max = m_rootP[itr];
		}
	}
	return max;
}
int Adt :: _min(void)
{
	int tmpLen = getLength();
	int min = INT_MAX;
	for(int itr = 0; itr < tmpLen; ++itr)
	{
		if(m_rootP[itr] < min)
		{
			min = m_rootP[itr];
		}
	}
	return min;
}



int Adt :: sMax(void)
{
	int tmpLen = getLength();
	int max = _max();
	int sMax = 0;
	
	for(int itr = 0; itr < tmpLen; ++itr)
	{
		if(m_rootP[itr] > sMax && m_rootP[itr] < max)
		{
			sMax = m_rootP[itr];
		}
		
	}
	return sMax;
}
int Adt :: sMin(void)
{
	int tmpLen = getLength();
	int min = INT_MAX;
	int sMin = min;
	
	for(int itr = 0; itr < tmpLen; ++itr)
	{
		if(m_rootP[itr] < min)
		{
			sMin = min;
			min = m_rootP[itr];
		}
		else if(sMin > m_rootP[itr])
		{
			sMin = m_rootP[itr];
		}
	}
	return sMin;
}

void Adt :: reverse()
{

	int tmpLen = getLength();/*
	//std::cout<<'\n'<<tmpLen<<'\n';
	for (int itr = 0; itr < (tmpLen/2); ++itr)
	{
		m_rootP[itr] = m_rootP[tmpLen-itr-1];
	}
	*/
	int *tmpVar = onePlace(getSize());
	for (int itr = 0; itr < tmpLen; ++itr)
	{
		tmpVar[itr] = m_rootP[tmpLen-itr-1];
	}
	
	delete[] m_rootP;
	m_rootP = tmpVar;
	tmpVar = nullptr;
	
}

void Adt :: shiftL(int t_index) ///shift right by n places.
{
	if(t_index >= getLength())
		return;
		
	int tmpSize = getSize();
	int *tmpAr = onePlace(tmpSize); //new int [tmpSize];
	
	int itr;
	for ( itr = 0; itr < tmpSize-t_index; ++itr)
	{
		tmpAr[itr] = m_rootP[itr+t_index];
	}
	
	for (itr = 0; itr < t_index; ++itr)
	{
		tmpAr[tmpSize-t_index+itr] = m_rootP[itr];
	}
	
	delete[] m_rootP;
	m_rootP = tmpAr;
	tmpAr = nullptr;
}


void Adt :: shiftR(int t_index) ///shift left by n places.
{
	if(t_index >= getLength())
		return;
		
	int tmpSize = getSize();
	int *tmpAr = onePlace(tmpSize); //)new int [tmpSize];
	
	int itr;
	
	for (itr = t_index; itr < tmpSize; ++itr)
	{
		tmpAr[itr-t_index] = m_rootP[itr];
	}
	
	for (itr = 0; itr < t_index; ++itr)
	{
		tmpAr[tmpSize-t_index+itr] = m_rootP[itr];
	}
	
	delete[] m_rootP;
	m_rootP = tmpAr;
	tmpAr = nullptr;
} 



void Adt :: help()
{
	std::cout<<"\n\n";
	std::cout<<"public int getSize(void)"<<'\n';
	std::cout<<"public int getLength(void)"<<'\n';
	std::cout<<"public void display(void)"<<'\n';
	std::cout<<"public void displayL(void)"<<'\n';
	std::cout<<"public void add(value)"<<'\n';
	std::cout<<"public void append(value)"<<'\n';
	std::cout<<"public void insert(index,value)"<<'\n';
	std::cout<<"public int search(value)"<<'\n';
	std::cout<<"public void deleteByIndex(index)"<<'\n';
	std::cout<<"public void deleteByValue(value)"<<'\n';
	std::cout<<"public int _max(void)"<<'\n';
	std::cout<<"public int _min(void)"<<'\n';
	std::cout<<"public int sMax(void)"<<'\n';
	std::cout<<"public int sMin(void)"<<'\n';
	std::cout<<"public void reverse(void)"<<'\n';
	std::cout<<"public void shiftR(index)"<<'\n';
	std::cout<<"public void shiftL(index)"<<'\n';
	std::cout<<"public void help(void)"<<'\n';
	std::cout<<"\n\n";
}





int* Adt :: onePlace(int t_place)
{
	int *tmpArr = new int[t_place];
	return tmpArr;
}

void Adt :: increment(int t_cnt)
{
	int tempSize = getSize();
	int tempLength = getLength();
	setSize(tempSize+t_cnt);
	setLength(tempLength+t_cnt);
}

Adt :: ~Adt () 
{
	delete[] m_rootP;
	m_rootP = nullptr;
}


