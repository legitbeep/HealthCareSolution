#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int doctor = 0;
int print = 0;
class health
{
	public:
		char user_name[10],password[10],re_password[10],id[10];
		int choice , points = 0;

	void header()
	{
	    cout<<endl;
	    cout<<setw(130);
        cout<<"---------WELCOME---TO---HEALTH---CARE---------"<<endl;

        cout<<"\n\n\t\t\t\t\t\t\t\t\t\t     ----------Steps to avoid COVID-19-------------";
        cout<<"\n\t\t\t\t\t\t\t\t\t\t     Avoid close contact with people who are sick \n\t\t\t\t\t\t\t\t\t    & wash your hands often with soap and water at least for 20 sec\n";
        cout<<"\n\t\t\t\t\t\t\t\t\t\t    -------------------------------------------------";
	}

/**** Ceaser's Cypher******/

void RSA(char *A , int N , int crypt)
{
    int p = 0;
    for(int i = 0 ; i<N && A[i] != '\0' ; i++)
    {
         p = i + p ; // variable key
        if(crypt)
        {
            A[i] = A[i] + p*p;
        }
        else
        {
            A[i] = A[i] - p*p;
        }
    }
}

/******** Dashboard *****************/

    void dashboardexit()
    {
        int count;
        cout<<endl<<setw(50)<<"Select your Choice"<<endl;
        cout<<setw(60)<<"1.FOR DASHBOARD"<<endl;
        cout<<setw(60)<<"2.FOR EXIT"<<endl;
        cout<<setw(50)<<"Enter your choice: ";
        cin>>choice;
        if(choice==1)
        dashboard();
        else
        exit(-1);
    }

/******** Main member function *********/

	void enter()
	{
		system("CLS");
		header();
		enter_again:
		cout<<endl<<setw(60);
        cout<<"--Select the Option--"<<endl<<endl;
        cout<<setw(38);
		cout<<"1.Login"<<endl;
		cout<<setw(40);
		cout<<"2.Sign Up"<<endl<<endl;
		cout<<setw(50);
		cout<<"Enter your Choice: ";
		cin>>choice;
		if(choice==1)
		{
		    cout<<endl<<setw(80);
		    cout<<setw(60)<<"--Select Login Option--"<<endl;
		    cout<<setw(39)<<"1.Doctor"<<endl<<setw(40)<<"2.Patient"<<endl<<endl;
		    cout<<setw(50);
		    cout<<"Enter your Choice: ";
		    cin>>choice;
		    if(choice==1)
                doctor=1;
		    login();
		}
		else if(choice==2)
		{
		    cout<<endl<<setw(60);
		    cout<<setw(60)<<"--Choose Sign Up Option--"<<endl;
		    cout<<setw(39)<<"1.Doctor"<<endl<<setw(40)<<"2.Patient"<<endl<<endl;
		    cout<<setw(50);
		    cout<<"Enter your Choice: ";
		    cin>>choice;
		    if(choice==1)
                doctor=1;
		    signup();
		}
		else
		{
		    cout<<endl<<setw(60);
		    cout<<setw(60)<<"Invalid Choice";
		    goto enter_again;
		}
	}

/**************** Login ****************/

