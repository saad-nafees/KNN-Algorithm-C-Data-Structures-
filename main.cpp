#include <windows.h> // these header gives you access to the Windows API -
#include <psapi.h>
#include <stdio.h>   
#include <tchar.h>
#include <ctime>
#include <iostream>
#include "KNN.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define DIV 1048576
#define WIDTH 7

using namespace std;

void mem(){



  MEMORYSTATUSEX statex;

  statex.dwLength = sizeof (statex);

  GlobalMemoryStatusEx (&statex);


  _tprintf (TEXT("There is  %*ld percent of memory in use.\n"),WIDTH, statex.dwMemoryLoad);
  _tprintf (TEXT("There are %*I64d total Mbytes of physical memory.\n"),WIDTH,statex.ullTotalPhys/DIV);
  _tprintf (TEXT("There are %*I64d free Mbytes of physical memory.\n"),WIDTH, statex.ullAvailPhys/DIV);
  _tprintf (TEXT("There are %*I64d total Mbytes of paging file.\n"),WIDTH, statex.ullTotalPageFile/DIV);
  _tprintf (TEXT("There are %*I64d free Mbytes of paging file.\n"),WIDTH, statex.ullAvailPageFile/DIV);
  _tprintf (TEXT("There are %*I64d total Mbytes of virtual memory.\n"),WIDTH, statex.ullTotalVirtual/DIV);
  _tprintf (TEXT("There are %*I64d free Mbytes of virtual memory.\n"),WIDTH, statex.ullAvailVirtual/DIV);
  _tprintf (TEXT("There are %*I64d free Mbytes of extended memory.\n"),WIDTH, statex.ullAvailExtendedVirtual/DIV);


	
}

int main(int argc, char** argv) {
	graph a[4];
	a[0].x1=7,a[0].x2=7,a[0].c=Bad;
	a[1].x1=7,a[1].x2=4,a[1].c=Bad;
	a[2].x1=3,a[2].x2=4,a[2].c=Good;
	a[3].x1=1,a[3].x2=4,a[3].c=Good;
	
	cout << "X1\tX2\tY\n";
	for(int i=0 ; i< 4 ; i++){
		cout << a[i].x1 << "\t" << a[i].x2 << "\t" ;
			if(a[i].c==Bad){
			cout << "Bad";
		}
			else if(a[i].c=Good){
			cout << "Good";
		}
		cout << endl;
	}
	graph v;
	cout << "\nMain Coordinate: "
	<< "\nX1 :";
	cin >>  v.x1;
	cout <<"X2 :";
	cin >> v.x2;
	
	clock_t c_start = clock();
    
	knn s;
	s.testKNNfuc(a,v);
	
	 clock_t c_end = clock();

     double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
     cout << "CPU time used: " << time_elapsed_ms << " ms\n";
	 
	 mem();

	return 0;
}
