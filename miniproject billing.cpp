//supermarket billing system
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string>
 using namespace std;
  class shop
    
	 {
  	private:
  	  int procode;  //pcode=procode for product number 
  	  string proname; //for product name
  	  float price;   //for price of product
  	  float discount;  //for product discount 
  	  
  	    public:
  	    	void menu(); 
  	    	void add();
  	    	void manager(); //for the managing head to add remove edit the product in database 
  	    	void edit(); //for editing the product
  	    	void rem();// rem for removing product data
			void list();
			void buyer(); // for buyer section
			void receipt(); //for displaying content in bill 
     };
     // for function content function defination
	  void shop :: menu()
	  {
	  	m:
	  	 int choice; //for menu driven 
	  	 string email;//for loging purpose 
	  	 string password;
	  	 cout<"\t\t\t\t\t\t                                                        \n";
	  	 cout<"\t\t\t\t\t\t                                                        \n";
	  	 cout<"\t\t\t\t\t\t        APDP ShoppingCentre Main Menu                   \n";
	  	 cout<"\t\t\t\t\t\t                                                        \n";
	  	 cout<"\t\t\t\t\t\t                                                        \n";
	  	 cout<"\t\t\t\t\t\t |  1.Manager  | \n";
		 cout<"\t\t\t\t\t\t                                                      \n";    
		 cout<"\t\t\t\t\t\t |  2.Buyer    | \n";     
		 cout<"\t\t\t\t\t\t                                                      \n";    
		 
		 cout<"\t\t\t\t\t\t |  3.Exit    | \n";   
		 cout<"\t\t\t\t\t\t                                                      \n";   
		 cout<<"\n\t\t\t\t Please Select Your Choice!!";
		 cin>>choice;
		 
		  switch(choice)
		  {
		  	case 1:
		  		cout<<"\t\t\t\t Please login for verification \n";
		  		cout<<"Enter your Email : \n";
		  		cin>>email;
		  		cout<<"\t\t\t\t Enter Password :  \n";
		  		cin>>password;
		  		
		  		if( email =="apdpshoppingcentre@gmail.com" && password=="apdp123")
		  		  {
		  		  	manager();
		  		
				  }
				  else 
				  {
				  	cout<<"Access Denied :( ";
				  	
				  }
		          break;
	  	 
	  
	  case 2:
	  	{
	  		buyer();
	  	
		  }
		  case 3:
		  	{
		  		exit(0);
		  		
			  }
			   default :          
			   	 {
			   	 	cout<<"Please select valid options:";
					}
					
}
goto m; //for goingback to menu for choosing option
	}
	 void shop :: manager()
	 {
	 	m:
	 	int choice;
	 	cout<<"\n\t\t\t\t Manager/Administrator Menu";
	 	cout<<"\n\t\t\t   1.Add product";
	 	cout<<"\n\t\t\t\t              ";
	 	cout<<"\n\t\t\t\t 2. Modify The Product";
	 	cout<<"\n\t\t\t\t              ";
	 	cout<<"\n\t\t\t\t 3. Delete The Product";
	    cout<<"\n\t\t\t\t              ";
	    cout<<"\n\t\t\t\t 4. Back to Main menu";
	    cout<<"\n\t\t\t Please Enter your choice:";
	    cin>>choice;
	    
	    switch(choice)
	    {
	    	case 1:
	    		add();
	    		break;
	    	 
			case 2:
			   edit();
			   break;
			    
				 case 3: 
				 rem();
				 break;
				   
				     case 4: 
				     menu();
				     break;
				      
				      default:
				      	cout<<"Invalid choice!! \n please choose the valid one.";
				      }
				      goto m;
					 	
	    
		}
		
		void shop::buyer()
		 {
		 	m:
		 	int choice;
		 	cout<<"\n\t\t\t| Buyer |\n";
		 	cout<<"__________________________\n";
		 	cout<<"                          \n";
		 	cout<<"\n\t\t\t| 1.Buy Product | \n";
		 	cout<<"                          \n";
		 	cout<<"\n\t\t\t| 2.Go Back | \n";
		 	cout<<"\t\t\t Enter Your choice!!\n";
		 	cin>>choice;
		 	 
		 	 switch(choice)
		 	 {
		 	 	case 1 :
		 	 		receipt();
		 	 		break;
		 	 		case 2:
		 	 			menu();
		 	 			break;
		 	 			default:
		 	 				cout<<"Please Enter valid choice";
		 	 				
		 	 			
			  }
			  goto m;
		 	
		 }
		 void shop ::add()
		 {
		 	m:
		 	fstream data;
		 	int c;
		 	float p;
		 	float d;
		 	string n;
		 	int token=0;
		 	
		 	 cout<<"\n\n\t\t\t Add New Product";
		 	  cout<<"\n\n\t\t Please enter Product code ";
		 	  cin>>procode;
		 	  cout<<"\n\n\t\tPlease Enter the Name of the product";
		 	  cin>>proname;
		 	  cout<<"\n\n\n\t\tPlease Enter the Price of the Product Added";
		 	  cin>>price;
		 	  cout<<"\n\n\t\tPlease Enter the Discount included";
			  cin>>discount;
			   // opeaning a file to show data
			   data.open("database.txt",ios::in);  // open file in reading mode 
			   if(!data) //if file does not exit
			   {
			   	data.open("database.txt",ios::app|ios ::out); //close the file
			   	data<<" "<<procode<<" "<<proname<<"  "<<price<< " "<<discount<<"\n";
			   	data.close();
			   }
			   else //if file exists
			   {
			   	data>>c>>n>>p>>d;
			   	while(!data.eof())
			   	{
			   		if(c==procode)
			   		{
			   			token++;
					   }
					   data>>c>>n>>p>>d;
				   }
				   data.close();
				   
			   
			   
			   if(token==1) //if product code entered is duplicated he need to go back to the menu
			     goto m;			
			    //if their is new product code entered 
			   else{
			   	data.open("database.txt",ios::app|ios ::out);
			   	data<<" "<<procode<<" "<<proname<<"  "<<price<< " "<<discount<<"\n";
			   	data.close();
			   	
			   }
		}
			   cout<<"\n\n\t\t\t Congratulations Record Inserted !!";
			   		 	  
		 	 
		 	
		 }
		 void shop ::edit() //for editing the inserted records
		 {
		 	fstream data,data1;
		 	int pkey;
		 	int token=0;
		 	int c;
		 	float p;
		 	float d;
		    string n;
		    cout<<"\n\t\t Modify The Record:";
		    cout<<"\n\t\t Enter Product Code:";
		    cin>>pkey;
		    data.open("database.txt",ios::in);
		    if(!data)
		    {
		    	cout<<"\n\n File Doesn't Exist!!";
		    	
			}
			else{
				data1.open("database1.txt",ios::app|ios::out);  //we'll save neu name and read and write in it
				data>>procode>>proname>>price>>discount;
				while(!data.eof()) //eof=end of file ,it will check up to end of file
				{
					if(pkey==procode)
					{
						cout<<"\n\t\t Enter The Product New code:";
						cin>>c;
						cout<<"Please enter Name of the product";
						cin>>n;
						cout<<"\n\t\t Enter Price of the Product:";
						cin>>p;
						cout<<"\n\t\t Enter The discount to be given to the Product: ";
						cin>>d;
						data1<<"  "<<c<<"  "<<n<<"  "<<p<< "  "<<d<< "\n";
						cout<<"\n\n\t\t OK! Record Edited!";
						token++;
						
					}
					else 
					{
						data<<" "<<procode<<" "<<proname<<" "<<price<<" "<<discount<<"\n";
					}
					data>>procode>>proname>>price>>discount;
					
				} 
				data.close();
				data1.close();
				remove("database.text");
				rename("database1.txt","database.txt");
				if(token==0)
				{
					cout<<"\n\n\t  Opps,Record not found!!";
					
				}
				
			}
		    
		 }
		 void shop ::rem()
		 {
		 	fstream data,data1;
		 	int pkey;
		 	int token=0;
		 	cout<<"\n\n\t\t Delete The Product";
		 	cout<<"Please Enter the product code of The producy You Want to delete:";
		 	cin>>pkey;
		 	data.open("database.txt",ios::in); //in reading mode
		 	if(!data)
		 	{
		 		cout<<"File Doesn't Exist!";
		 		
			 }
			 else {
			 	data1.open("database.txt",ios::app|ios::out);
			 	data>>procode>>proname>>price>>discount;
			 	while(data.eof())
			 	{
			 		if(procode==pkey)
			 		{
			 			cout<<"\n\n\t\t Product Deleted ";
			 			token++;
			 			
					 }
					 // all the product will be displayed except the one that is deleted
					 else {
					 	data1<<" "<<procode<<" "<<proname<<" "<<price<<" "<<discount<<" \n";
					 	
					 }
					 data>>procode>>proname>>price>>discount;
					 
				 }
				 data.close();
				 data1.close();
				 remove("database.txt");
				 rename("database1.txt","database.txt");
				 if (token==0)
			      {
				 	cout<<"\n\n Record Not found !!";
				 	
			         }	
			  }
		 }
		 void shop :: list()
		 {
		 	fstream data;
		 	data.open("database.txt",ios::in);
			cout<<"\n\n|________________________________________\n";
			cout<<"Product Number \t\r Name\t\t Price";
			cout<<"\n\n|________________________________________\n";
			data>>procode>>proname>>price>>discount;
			while(!data.eof())
			{
				cout<<procode<<"\t\t"<<proname<<"\t\t"<<price<<"\t\t"<<discount<<"\n";
				data>>procode>>proname>>price>>discount;
				
			}
			data.close();
		}
		void shop :: receipt()
		{
			fstream data;
			int arrc[150];   //array of codes
			int arrq[150];
			char choice;
			int c=0;
			float amount=0;
			float dis=0;
			float total=0;
			cout<<"BILL INVOICE:";
			data.open("database.txt",ios::in);
			if(!data)
			{
				cout<<"\n\n\t\t database is Empty!";
				
			}
			else{
				data.close();
				list();
				cout<<"\n|_________________________________\n";
				cout<<"\n|_________________________________\n";
				cout<<"\n|     PLEASE PLACE THE ORDER      \n";
				cout<<"\n|_________________________________\n";
				cout<<"\n|_________________________________\n";
				do 
				{
					m:
					cout<<"\n\nEnter The product Code:";
					cin>>arrc[c];
					cout<<"Please enter the product quantity:";
					cin>>arrq[c];
					for(int i=0;i<c;i++)
					{
						if(arrc[c]==arrc[i])
						{
							cout<<"\n\n\t Duplicate product code!!";
							goto m;
						}
					}
					c++;
					cout<<"\n\n Do you want to buy another product? if yes please press y else n";
					cin>>choice;
				}
				while(choice =="y");
				cout<<"\n\n\t\t\t_______________________RECEIPT_____________________\n";
				cout<<"\n\t Product Number \t Product Name \t Price\t total amount with discount\n";
				for(int i=0;i<c;i++)
				{
					data.open("database.txt",ios::in);
					data>>procode>>proname>>price>>discount;
					while(!data.eof())
					{
						if(procode==arc[i])
						{
							amount=price*arrq[i];
							discount=amount-(amount*discount/100);
							total=total=discount;
							cout<<"\n\t"<<procode"\t\t"<<proname"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount;
						}
						data>>procode>>proname>>price>.discount;
						
					}
					
				}
				data.close();
				
					}
					cout"\n\n\t_____________________________________________";
					cout<<"\n\n TOTAL AMOUNT "<<total;
			}
			int main()
			{
				shop s;
				s.menu();
				
			}
	
		
			
	
  
