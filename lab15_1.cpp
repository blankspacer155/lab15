#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void showData(double * dptr, int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(dptr+i);
        if((i+1)%M==0) cout << endl;
        else cout << " ";
    }
}

void randData(double * dptr, int N ,int M){
    for(int i = 0; i < N*M; i++){
        *(dptr+i) = (rand()%101)/100.0;
    }
}

void findRowSum(const double *dptr,double * aptr,int roll ,int col) 
{
	//ส่งในข้อย่อยผิดแต่ส่งโค้ดรวมถูก
	/* int aind=0;
	for(int i=0;i<roll*col;i++)
	{
		*(aptr+aind)+=*(dptr+i);
		if((i+1)%col==0)aind++;
	} */
	int aind=0;
	double sumroll=0;
	for(int i=0;i<roll*col;i++)
	{
		sumroll+=*(dptr+i);
		if((i+1)%col==0)
		{
		*(aptr+(aind++))=sumroll;
		sumroll=0;
		}
	}
}
void findColSum(const double *dptr,double * aptr,int roll ,int col) 
{
	//ส่งในข้อย่อยผิดแต่ส่งโค้ดรวมถูก
	/* int aind=0;
	for(int i=0;i<roll*col;i++)
	{
		*(aptr+aind)+=*(dptr+i);
		aind++;
		if((i+1)%col==0)aind=0;
	} */
	int ind=0;
	double sumcol[col];
	for(int i=0;i<roll*col;i++)
	{
	    sumcol[ind]+=*(dptr+i);
		ind++;
		if((i+1)%col==0)ind=0;
	}
	for(int i=0;i<col;i++)
	{
	    *(aptr+i)=sumcol[i];
	}
}