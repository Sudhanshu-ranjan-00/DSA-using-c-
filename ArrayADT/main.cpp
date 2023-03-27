#include <iostream>
#include<stdlib.h>
using namespace std;

class Array
{
private:
    int *A;
    int Size;
    int length;
    void Swap(int *x,int *y);
public:
    Array()
    {
        Size=10;
        length=0;
        A=new int[Size];
    }
    Array(int sz)
    {
        Size=sz;
        length=0;
        A=new int[Size];
    }
    ~Array()
    {
        delete []A;
    }

void Display();
void Append(int x);
void Insert( int index,int x);
int Delete( int index);
int Lsearch(int key);
int TransLsearch(int key);
int BinSearch(int key);
int RBinSearch(int a[],int l,int h,int key);
int get(int index);
void Set(int index,int x);
int Max();
int Min();
int Sum();
float Avg();
void Reverse();
void Reverse2();
void InsertSort(int x);
bool isSort();
void reSort();
Array * Merge(Array arr2);
Array * Union(Array arr2);
Array * Intersection(Array arr2);
Array * Difference(Array arr2);


};

void Array :: Display()
{
    int i;
    cout<<endl<<"Elements in the array are : "<<endl;
    for(i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;
}

void Array :: Append(int x)//Call by address type
//Because the array is supposed to be modified
{
    if(length<Size)
    {
        A[length++]=x;
    }
}

void Array :: Insert(int index,int x)
{
    if(index>=0&&index<=length)
    {
        for(int i=length;i>index;i--)
        {
            A[i]=A[i-1];
        }
        A[index]=x;
        length++;
    }
}

int  Array :: Delete(int index)
{
    int x=-1;
    if(index>=0&&index<=length)
    {
        x=A[index];
        for(int i=index;i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
        return x;
    }
    return -1;
}

int  Array ::  Lsearch(int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(key==A[i])
            return i;
    }
    return -1;
}

void  Array ::  Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int  Array ::  TransLsearch(int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(key==A[i])
        {
           // Swap(&arr->A[i],&arr->A[i-1]);
            Swap(&A[i],&A[0]);
            return i;
        }

    }
    return -1;
}

int  Array ::  BinSearch(int key)
{
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==A[mid])
        {
            return mid;
        }
            else if(key<A[mid])
            {
                h=mid-1;;
            }
            else{
                l=mid+1;
            }
    }
    return -1;
}

int  Array :: RBinSearch(int a[],int l,int h,int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
        {
            return mid;

        }
        else if(key<a[mid])
        {
            return RBinSearch(a,l,mid-1,key);
        }
        else{
            return RBinSearch(a,mid+1,h,key);
        }
    }
    return -1;
}

int  Array ::  get(int index)
{
    if(index>=0&&index<length)
    {
        return A[index];
    }
    else{
        return -1;
    }
}
void  Array ::  Set(int index,int x)
{
    if(index>=0&&index<length)
    {
        A[index]=x;
    }
}

int  Array ::  Max()
{
    int max=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    return max;
}


int Array :: Min()
{
    int min=A[0];
    for(int i=0;i<length;i++)
    {
        if(A[i]<min)
        {
            min=A[i];
        }
    }
    return min;
}

int Array :: Sum()
{
    int total=0;
    for(int i=0;i<length;i++)
    {
        total=total+A[i];
    }
    return total;
}

float  Array ::  Avg()
{
    return (float)Sum()/length;
}

void  Array ::  Reverse()
{
    int *B;
    int i,j;
    B=new int(length);
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    }
    for(i=0;i<length;i++){
        A[i]=B[i];
    }
}

void  Array ::  Reverse2()
{
    int i,j;
    for(i=length-1,j=0;i>j;i--,j++)
    {
        Swap(&A[j],&A[i]);
    }
}

void  Array ::  InsertSort(int x)
{
    int i=length-1;
    if(length==Size)
    {
        return;
    }
    else{
        while(i>=0&&A[i]>x)
        {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=x;
        length++;
    }
}

bool  Array ::  isSort()
{
    int i;
    for(i=0;i<length-1;i++)
    {
        if(A[i]>A[i+1])
        {
            return false;
        }
    }
    return true;
}

void  Array ::  reSort()
{
    int i,j;
    i=0;
    j=length-1;
    while(i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[i]>=0){
            j--;
        }
        if(i<j)
        {Swap(&A[i],&A[j]);
    }
}}

Array * Array ::  Merge(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
        }
        else{
            arr3->A[k++]=arr2.A[j++];
        }
    }
    for(;i<length;i++)
    {
        arr3->A[k++]=A[i];
    }
    for(;j<arr2.length;j++)
    {
        arr3->A[k++]=arr2.A[j];
    }
    arr3->length=((length)+(arr2.length));
    arr3->Size=((Size)+(arr2.Size));


    return arr3;

}

Array * Array :: Union(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
        }
        else if(arr2.A[j]<A[i]){
            arr3->A[k++]=arr2.A[j++];
        }
        else{
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    for(;i<length;i++)
    {
        arr3->A[k++]=A[i];
    }
    for(;j<arr2.length;j++)
    {
        arr3->A[k++]=arr2.A[j];
    }
    arr3->length=k;
    arr3->Size=((Size)+(arr2.Size));


    return arr3;

}

Array * Array :: Intersection(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3 = new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            i++;
        }
        else if(arr2.A[j]<A[i]){
            j++;
        }
        else if(A[i]==arr2.A[j]){
            arr3->A[k++]=A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->Size=((Size)+(arr2.Size));


    return arr3;

}


Array * Array :: Difference(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
        {
            arr3->A[k++]=A[i++];
        }
        else if(arr2.A[j]<A[i]){
                j++;
        }
        else{
         i++;
        j++;
        }
    }
    for(;i<length;i++)
    {
        arr3->A[k++]=A[i];
    }
    arr3->length=k;
    arr3->Size=((Size)+(arr2.Size));


    return arr3;

}

int main()
{
    Array *arr1;
    int ch,sz;
    int index,x;
    cout<<"Enter the size : "<<endl;
    cin>>sz;
    arr1=new Array(sz);
    do{
    cout<<"Menu\n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
    cout<<"3. Search\n";
    cout<<"4. Sum\n";
    cout<<"5. Display\n";
    cout<<"6. Exit\n";

    cout<<"Enter your choice : "<<endl;
    cin>>ch;

    switch(ch)
    {
        case 1 :
            cout<<"Enter the index : "<<endl;
            cin>>index;
            cout<<"Enter the element : "<<endl;
            cin>>x;
            arr1->Insert(index,x);
            break;
        case 2:
            cout<<"Enter index : "<<endl;
            cin>>index;
            x=arr1->Delete(index);
            cout<<"Deleted element is : "<<x<<endl;
            break;
        case 3:
            cout<<"Enter the element to search"<<endl;
            cin>>x;
            index=arr1->Lsearch(x);
            cout<<"Element is present on : "<<index<<endl;
            break;
        case 4:
            cout<<"Sum is  : "<<arr1->Sum()<<endl;
            break;
        case 5:
            arr1->Display();
            break;

    }
    }while(ch<6);
return 0;
}