	void login()
	{
		cout<<endl<<setw(60)<<"--Enter User Name--: ";
		scanf("%s",&user_name);
		char s[10];
		int j;
		int line=0,flag=1;
		ifstream user;
		user.open("user.txt");
		while(!user.eof())
		{
			user.getline(s,10);
			RSA(s,10,0);

			if(strcmp(s,user_name)==0)
			{
				flag=0;
				break;
			}
			line++;
		}
		int ch;
		if(flag)
		{
			cout<<setw(70)<<"Username does not exists"<<endl;
			cout<<endl<<setw(60)<<"Enter 1 to try again , 2 for sign up if new user : "<<endl;
			cout<<setw(70)<<"--Enter your Choice--: ";
			cin>>ch;
			if(ch==2)
                signup();
            else if(ch == 1)
                login();
            else
                exit(-1);

		}
		user.close();
		flag=1;
		idd:
		cout<<setw(70)<<"--Enter the UID/Registration Number--: ";
		scanf("%s",&id);
		ifstream userid;
		userid.open("id.txt");
		for(j=0;j<=line;j++)
		{
		    if(j==line)
		    {
		    	userid.getline(s,10);
		    	RSA(s,10,0);
		    	if(strcmp(s,id)==0)
		    	{
		    		flag=0;
				}
				else if(flag)
				{
					cout<<endl<<setw(60)<<"!!!---Incorrect UID/Registration Number---!!!"<<endl;
					goto idd;
				}
			}
			else
			{
				userid.getline(s,80);
			}
		}
		char k[10];
		int p;
		passwordd:
        j=0;
		cout<<setw(70)<<"--Enter the Password--: ";
		while(true)
        {
	        s[j]=_getch();
	        if(!((s[j]>=33 && s[j]<=126) || s[j]==8))
	        break;
	        if(s[j]==8)
	        {
		       system("CLS");
	           header();
	           cout<<endl;
	           cout<<setw(60)<<"Enter the password: ";
	           for(p=0;p<j-1;p++)
		       cout<<k[p];
		       j--;
	       }
	       else
	       {
		       k[j]='*';
		       cout<<k[j];
		       j++;
	       }
       }
       s[j]='\0';
       int dl;
       strcpy(password,s);
		ifstream pass;
		pass.open("pass.txt");
		for(j=0;j<=line;j++)
		{
		    if(j==line)
		    {
		    	pass.getline(s,10);
		    	RSA(s,10,0);
		    	if(strcmp(s,password)==0)
		    	{
		    	    cout<<endl<<endl<<endl<<"\t\t\t\tPlease Wait!!!"<<endl;
		    	    cout<<"\t\t\t\tLoading";
		    	    for(dl=1;dl<35;dl++)
                    {
                        delay(50);
                        cout<<"..!";
                    }
                    cout<<setw(80)<<endl<<endl<<"!!!!----Press 'ENTER' to CONTINUE----!!!!"<<endl;
                    _getch();
		    	    dashboard();
				}
				else
				{
					cout<<endl<<setw(60)<<"!!!---Incorrect Password---!!!"<<endl;
					goto passwordd;
				}
			}
			else
			{
				pass.getline(s,80);
				RSA(s,10,0);
			}
		}

    }

/******************* Sign Up *******************/

