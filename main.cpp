#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void insertionSort( std::deque<int> &arr);
int linearSearch(const std::vector <int> &vec, int val);
void SelectionSort( std::deque<int> &arr);
bool binarySearch(const array <int,10> &arr,int val);
long int hornerPolynomialEvaluator(const vector<int> &vec, int &x);
void MergeSort(std::vector<int> &A);
void Inversions(std::deque<int> &A, unsigned long &cnt);
void quickFind(int N);
void stringMatcher(string T, string pattern);


int main() {


    return 0;
}


//Insertion Sort Algorithm taking a deque type by  reference
// algorithmic complexity is O(n^2)
/* High level approach
 * Beginning from the second element to the last, if the element before it is greater than it, swap positions, do this
 * until the character before this is equal or less than, or the array index is less than 0*/

void insertionSort( std::deque<int> &array){

    int temp, idxBefore;

    for (int idx=1;idx<array.size();++idx){

        idxBefore=idx-1;


        while (idxBefore>=0  && array[idxBefore]<array[idx] ){

            temp=array[idxBefore];
            array[idxBefore]=array[idx];
            array[idx]=temp;
            idx=idxBefore;
            --idxBefore;

        }
    }

}

/* Linear Search algorithm taking a vector by constant reference
 * Traverses the entire until value is found or the end of vector is reached
 * if found returns the index of the value, else prints out not found*/

int linearSearch(const std::vector <int> &vec, int val){

     std::vector<int>::const_iterator beg=vec.cbegin();
    int idx=0;

    while (beg!=vec.cend()){

        if (*beg==val){
            return idx;



        } else{
            ++idx;
            ++beg;
        }



    }
    std::cout<<"not found";

}

/* Selection Sort algorithm, taking a reference from a deque object, for each character in the array except the last,
 * find the minimum in the array, then swap positions, continue until you reach the n-1 character*/

void SelectionSort( std::deque<int> &arr){

    int min; int swapIdx=0;int temp;


    for (int idx=0;idx<arr.size()-1;++idx){
        min=arr[idx];

        for (int j=idx+1;j<arr.size();++j){

            if (arr[j]>min){

                min=arr[j];
                swapIdx=j;
            }
        }
        temp=arr[idx];
        arr[idx]=min;

        arr[swapIdx]=temp;



    }
}
/* Binary search algorithm, continuously divide the list into two parts, until the value is found ,by the reference
 * given by the middle element*/

bool binarySearch(const array <int,10> &arr,int val){

    int start=0;
    int end=9;
    int mid=(start+end)/2;
    bool found =false;

    while (mid!=end && not found  ){{

            if (arr[mid]==val){

                found=true;
            }else if (arr[mid]>val){

                end=mid;

            }else{
                start=mid+1;
            }
            mid=(start+end)/2;

        }



    }
    return found;



}/* Algorithm for evaluating polynomial of any degree, input is a vector of coefficients and the value to be
 * evaluated at, better for user to reserve the exact size of vector for better memory use*/

long int hornerPolynomialEvaluator(const vector<int> &vec, int &x){

    auto beg=vec.cbegin()+1; long int result=*vec.cbegin(); auto end=vec.cend();
    while (beg!=end){


        result=(result*x)+ *(beg);
        ++beg;

    }

    return result;

}
//Merge Sort, sorting a colection in nlogn time

void MergeSort(std::vector<int> &A){

    if (A.size()>1){

        auto mid= A.begin()+A.size()/2;

        std::vector<int> leftHalf(A.begin(),mid);

        std::vector<int> rightHAlf(mid,A.end());

        MergeSort(leftHalf);
        MergeSort(rightHAlf);

        int i=0,j=0,k=0;

        while (i<leftHalf.size()  &&  j<rightHAlf.size()){

            if (leftHalf[i]<=rightHAlf[j]){

                A[k]=leftHalf[i];
                ++i;

            }else{

                A[k]=rightHAlf[j];
                ++j;

            }
            ++k;

        }while (i<leftHalf.size()){

            A[k]=leftHalf[i];
            ++i;
            ++k;


        } while (j<rightHAlf.size()){


            A[k]=rightHAlf[j];
            ++j;
            ++k;
        }

    }}

//This function finds the number of inversions in an array,
//Given index i> index j, and A[j]>A[i], we have an inversion.
//This algorithm uses the merge sort approach

void Inversions(std::deque<int> &A, unsigned long &cnt){

    if (A.size()>1){

        auto mid= A.begin()+A.size()/2;

        std::deque<int> leftHalf(A.begin(),mid);

        std::deque<int> rightHAlf(mid,A.end());



        Inversions(leftHalf,cnt);
        Inversions(rightHAlf,cnt);

        int i=0,j=0,k=0;

        while (i<leftHalf.size()  &&  j<rightHAlf.size()){

            if (leftHalf[i]<=rightHAlf[j]){

                A[k]=leftHalf[i];
                ++i;

            }else{

                cnt=cnt+(leftHalf.size()-i);

                A[k]=rightHAlf[j];
                ++j;

            }
            ++k;

        }while (i<leftHalf.size()){

            A[k]=leftHalf[i];
            ++i;
            ++k;


        } while (j<rightHAlf.size()){


            A[k]=rightHAlf[j];
            ++j;
            ++k;
        }

    }


}

//Algorithm for solving connectivity problem using the quick find approach, uses an array, where the elements in
// question are the array indices and uses the values of the array to show whether these objects are connected

void quickFind(int N){
    int arr[N];

    int p,q,t;

    for (int i=0;i!=N;++i){

        arr[i]=i;
    }
    while (cin>>p>>q){
        t=arr[p];

        if (t==arr[q]){

            continue;
        }
        for (int i=0;i!=N;++i){

            if (arr[i]==t){

                arr[i]=arr[q];
            }

        }
        cout<<p<<" "<<q<<"\n";

    }




}

//Algorithm for finding n combination r
inline unsigned long long comb(int n,int r){
    int idx=1;
    int bottom=min(r,n-r);

    unsigned long long total=1;

    while (idx!=bottom+1){

        total*=n;
        --n;
        total/=idx;
        ++idx;


    }
    return total;

}

//Algorithm for finding the number of occurences of pattern in a text
void stringMatcher(string T, string pattern){

  long long index=0;
  bool first_char_found =false;
  long long count=0;
  long long Tsize = T.size ();
  long long pSize = pattern.size ();

  for (int i=0;i<Tsize;++i){

      if (! first_char_found){

          if (T[i]==pattern[index]){

              first_char_found=true;
              ++index;

            }
          else{
              continue;
            }
        }
      else {

          if (T[i]==pattern[index]){

              ++index;
            }
          else{

              if (index==pSize){
                  ++count;
                }

              if(T[i]==pattern[0]){
                  first_char_found=true;
                  index=1;
                }
              else{
                  index=0;
                  first_char_found=false;
                  continue;
                }


            }
        }

      if (index==pSize){
          ++count;
          index=0;
          first_char_found=false;
        }
    }
  printf ("%lld",count);

}

