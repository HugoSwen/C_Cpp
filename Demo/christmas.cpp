#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int s1[2][10]={{0,262,294,330,349,392,440,494},
			   {0,277,311,-99,370,415,466,-99}};
			   
int s2[2][10]={{0,523,587,659,698,784,880,988},
			   {0,554,622,-99,740,831,932,-99}};
			   
int s3[2][10]={{0,1046,1175,1318,1397,1568,1760,1976},
			   {0,1109,1245,-999,1480,1661,1865,-999}};
 
void k(int a,int b,int c,int d)
{
	if (a==1)
		Beep(s1[b][c],d);
	if (a==2)
		Beep(s2[b][c],d);
	if (a==3)
		Beep(s3[b][c],d);
}
 
void jingdian()
{
	Beep(s2[0][3],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],800);
	
	Beep(s2[0][3],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],800);
	
	Beep(s2[0][3],400);
	Beep(s2[0][5],400);
	Beep(s2[0][1],600);
	Beep(s2[0][2],200);
	Beep(s2[0][3],1600);
	
	Beep(s2[0][4],400);
	Beep(s2[0][4],400);
	Beep(s2[0][4],600);
	Beep(s2[0][4],200);
	Beep(s2[0][4],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],200);
	Beep(s2[0][3],200);
	
	Beep(s2[0][3],400);
	Beep(s2[0][2],400);
	Beep(s2[0][2],400);
	Beep(s2[0][1],400);
	Beep(s2[0][2],800);
	Beep(s2[0][5],800);
	
	Beep(s2[0][3],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],800);
	
	Beep(s2[0][3],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],800);
	
	Beep(s2[0][3],400);
	Beep(s2[0][5],400);
	Beep(s2[0][1],600);
	Beep(s2[0][2],200);
	Beep(s2[0][3],1600);
	
	Beep(s2[0][4],400);
	Beep(s2[0][4],400);
	Beep(s2[0][4],600);
	Beep(s2[0][4],200);
	Beep(s2[0][4],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],400);
	Beep(s2[0][3],200);
	Beep(s2[0][3],200);
	
	Beep(s2[0][5],400);
	Beep(s2[0][5],400);
	Beep(s2[0][4],400);
	Beep(s2[0][2],400);
	Beep(s2[0][1],1200);
}
 
int main()
{
	jingdian();
	return 0;
}