   void signup()
   {
   	    cout<<endl<<setw(50)<<"--Enter User Name--: ";
		scanf("%s",&user_name);
		if(doctor)
        {
            ofstream doc;
            doc.open("doctors.txt",ios::app);
            RSA(user_name,10,1);
            doc<<user_name<<endl;
            RSA(user_name,10,0);
            doc.close();
        }
		cout<<setw(60)<<"--Enter the UID/Registration Number--: ";
		scanf("%s",&id);
		pass:
		cout<<setw(55)<<"--Enter the Password--: ";
		char k[10],s[10];
		int p;
		int j=0;
		while(true)
        {
	        s[j]=_getch();
	        if(!((s[j]>=33 && s[j]<=126) || s[j]==8))
	        break;
	        if(s[j]==8)
	        {
		       system("CLS");
	           header();
	           cout<<setw(70)<<endl<<"--Enter the Password--: ";
	           for(p=0;p<j-1;p++)
		       cout<<k[p];
		       j--;
	       }
	       else
	       {
		       k[j]='*';
		       cout<<k[j];
		       j++;
	       }
       }
       s[j]='\0';
       strcpy(password,s);
       cout<<endl;
		cout<<setw(55)<<"--Re-Enter the Password--: ";
		j=0;
		while(true)
        {
	        s[j]=_getch();
	        if(!((s[j]>=33 && s[j]<=126) || s[j]==8))
	        break;
	        if(s[j]==8)
	        {
		       system("CLS");
	           header();
	           cout<<setw(70)<<endl<<"--Re-Enter the Password--: ";;
	           for(p=0;p<j-1;p++)
		       cout<<k[p];
		       j--;
	       }
	       else
	       {
		       k[j]='*';
		       cout<<k[j];
		       j++;
	       }
       }
       int dl;
       s[j]='\0';
       strcpy(re_password,s);
		if(strcmp(password,re_password)!=0)
		{
			cout<<setw(100)<<endl<<"!!!!----Re-entered Password do not matches the Password----!!!!"<<endl;
			cout<<setw(80)<<endl<<"!!!!----Press 'ENTER' to CONTINUE----!!!!"<<endl;
			_getch();
			goto pass;
		}
		else
		{
			ofstream user;
			user.open("user.txt",ios::app);
			RSA(user_name,10,1);

			user<<user_name<<endl;
			RSA(user_name,10,0);


			user.close();
			ofstream pass;
			pass.open("pass.txt",ios::app);
			RSA(password,10,1);
			pass<<password<<endl;
			RSA(password,10,0);
			pass.close();

			ofstream userid;
			userid.open("id.txt",ios::app);
			RSA(id,10,1);
			userid<<id<<endl;
			RSA(id,10,0);
			userid.close();
			cout<<endl<<endl<<endl<<"\t\t\t\tPlease Wait!!!"<<endl;
		    cout<<"\t\t\t\tLoading";
			for(dl=1;dl<35;dl++)
            {
                delay(50);
                cout<<"..!";
            }
            cout<<setw(80)<<endl<<endl<<"!!!!----Press 'ENTER' to CONTINUE----!!!!"<<endl;
            _getch();
			dashboard();
		}
   }

   /**Function for Graph***/

   void graph(int a[],int n)
   {
       initwindow(1600,800);
       line(50,50,50,750);
       line(50,750,1200,750);
       int k1=100;
       int k2=150;
       for(int k=1;k<n;k++)
       {
          line(k1,a[k-1],k2,a[k]);
          outtextxy(k2,a[k]-5,"*");
          k1=k1+50;
          k2=k2+50;
       }
       setcolor(3);
       settextstyle(3,0,3);
       outtextxy(400,20,"---------WELCOME---TO---HEALTH---CARE---------");
       setcolor(4);
       settextstyle(3,0,3);
       outtextxy(10,350,"BMI");
       setcolor(4);
       settextstyle(3,0,3);
       outtextxy(700,770,"NUMBER OF TIMES OF INPUT----->");
      _getch();
      closegraph();
      dashboardexit();
   }

   /**Function for Appointment***/

