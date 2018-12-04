#include<stdio.h>
#include<stdlib.h>
#include <time.h>

char *apa;
char **table,**fake;
int checkwalls();
void putail();
int check();
int movetail();
void showTable();
int checksnake();
void sunepies();
char ans;
int mov[1000];
int points=0;
int wx,wy,N,M,walls,fx,fy,m,m1,ffx,ffy,p,fahx,fahy,poo,nom;
int ii=20,hp=3,fah,over=0,delay;
int exit1=0;
char alphaba[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
 int main(void)
 {
 	int choice,i,j,aa,px,py;
 	int hal=0,zz=20,ansn,k=0;
 	int oo=0;
 	char str;
 	
 	do
 	{
	 // read horizontal dimension
	printf("Please type the horizontal dimension.Must be bigger than 10\n");
	scanf("%d",&N);
	// read vertical dimension
	printf("Please type the vertical dimension.Must be bigger than 10\n");
	scanf("%d",&M);
    do
    {
        printf("press 1 for easy mode, 2 for medium mode, or 3 for hard mode\n");
        scanf("%d",&choice);
    }while(choice!=1 && choice!=2 && choice!=3 && choice!=4);
    		
	if (choice==1)
	{
	    walls=((5*(N*M))/100);
	    p=2;
	    k=(1200/(N*M))+5;
	}
	else if(choice==2)
	{
		walls=((10*(N*M))/100);
		p=1;
		k=(1200/(N*M))+10;
	}
	else if(choice==3)
	{
		walls=((15*(N*M))/100);
		p=0;
		k=(1200/(N*M))+15;
	}
	}while(k>=N*M);
do
{
	delay=2;
	fah=1;
	apa = (char *)malloc(3*sizeof(char));	
	table = (char **) malloc(N*sizeof(char*));
    for(i=0; i<N; i++)
    {
	table[i]= (char *) malloc(M*sizeof(char));
	for(j=0; j<M; j++)
	{
	    table[i][j]='.';
	}
    }
     //rand
    srand((unsigned) time(NULL));           
    
	fake=(char**) malloc(N*sizeof(char*));
	for(i=0; i<N; i++)
    {
		fake[i]= (char *) malloc(M*sizeof(char));
		for(j=0; j<M; j++)
	{
	    	fake[i][j]='.';
	}
    }
     // walls
    wx=rand() % N;
	wy=rand() % M;
	fake[wx][wy]='#';
	for(i=1; i<walls; i++)
	{
		do
		{
			m=rand() % 3;
		}while(checkwalls()!=1);
	if(m==0)
	{
		wy--;
		fake[wx][wy]='#';
	}
	if(m==1)
	{
		wy++;
		fake[wx][wy]='#';	
	}
	if(m==2)
	{
		wx--;
		fake[wx][wy]='#';	
	}
	if(m==3)
	{
		wx++;
		fake[wx][wy]='#';	
	}
    }
     // fidi
    do             
    {
		fx=rand() % N;
		fy=rand() % M;
		ffx=fx;
		ffy=fy;
		if(fake[fx][fy]=='.')
		{
			table[fx][fy]='O';	
		}
	}while(table[fx][fy]!='O');
	 //oura 1
	do
	{
		m=rand() % 3;
	}while(checksnake()!=1);

	do   
	{
		oo=0;				
		if(m==3 && fake[fx++][fy]=='.')
		{
			table[fx][fy]='X';	
			m1=2;
		}
		else if(m==2 && fake[fx--][fy]=='.')
			{
				table[fx][fy]='X';
				m1=3;	
			}
		else if(m==1 && fake[fx][fy++]=='.')
			{
				table[fx][fy]='X';
				m1=0;
			}
	   	else if(m==0 && fake[fx][fy--]=='.')	
			{
				table[fx][fy]='X';
				m1=1;
				
			}
		else
		{
			m=rand()%3;
			oo++;
		}
	}while(oo==1);
	oo=0;	
	// oura 2	
	do     
	{
		oo=0;			
		if(m==3 && fake[fx++][fy]=='.')
		{
			table[fx][fy]='X';
				
		}
		else if(m==2 && fake[fx--][fy]=='.')
			{
				table[fx][fy]='X';	
			}
		else if(m==1 && fake[fx][fy++]=='.')
			{
				table[fx][fy]='X';
			}
	   	else if(m==0 && fake[fx][fy--]=='.')	
			{
				table[fx][fy]='X';
			}
		else
		{
			m=rand()%3;
			oo++;
		}
	}while(oo==1);
	m=m1;
	// fahhhhhhhhhhhhhh
    do             
    {
		fahx=rand() % N;
		fahy=rand() % M;
		if(table[fahx][fahy]=='.' && fake[fahx][fahy]=='.')
		{
			table[fahx][fahy]='1';	
		}
	}while(table[fahx][fahy]!='1');	
	
	showTable();
	printf("\n");
	printf("give any key to start the game :)\n");
	scanf("%s", &str);
	// KSEKINAei TO GAME
	printf("game begins\n");
	printf("-----------\n");
	do
	{
	do
	{
		do
		{
			printf("1.Prees U to move up,press D to move down,\npress R to move right or press L to move left and\n");
			printf("	how many times do you want to move your snake to this side(between 1-9)\n");
			printf("2.Press X to exit\n");
			printf("3.Press p to summone a power up\n");
			printf("your choise is--> ");
			scanf("%s", apa);  
			printf("\n");                                                
		}while(checkans()!=1);
		if(ans=='P' || ans=='p')
	    {
	    	for(i=0; i<N; i++)
	    	{
	    		for(j=0; j<M; j++)
	    		{
	    			if(table[i][j]=='@')
					{
						poo=1;
					}	
				}
			}
	    	if (p!=0 && poo==0)
	    	{
	    		p--;
	    		do
	    		{
	    			px=rand() % N;
	    			py=rand() % M;
	    			if(table[px][py]=='.' && fake[px][py]=='.')
	    			{
	    				table[px][py]='@';
					}
				}while(table[px][py]!='@');
			}
			else
			{
				printf("----You dont have any powerup or you cant have 2 powerups on the map----\n");
			}
			showTable();
		}

	}while(check()!=1);
	
	for(i=0; i<nom; i++)
	{
		movetail();
		if(ans=='U' || ans=='u' && fah<=6)
		{
			ffx--;
			sunepies();
			table[ffx][ffy]='O';
			mov[zz]=2;
			m1=2;
			zz++;
		}
		else if(ans=='D' || ans=='d' && fah<=6)
		{
			ffx++;
			sunepies();
			table[ffx][ffy]='O';
			mov[zz]=3;
			m1=3;
			zz++;
		}
		else if(ans=='R' || ans=='r' && fah<=6)
		{
			ffy++;
			sunepies();
			table[ffx][ffy]='O';
			mov[zz]=1;
			m1=1;
			zz++;
		}
		else if(ans=='L' || ans=='l' && fah<=6&& fah<=6)
		{
			ffy--;
			sunepies();
			table[ffx][ffy]='O';
			mov[zz]=0;
			m1=0;
			zz++;
		}
		else if(ans=='X' || ans=='x')
		{
			exit1=1;
			over=1;
			fah=7;
		}
		if(fah==6)
		{
			showTable();
			printf("\n");
			printf("give any key to change the map:)\n");
			scanf("%s", &str);
			N=N+2;
			M=M+2;
			points=points+100;
			free (table);
			free (fake);
		}
	}
	if(fah<6)
	{
	showTable();
	}
}while(fah<=5);
}while (exit==0 || over==0);

printf("Your score is:%d", points );

free (table);
free (fake);
free (apa);

return 0;
}

void showTable()  // pikanas emfanisi
{

    int i,j;
	printf("\n   ");
	for(i=0; i<M; i++)
	{
	    printf("%3d",(i+1));
	}
	printf("\n");
    for(i=0; i<(3+(M*3)); i++)
	{
	    printf("-");
	}
	printf("\n");

    for(i=0; i<N; i++)
	{
	    printf("%2d",(i+1));
	    printf("|");
	    printf("  ");
	    for(j=0; j<M; j++)
	    {
	    	if(fake[i][j]=='#')
	    	{
	    		if(fake[ffx][ffy]=='#')
	    		{
	    			table[ffx][ffy]='O';
				}
				else if(table[i][j]=='X')
				{
					table[i][j]=='X';
				}
				else
				{
	    		table[i][j]='#';
	    		}
			}
			printf("%c",table[i][j]);
		
		printf("  ");
	    }
	    printf("\n");
	}
	printf("POINTS:%d\n", points);
}
 
int checkwalls()  //WALLAS elenxos g out kai an mpori na mpei mesa
{
	if(wx==0 && wy==0 && (m==0))   //m==0 left  m==1 right   m==2 up  m==3 down
    {
	return 0;
    }
    else if(wx==0 && wy==0 && (m==2))
	{
	    return 0;
	}
    else if(wx==0 && wy==M-1 && (m==1))
	{
	    return 0;
	}
	else if(wx==0 && wy==M-1 && (m==2))
	{
		return 0;
	}
	else if(wx==0 && (m==2))
	{
		return 0;
	}
    else if(wx==N-1 && wy==M-1 && (m==3))
	{
	    return 0;
	}
	else if(wy==M-1 && (m==3))
	{
	    return 0;
	}
	else if(wx==N-1 && wy==M-1 && (m==1))
	{
	    return 0;
	}
	else if(wx==N-1 && wy==0 && (m==3))
	{
	    return 0;
	}
	else if(wx==N-1 && wy==0 && (m==0))
	{
	    return 0;
	}
	else if(wx==N-1 && (m==3))
	{
	    return 0;
	}
	else if(wy==0 && (m==0))
	{
	    return 0;
	}
	else if(m==0 && fake[wx][wy-1]!='.')
	{
		return 0;
	}
	else if(m==1 && fake[wx][wy+1]!='.')
	{
		return 0;
	}
	else if(m==2 && fake[wx-1][wy]!='.')
	{
		return 0;
	}
	else if(m==3 && fake[wx+1][wy]!='.')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int checksnake()  //snake elenxos g oura
{
	if(fx==0 && m==2 && fake[N-1][fy]=='#')  		 //m==0 left  m==1 right   m==2 up  m==3 down
    {
    	return 0;
    }
    else if(fy==0 && m==0 && fake[fx][M-1]=='#')
	{
	    return 0;
	}
    else if(fy==M-1 && m==1 && fake[fx][0]=='#')
	{
	    return 0;
	}
	else if(fx==N-1 && m==3 && fake[0][fy]=='#')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int check() //elenxei k metakini
{
   	if(m1==0 && (ans=='r' || ans=='R'))
   	{
   		return 0;	
	 }
	 else if(m1==1 && (ans=='L' || ans=='l'))
	 {
	 	return 0;
	 }
	 else if(m1==2 && (ans=='D' || ans=='d'))
	 {
	 	return 0;
	 }
	 else if(m1==3 && (ans=='U' || ans=='u'))
	 {
	 	return 0;
	 }
	 else if(ans=='p' || ans=='P')
	 {
	 	return 0;
	 }
	 else if(ans=='X' || ans=='x')
	 {
	 	return 1;
	 }
	else
	{
		return 1;
	}
		
}

void sunepies() // sunepies
{  
	int cnt,i,j;
	int lol;
	if(ffx==N && (ans=='D' || ans=='d'))
	{
		ffx=0;	
	}
	else if(ffx==-1 && (ans=='U' || ans=='u'))
	{
	    ffx=N-1;
	}
	else if(ffy==-1 && (ans=='L' || ans=='l'))
	{
		ffy=M-1;
	}
    else if(ffy==M && (ans=='R' || ans=='r'))
    {
		ffy=0;
    }
	
	if(fake[ffx][ffy]=='#')
	{
		hp--;
		printf("----Snake hit its head on a wall.You lost 1 life----\n");
		printf("----You have %d more left----",hp);
		fake[ffx][ffy]='.';
		if(hp==0)
		{
			over=1;
			exit1=1;
			fah=7;
		}
	}
	else if(table[ffx][ffy]=='1')
	{
		printf("----snake feed----\n");
		fah++;
		putail();
	 do             
    {
		fahx=rand() % N;
		fahy=rand() % M;
		if(table[fahx][fahy]=='.' && fake[fahx][fahy]=='.')
		{
			table[fahx][fahy]='2';	
		}
	}while(table[fahx][fahy]!='2');
	}
	else if(table[ffx][ffy]=='2')
	{
		printf("----snake feed----\n");
		for(i=0; i<fah; i++)
		{
			putail();	
		}
		fah++;
	 do             
    {
		fahx=rand() % N;
		fahy=rand() % M;
		if(table[fahx][fahy]=='.' && fake[fahx][fahy]=='.')
		{
			table[fahx][fahy]='3';	
		}
	}while(table[fahx][fahy]!='3');
	}
	else if(table[ffx][ffy]=='3')
	{
		printf("----snake feed----\n");
		for(i=0; i<fah; i++)
		{
			putail();	
		}
		fah++;
	 do             
    {
		fahx=rand() % N;
		fahy=rand() % M;
		if(table[fahx][fahy]=='.' && fake[fahx][fahy]=='.')
		{
			table[fahx][fahy]='4';	
		}
	}while(table[fahx][fahy]!='4');
	}
	else if(table[ffx][ffy]=='4')
	{
		printf("----snake feed----\n");
		for(i=0; i<fah; i++)
		{
			putail();	
		}
		fah++;
	 do             
    {
		fahx=rand() % N;
		fahy=rand() % M;
		if(table[fahx][fahy]=='.' && fake[fahx][fahy]=='.')
		{
			table[fahx][fahy]='5';	
		}
	}while(table[fahx][fahy]!='5');
	}
	else if(table[ffx][ffy]=='5')
	{
		for(i=0; i<fah; i++)
		{
			putail();	
		}
		fah++;
		points=points+(hp*20);
		printf("----Good Job----\n");
		printf("----Get ready for the next round----");	
	}
	else if(table[ffx][ffy]=='X')
	{
		printf("----Snake cant eat itself----");
		over=1;
		exit1=1;
		fah=7;
	}
	else if(table[ffx][ffy]=='@')
	{
		poo=0;
		cnt=rand() % 3; 
		if(cnt==1) //walls
		{
			printf("----Well played 2 walls down----\n");
			lol=0;
			for(i=0; i<N; i++)	
			{
				for(j=0; j<M; j++)
				{
					if(fake[i][j]=='#' && lol<2)
					{
						table[i][j]='.';
						fake[i][j]='.';
						lol++;
					}
				}
			}	
		}
		else if(cnt==2) //points
		{
			points= points+100;
			printf("----you got 100 points :D\n----");
		}
		else //oures
		{
			printf("----Snake trap 2xtails--\n");
			for(i=0; i<2; i++)
			{
				table[fx][fy]='.';
				if (mov[ii]==0)
				{
					fy--;
					ii++;
				}
				else if(mov[ii]==1)
				{
					fy++;
					ii++;
				}
				else if(mov[ii]==2)
				{
					fx--;
					ii++;
				}
				else if(mov[ii]==3)
				{
					fx++;
					ii++;
				}
				}			
			}		
		}
	
}

void putail() // eisagwgh ouras
{			
	int coin=0;
	if(fx!=N-1 && mov[ii]!=3)
	{
	if(fake[fx++][fy]=='.' && table[fx][fy]=='.' && coin==0)
	{
		mov[--ii]=2;
		table[fx][fy]='X';
		coin=1;	
		}
		else
		{
			fx--;
		}
	}
	if(fx!=1 && mov[ii]!=2)
	{
		if(fake[fx--][fy]=='.' && table[fx][fy]=='.' && coin==0)
		{
			mov[--ii]=3;
			table[fx][fy]='X';
			coin=1;	
		}
		else
		{
			fx++;
		}
	}
	if(fy!=M-1 && mov[ii]!=1)
	{
		if(fake[fx][fy++]=='.' && table[fx][fy]=='.' && coin==0)
		{
			mov[--ii]=0;
			table[fx][fy]='X';
			coin=1;
		}
		else
		{
			fy--;
		}
	}
	if(fy!=1 && mov[ii]!=0)
	{
	   	if(fake[fx][fy--]=='.' && table[fx][fy]=='.' && coin==0)	
		{
			mov[--ii]=1;
			table[fx][fy]='X';
			coin=1;
		}
		else
		{
			fy++;
		}			
	}
}

int checkans() //elenxos apantisis
{
	if(apa[0]=='U' || apa[0]=='u')
	{
		ans='u';
	}
	else if(apa[0]=='D' || apa[0]=='d')
	{
		ans='d';
	}
	else if(apa[0]=='L' || apa[0]=='l')
	{
		ans='l';
	}
	else if(apa[0]=='R' || apa[0]=='r')
	{
		ans='r';
	}
	else if(apa[0]=='X' || apa[0]=='x')
	{
		ans='x';
		nom=1;
		return 1;
	}
	else if(apa[0]=='P' || apa[0]=='p')
	{
		ans='p';
		return 1;
	}
	else
	{
		return 0;
	}
	
	if(apa[2]!='\0')
	{
		apa[2]='\0';
		return 0;
	}
	
	if(apa[1]=='1')
	{
		nom=1;
		return 1;
	}
	else if(apa[1]=='2')
	{
		nom=2;
		return 1;
	}
	else if(apa[1]=='3')
	{
		nom=3;
		return 1;
	}
	else if(apa[1]=='4')
	{
		nom=4;
		return 1;
	}	
	else if(apa[1]=='5')
	{
		nom=5;
		return 1;
	}	
	else if(apa[1]=='6')
	{
		nom=6;
		return 1;
	}
	else if(apa[1]=='7')
	{
		nom=7;
		return 1;
	}
	else if(apa[1]=='8')
	{
		nom=8;
		return 1;
	}
	else if(apa[1]=='9')
	{
		nom=9;
		return 1;
	}
	else
	{
		return 0;
	}				
}

int movetail() // inisi ouras
{
	table[ffx][ffy]='X';
		if(fake[fx][fy]=='.')
		{
			table[fx][fy]='.';
		}
		else
		{
			table[fx][fy]='#';
		}
		
		if(delay>0)
		{
			if(m==0)
			{
				fy--;
				delay--;
			}
			else if(m==1)
			{
				fy++;
				delay--;
			}
			else if(m==2)
			{
				fx--;
				delay--;
			}
			else if(m==3)
			{
				fx++;
				delay--;
			}
			return 1;
		}
		else
		{
			if(fx==N-1 && mov[ii]==3)
			{
				fx=0;
				ii++;	
			}
			else if(fx==0 && mov[ii]==2)
			{
			    fx=N-1;
			    ii++;
			}
			else if(fy==0 && mov[ii]==0)
			{
				fy=M-1;
				ii++;
			}
  		    else if(fy==M-1 && mov[ii]==1)
    		{
				fy=0;
				ii++;
   			 }
	    	else if (mov[ii]==0)
			{
				fy--;
				ii++;
			}
			else if(mov[ii]==1)
			{
				fy++;
				ii++;
			}
			else if(mov[ii]==2)
			{
				fx--;
				ii++;
			}
			else if(mov[ii]==3)
			{
				fx++;
				ii++;
			}
			return 1;
		}	
	}
	
