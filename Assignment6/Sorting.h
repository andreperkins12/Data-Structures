
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class Sorting
{
public:
	Sorting();
	~Sorting();
///////TIMER////////
	clock_t start;
    double duration;
////////END TIMER///////

	int size;
	double *array;
	
	void bubbleSort(double bS[], int size);

	void insertionSort(double iS[],int size);

	void quickSort(double qs[], int left, int right);

	void mergeSort(double theR[], int s);

	void merge(double left[], int leftLength, double right[], int rightLength, double a[]);

	void swap(int left, int right);

	int partition(double qs[], int left, int right);

	void readFrom(string textfile);


};

Sorting::Sorting(){}

Sorting::~Sorting(){}

void Sorting::readFrom(string textFile){

	int theSize = 0;
	int raySize = 1215752192;
	array = new double[raySize];
	double toPass;
	string read;
	ifstream theFile;

	theFile.open(textFile);

	cout << "Passing Data from Text File......." << endl;

	if (theFile.is_open())
	{
		
		while(getline(theFile, read)){

			toPass = stod(read);

			array[theSize] = toPass;
			
			theSize++;

			size = theSize;

			if (theFile.eof())
			{
				cout << "End of File, Data successfully processed." << endl;

				theFile.close();

				cout << "File Closed, Size:  " << size << endl;

				bubbleSort(array, size);
				insertionSort(array,size);

				cout << "------------MERGE SORT----------" << endl;

				cout << "\nSorting Started...." << endl;

				start = clock();
				mergeSort(array,size); //Problems with Merge Sort


				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				cout << "\nTime for Merge Sort to Finish: " << duration << endl; 

				cout << "--------Quick Sort-----------" << endl;

				start = clock();
				cout << "\nSorting Started...." << endl;
				quickSort(array,0,500); 
				//Problems with Quick SOrt
				duration = (clock() - start) / (double) CLOCKS_PER_SEC;
				cout << "\nTime for Quick Sort to Finish: " << duration << endl; 
			}
		}
	}

	//pass array into functions

}

void Sorting::bubbleSort(double array[],int size){  ///DONE

	cout << "---------BUBBLE SORT------------" << endl;

	ofstream theFile("bubble.txt");

	start = clock();

	cout << "SIZE: " << size << endl;

	if (size > 10000)
	{
		cout << "This may take awhile LOL " << endl;
	}

	cout << "Sorting Started...." << endl;

	for (int i = 0; i < size; ++i)
	{
		int temp = 0;

		for (int j = 0; j < size - 1; ++j)
		{
			
			
			temp = array[j + 1];

			array[j+1] = array[j];

			array[j] = temp;

			//theFile << array[j] << endl;

		}
		//theFile.close();
	}
	duration = (clock() - start) / ((double) CLOCKS_PER_SEC);

	cout << "Time for Bubble Sort to Finish: " << duration << endl; 


	cout << "REACHED" << endl;

	
}


void Sorting::insertionSort(double insertRay[], int size){ //Done

	cout << "---------INSERTION SORT-----------" << endl;

	cout << "SIZE: " << size << endl;

	cout << "Sorting Started...." << endl;

	start = clock();

	for (int i = 0; i < size; ++i)
	{
		int temp = insertRay[i];

		int k = i;


		while(k > 0 && insertRay[k - 1] >= temp){

			insertRay[k] = insertRay[k - 1];

			--k;
		}

		insertRay[k] = temp;

		
	}

	duration = (clock() - start) / (double) CLOCKS_PER_SEC;

	cout << "Time for Insertion Sort to Finish: " << duration << endl; 

}

void Sorting::mergeSort(double a[], int length) {

    if (length <= 1) return;

    double* left = new double[length/2];
    double* right = new double[length - length/2];

    for (int i = 0; i < length/2; ++i){

    	left[i] = a[i];
    } 
    for (int i = length/2; i < length; ++i){

    	right[i-length/2] = a[i];
    } 

    mergeSort(left, length/2);
    mergeSort(right, (length - length/2));
    merge(left, length/2, right, (length - length/2), a);

}



void Sorting::merge(double left[], int leftLength, double right[], int rightLength, double a[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < leftLength) && (j < rightLength)) {

        if (left[i] <= right[j]) {

            a[k++] = left[i++];

        } else {
            a[k++] = right[j++];
        }
    }

    while (i < leftLength) {

        a[k++] = left[i++];
    }

    while (j < rightLength) {

        a[k++] = right[j++];
    }
}





void Sorting::quickSort(double array[], int left, int right){

bool complete = false;

int idx = partition(array,left,right);


double totalTime = 0;


while(!complete){
	

	if (left < idx - 1)
	{

		quickSort(array,left,idx - 1);
		break;

	} if (idx < right)
	{
		quickSort(array,idx + 1,right);

		break;

	}

	complete =  true;

}

	

}

int Sorting::partition(double arr[], int left, int right){

	  int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
     
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }

      swap(i,j);

	return left;
}

void Sorting::swap(int left, int right){

	int temp;
	temp = left;
	left = right;
	right = temp;

}