   void bookappointment()
		{
			    system("CLS");
			    header();
			    char s[80],mm[8],time[8];
			    char str[80];
			    int ch,i,dd,choice;
			    cout<<"\n\t\t\t\t\t---SELECT YOUR CHOICE---"<<endl<<endl;
			    cout<<"\t\t\t\t1.Book Appointment"<<endl;
			    cout<<"\t\t\t\t2.Check Appointment"<<endl<<endl;
			    cout<<"\t\t\t\t\tEnter your Choice: ";
			    cin>>choice;
			    if(choice==1)
				{
				    ifstream appoin;
				appoin.open("doctors.txt");
				cout<<"\n\t\t\t\tSelect the doctor for appoinment"<<endl;
				i=1;
				appoin.getline(s,80);
				while(!appoin.eof())
				{

					RSA(s,10,0);
					cout<<"\t\t\t\t";
					cout<<i<<".";
					cout<<s<<endl;
					i++;
					appoin.getline(s,80);
				}
				char dn[20];
				cout<<endl<<"\t\t\t\t\tEnter Doctor's Name for appoinment: ";
				cin>>dn;
				ifstream user;
		        user.open("user.txt");
		        int line=0,j;
		        while(!user.eof())
		        {
			        user.getline(s,10);
			        RSA(s,10,0);
			        if(strcmpi(s,dn)==0)
                        break;
			        line++;
		        }
		        ifstream userid;
		        userid.open("id.txt");
		        for(j=0;j<=line;j++)
		        {
		            if(j==line)
		    	     userid.getline(s,10);
			        else
				      userid.getline(s,80);
		        }
				cout<<"\t\t\t\t\tEnter the date: ";
				cin>>dd;
				cout<<"\t\t\t\t\tEnter the month: ";
				cin>>mm;
				cout<<"\t\t\t\t\tEnter the time: ";
				cin>>time;
				appoin.close();
				cout<<"\n\t\t\t----Your Appointment has been Successfully Registered----"<<endl;
				_getch();
				ofstream chkapp;
				chkapp.open(s,ios::app);
				chkapp<<"Patient's Name: "<<user_name<<endl;
				chkapp<<"Date: "<<dd<<endl;
				chkapp<<"Month: "<<mm<<endl;
				chkapp<<"Time: "<<time<<endl<<endl;
				chkapp.close();
				ofstream appo;
				appo.open(id,ios::app);
				appo<<"Doctor's Name: "<<dn<<endl;
				appo<<"Date: "<<dd<<endl;
				appo<<"Month: "<<mm<<endl;
				appo<<"Time: "<<time<<endl<<endl;
				appo.close();
				}
				else if(choice==2)
                {
                    ifstream appi;
                    appi.open(id);
                    if(!appi)
                    cout<<"\n\n\t\t\t\tNo Appoinments"<<endl;
                    else
                    while(!appi.eof())
                    {
                        appi.getline(str,80);
                        cout<<"\n\t\t\t\t\t"<<str;
                    }
                    cout<<setw(80)<<endl<<"!!!!----Press 'ENTER' to Continue----!!!!"<<endl;
                    _getch();
                }
				dashboardexit();
		}

		/**Function to Check Appointment****/

		void checkappointment()
		{
		    char input[80];
		    system("CLS");
		    header();
		    ifstream f;
		    f.open(id);
		    if(!f)
                cout<<"\n\n\t\t\t\tNo Appoinments"<<endl;
            else
            {
                cout<<endl<<"\t\t\t\t\t\t----YOUR APPOINMENTS----"<<endl<<endl;
		    while(!f.eof())
            {
                f.getline(input,80);
                cout<<"\t\t\t\t\t"<<input<<endl;
            }
            }
            f.close();
            _getch();
            dashboardexit();
		}

   /***Function Call Graph**/

   void functiontocallgraph(){
       int a[100],i=0,input;
        ifstream ifile;
        ifile.open(user_name);
        if(!ifile)
        {

            cout<<"\n\n\t\t\t\tNot enough data to process the graph , try again later!!";
            dashboard();
        }
        else{
        while(!ifile.eof())
        {
            ifile>>input;
            a[i]=input;
            i++;
        }
        }
        if(i>1)
        graph(a,i);
        else
        {
            cout<<"\n\n\t\t\t\tNot enough data to process the graph , try again later";
            _getch();
            dashboard();
        }
   }

   /***Points Calculator**/

    int point_calc()
    {
        system("CLS");
        header();

        int value = 0;
        float BMI , BF , weight , height , heart_rate , waist , hip , elbow ;
        int gender , age , work;
        cout<<"\n\n\t\t\t\t Enter your gender ( 1 for male , 0 for female ) : ";
        cin>>gender;
        cout<<"\t\t\t\t Enter weight ( in Kg )  : ";
        cin>>weight;
        cout<<"\t\t\t\t Enter height ( in m ) : ";
        cin>>height;
        cout<<"\t\t\t\t Enter your age : ";
        cin>>age;
        cout<<"\t\t\t\t Enter heart rate at rest ( in bpm ) : ";
        cin>>heart_rate;
        cout<<"\t\t\t\t Enter your waist size ( in cm ) : ";
        cin>>waist;
        cout<<"\t\t\t\t Enter hip size ( in cm ) : ";
        cin>>hip;
        cout<<"\t\t\t\t Enter elbow width ( in cm ) : ";
        cin>>elbow;

        BMI = weight/(height*height);
        BF = (1.39*BMI)+(0.16*age)-(10.34*gender)-9;
        if( BF < 0 )
            BF *= -1;
            cout<<"\n\n\t\t\t\t---------------RESULTS----------------";
        cout<<"\n\n\t\t\t\t Body Mass Index (BMI) : "<<BMI;
        cout<<"\n\t\t\t\t Waist to Hip ratio : "<<(waist/hip)*100<<"%";
        cout<<"\n\t\t\t\t Ideal Weight : ";
        (gender) ? cout << 22*(pow(height,2)) : cout << 22*pow(height,2);
        cout<<"\n\t\t\t\t Body Fat : "<<BF*weight/100<<"\t"<<BF<<"%";
        cout<<"\n\t\t\t\t Lean Mass : "<<weight - (BF*weight)/100;
        cout<<"\n\t\t\t\t Interpretation : ";

        points = BF;
        BF = (int)BF;
        if(gender)
        {
            if( BF >= 0 && BF <= 5)
               {
                    cout<<"Essential fat ";
                    value =300;
               }
            else if( BF >= 6 && BF <= 13)
                {
                    cout<<"Athelete";
                    value = 100;
               }
            else if( BF >= 14 && BF <= 17)
                {
                    cout<<"Fit ";
                    value = 170;
               }
            else if( BF >= 18 && BF <= 25)
                {
                    cout<<"Average";
                    value = 250;
               }
            else
                {
                    cout<<"Obese";
                    value = 420;
               }
        }
        else{
            if( BF <10)
                {
                    cout<<"N0 fat ";
                    value = 350;
               }
            else if( BF >= 10 && BF <= 13)
                {
                    cout<<"Essential fat ";
                    value = 300;
               }
            else if( BF >= 14 && BF <= 20)
                {
                    cout<<"Atheletes";
                    value = 100;
               }
            else if( BF >= 21 && BF <= 24)
                {
                    cout<<"Fit";
                    value = 150;
               }
            else if( BF >= 25 && BF <= 31)
                {
                    cout<<"Average";
                    value = 200;
               }
            else
                {
                    cout<<"Obese";
                    value = 400;
               }
        }

        cout<<setw(80)<<endl<<"!!!!----Press 'ENTER' to See your health statistics----!!!!"<<endl;
        _getch();
        points = value;
        ofstream fvalue;
        fvalue.open(user_name,ios::app);
        fvalue<<value<<endl;
        fvalue.close();
        ofstream fo;
        fo.open("userl.txt",ios::app);
        fo<<user_name<<endl;
        fo.close();
        ofstream fi;
        fi.open("pointsl.txt",ios::app);
        fi<<value<<endl;
        fi.close();
        int arr[20],i=0,input;
        ifstream ffvalue;
        ffvalue.open(user_name);
        while(!ffvalue.eof())
        {
            ffvalue>>input;
            arr[i]=input;
            i++;
        }
        if(i>1)
        graph(arr,i);
        else
           {
               cout<<"Insufficient data to process Graph"<<endl;
               dashboard();
           }
    }

   /***Function of Leader Board**/

   void leader_board()
   {
       system("CLS");
       header();
       int i=0,input,a[100],g1=0,g2=0,g3=0,index1=0,index2=0,index3=0;
       ifstream fo;
       fo.open("pointsl.txt");
       while(!fo.eof())
       {
           fo>>input;
           a[i]=input;
           i++;
       }
       cout<<"\n\t\t\t\t----Leader Board----"<<endl<<endl;
       cout<<"\t\t\t\t\----User_Name-----Points----"<<endl<<endl;
       fo.close();
       if(i==1)
       {
           for(int k=0;k<i;k++)
         {
           if(a[k]>g1)
           {
               g1=a[k];
               index1=k;
           }
         }
       }
       else if(i==2)
       {
           {
           for(int k=0;k<i;k++)
           {
               if(a[k]>g1)
             {
               g2=g1;
               g1=a[k];
               index1=k;
             }
           if(a[k]>g2 && a[k]!=g1)
           {
               g2=a[k];
               index2=k;
           }
           }
       }
       }
       else
       {
       for(int k=0;k<i;k++)
       {
           if(a[k]>g1)
           {
               g2=g1;
               g1=a[k];
               index1=k;
           }
           if(a[k]>g2 && a[k]!=g1)
           {
               g3=g2;
               g2=a[k];
               index2=k;
           }
           if(a[k]>g3 && a[k]!=g2)
           {
               g3=a[k];
               index2=k;
           }
        }
       }
        int k=0;
        char s[80];
        if(i>=1)
        {
            ifstream fi;
        fi.open("userl.txt");
        while(!fi.eof())
        {
            fi.getline(s,80);
            if(k==index1)
            {
                cout<<"\t\t\t\t"<<s<<"          "<<a[index1]<<endl;
                break;
            }
            k++;
        }
        fi.close();
        }
        k=0;
        if(i>=2)
        {
            ifstream fi;
        fi.open("userl.txt");
        while(!fi.eof())
        {
            fi.getline(s,80);
            if(k==index2)
            {
                cout<<"\t\t\t\t"<<s<<"         "<<a[index2]<<endl;
                break;
            }
            k++;
        }
        fi.close();
        }
        k=0;
        if(i>=3)
        {
            ifstream fi;
        fi.open("userl.txt");
        while(!fi.eof())
        {
            fi.getline(s,80);
            if(k==index3)
            {
                cout<<"\t\t\t\t"<<s<<"         "<<a[index3]<<endl;
                break;
            }
            k++;
        }
        fi.close();
        }
        else
            cout<<"\t\t\t\t\t"<<user_name<<" "<<"0"<<endl;
            cout<<setw(80)<<endl<<endl<<"!!!!----Press 'ENTER' to CONTINUE----!!!!"<<endl;
                    _getch();
                    dashboardexit();
   }


   /*** search or add any of the diseases ***/

    void search_disease()
    {
        system("CLS");
        header();

        int flag = 0, line_no = 0;
        char ename[20] , fname[20] , symptoms[80]  , precautions[80];
        ofstream fo , sfo , pfo;
        ifstream fi , sfi , pfi;
        fi.open("diseases.txt");
        sfi.open("symptoms.txt");
        pfi.open("precautions.txt");

        cout<<"\n\n\n\t\t\t\tEnter disease name to be searched : ";
        cin>>ename;

        while(!fi.eof())
        {
            fi >> fname ;
            if( strcmpi(fname,ename) == 0)
            {
                flag = 1;
                cout<<endl<<endl<<endl<<"\t\t\t\tPlease Wait!!!"<<endl;
                    cout<<"\t\t\t\tSearching";
			        for(int dl=1;dl<35;dl++)
                    {
                       delay(50);
                       cout<<"..!";
                    }
                cout<<setw(80)<<endl<<endl<<"!!!!----Press 'ENTER' to CONTINUE----!!!!"<<endl;
                    _getch();
                cout<<"\n\n\n\t\t\t\t\t-----Disease found!!-----";
                cout<<"\n\n\t\t\t\t-----Following are its symptoms-----\n\n";
                for(int i = 0 ; i<=line_no ; i++)
                {

                    for(int j = 1 ; j<=3 ; j++)
                    {
                        sfi.getline(symptoms,80);
                        if(i == line_no)
                        {
                            cout << "\t\t\t\t" << j << "." << symptoms << "\n" ;
                        }
                    }
                }
                sfi.close();
                cout<<"\n\n\t\t\t\t-----Following are its precautions-----\n\n";
                for(int i = 0 ; i<=line_no && !fi.eof() ; i++)
                {

                    for(int j = 1 ; j<=3 && !sfi.eof() ; j++)
                    {
                        pfi.getline(precautions,80);
                        if(i == line_no)
                        {
                            cout << "\t\t\t\t" << j << "." << precautions << "\n" ;
                        }
                    }

                }
                pfi.close();
                break;
            }
            line_no++;
        }
        if(!flag)
        {
            cout<<"\n\n\t\t\t\tOops ! Seems entered disease isn't in out list !!! ";
            if(doctor)
            {

                cout<<"\n\n\t\t\t\tWould you like to enter the disease and its symptoms ? (Y/N) : ";
                char ch = _getch();
                if(ch == 'y' || ch == 'Y')
                {
                    system("CLS");
                    header();
                    fo.open("diseases.txt", ios::app );
                    sfo.open("symptoms.txt", ios::app );
                    cout<<"\n\n\t\t\t\tEnter name of the disease : ";
                    cin>>ename;

                    fo << ename <<"\n";

                    cout<<"\n\n\t\t\t\tEnter its symptoms ( at least 3 ) : \n";
                    for(int i = 0 ; i<=3 ; i++)
                    {
                        if(i>0)
                        {
                        cout<<"\t\t\t\t" << i << ". ";
                        cin.getline(symptoms,80);
                        sfo << symptoms <<"\n" ;
                        }
                        else
                            cin.getline(symptoms,80);
                    }
                    cout<< setw(80) <<endl <<"!!!!-------Saved Successfully ------ !!!";
                }
            }
        }
        fi.close();
        sfi.close();
        sfo.close();
        fo.close();

        cout<<setw(80)<<endl<<"!!!!----Press 'ENTER' to CONTINUE----!!!!"<<endl;
        _getch();
        dashboardexit();
    }

    /******* Dashboard *********/

     void dashboard()
    {

        choice:

        system("CLS");
        header();
        cout<<endl<<endl;
        cout<<setw(45)<<"Username: "<<user_name<<endl;
        cout<<setw(50)<<"Registration/UID Number: "<<id<<endl;

        cout<<"\n\n\t\t\t\t---------DASHBOARD---------";
        cout<<"\n\n\t\t\t\t-----Select any option-----";
        cout<<"\n\n\t\t\t\t   1) Search Disease ";
        cout<<"\n\t\t\t\t   2) Check up ";
        cout<<"\n\t\t\t\t   3) Appointments ";
        cout<<"\n\t\t\t\t   4) Leader Board ";
        cout<<"\n\t\t\t\t   5) Health Statistics ";
        cout<<"\n\t\t\t\t   6) Logout ";
        cout<<"\n\t\t\t\t   7) Exit ";
        cout<<"\n\n\t\t\t\t   Enter your choice : ";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 1 : search_disease();
                     break;
            case 2 : point_calc();
                     break;
            case 3 : if(doctor==0)
                     bookappointment();
                     else
                     checkappointment();
                     break;
            case 4 ://print = 1;
                    leader_board();
                    //print = 0;
                     break;
            case 5 : functiontocallgraph();
                     break;
            case 6 :cout<<endl<<endl<<endl<<"\t\t\t\tPlease Wait!!!"<<endl;
                    cout<<"\t\t\t\tLoading";
			        for(int dl=1;dl<35;dl++)
                    {
                       delay(50);
                       cout<<"..!";
                    }
                    cout<<setw(80)<<endl<<endl<<"!!!!----Press 'ENTER' to CONTINUE----!!!!"<<endl;
                    _getch();
                    enter();
                    break;
            case 7 : exit(-1);
            default : cout<<"\n\t\t Invalid input , try again ! ";
                      _getch();
                      goto choice;
        }
    }
};
int main()
{
	health h;
	h.enter();
	return 0;


}
