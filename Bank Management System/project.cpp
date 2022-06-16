#include<iostream>

#include<conio.h>

#include<windows.h>

using namespace std;

class Bank{

	private: 

	    int total;

	    string id;

	    struct person{

	    	string name,ID,address;

	    	int contact,amount;

		}person[100];

	public:

		Bank(){

			total=0;

		}

		void options();

		void insert();

		void list();

		void update();

		void search();

		void transactions();

		void remove();

};

int main(){
	system("CLS");
	cout<<endl<<endl<<endl<<"    ========================================="<<endl<<"    WELCOME TO THE NEW BANK MANAGEMENT SYSTEM"<<endl<<"    ========================================="<<endl;
	Sleep(3000);
	system("CLS");
	Bank b;

	b.options();

	return 0;

}

void Bank::options(){

	char ch;

	while(1){

	cout<<"\n\nPRESS the required key..!!"<<endl<<endl;

	cout<<"1. Create new account"<<endl;

	cout<<"2. View customers list"<<endl;

	cout<<"3. Update information of existing account"<<endl;

	cout<<"4. Check the details of an existing account"<<endl;

	cout<<"5. For transactions"<<endl;

	cout<<"6. Remove existing account"<<endl;

	cout<<"7. Exit"<<endl;

	ch=getch();

	system("CLS");

	switch(ch){

		case '1':

			Bank:insert();
			
			break;

		case '2':

			if(total==0){

				cout<<"No data is present"<<endl;

			}else{

			Bank::list();

		   }

			break;

		case '3':

			if(total==0)

			cout<<"No data is present"<<endl;

			else

			Bank::update();

			break;

		case '4':

			if(total==0)

			cout<<"No data is present"<<endl;

			else

			Bank::search();

			break;

		case '5':

			if(total==0)

			cout<<"No data is present"<<endl;

			else

			Bank::transactions();

			break;

		case '6':

			if(total==0)

			cout<<"No data is present"<<endl;

			else

			Bank::remove();

			break;

		case '7':

			exit(0);

			break;

		default:

			cout<<"Invalid input"<<endl;

			break;

	}

    }

}

void Bank::insert(){

	string testID;
	
	cout<<"Enter data of person "<<total+1<<endl;

	cout<<"Enter name of account holder: ";

	cin>>person[total].name;

	cout<<"ID: ";
	
	cin>>testID;

	for(int i=0; i<total; i++){
		if(testID==person[i].ID){
			cout<<"ID not available !!"<<endl;
			//total--;
			getch();
			return;
		}
	}
	
	person[total].ID = testID;

	cout<<"Address: ";

	cin>>person[total].address;

	cout<<"Contact: ";

	cin>>person[total].contact;

	cout<<"Total Amount: ";

	cin>>person[total].amount;

	total++;

}

void Bank::list(){

	for(int i=0;i<total;i++){

		cout<<"Data of person "<<i+1<<endl;

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"ID: "<<person[i].ID<<endl;

		cout<<"Address: "<<person[i].address<<endl;

		cout<<"Contact: "<<person[i].contact<<endl;

		cout<<"Amount: "<<person[i].amount<<endl;
		
		cout<<endl<<endl;

	}

}

void Bank::update(){

	cout<<"Enter id of account holder to update the record"<<endl;

	cin>>id;

	for(int i=0;i<total;i++){

		if(id==person[i].ID){

		cout<<"------ Data Stored ------"<<endl;

		cout<<"Data of person "<<i+1<<endl;

		cout<<"Name: "<<person[i].name<<endl;

		cout<<"ID: "<<person[i].ID<<endl;

		cout<<"Address: "<<person[i].address<<endl;

		cout<<"Contact: "<<person[i].contact<<endl;

		cout<<"Amount: "<<person[i].amount<<endl;

		cout<<"\nEnter new data to update the record"<<endl;

		cout<<"Enter name: ";

	cin>>person[i].name;

	cout<<"ID: ";

	cin>>person[i].ID;

	cout<<"Address: ";

	cin>>person[i].address;

	cout<<"Contact: ";

	cin>>person[i].contact;

	cout<<"Total Amount: ";

	cin>>person[i].amount;

	break;

		}

		if(i==total-1){

			cout<<"No such record found"<<endl;

		}

	}

}

void Bank::search(){

cout<<"Enter id of account holder to search the record"<<endl;

cin>>id;

for(int i=0;i<total;i++){

	if(id==person[i].ID){

		cout<<"Name of the account holder: "<<person[i].name<<endl;

		cout<<"ID: "<<person[i].ID<<endl;

		cout<<"Address: "<<person[i].address<<endl;

		cout<<"Contact: "<<person[i].contact<<endl;

		cout<<"Amount: "<<person[i].amount<<endl;

		break;

	}

	if(i==total-1){

		cout<<"No such record found"<<endl;
		cout<<endl<<endl;

	}

}

}

void Bank::transactions(){

	int amount;

	char ch;

	cout<<"Enter id of account holder to proceed towards transaction"<<endl;

     cin>>id;

     for(int i=0;i<total;i++){

     	if(id==person[i].ID){

     		cout<<"Name: "<<person[i].name<<endl;

     	     cout<<"Address: "<<person[i].address<<endl;

		     cout<<"Contact: "<<person[i].contact<<endl;

		     cout<<"\nExisting Amount "<<person[i].amount<<endl;

		     cout<<"Press 1 to deposit"<<endl;

		     cout<<"Press 2 to withdraw"<<endl;

		     ch=getch();

		     switch(ch){

		     	case '1':

		     		cout<<"How much amount you want to deposit??"<<endl;

		     		cin>>amount;

		     		person[i].amount+=amount;

		     		cout<<"Your new amount is "<<person[i].amount<<endl;

		     		break;

		     	case '2':

		     		back:

		     		cout<<"How much amount you want to withdraw??"<<endl;

		     		cin>>amount;

		     		if(amount>person[i].amount){

		     			cout<<"Your existing amount is "<<person[i].amount<<endl;

		     			Sleep(3000);

		     			goto back;

					 }

					 person[i].amount-=amount;

					 cout<<"Your new amount is "<<person[i].amount<<endl;

					 break;

				default:

					cout<<"Invalid input"<<endl;

					break;

			 }

			 break;

		 }

		 if(i==total-1){

		 	cout<<"No such record found"<<endl;

		 }

	 }

}

void Bank::remove(){

	char ch;
	int flag = 0;
	cout<<"Press 1 to remove specific record"<<endl;

	cout<<"Press 2 to remove full record"<<endl;

	ch=getch();

	switch(ch){

		case '1':

	cout<<"Enter id of account holder to remove"<<endl;

     cin>>id;

   //  int flag = 0;

     for(int i=0;i<total;i++){

     	if(id==person[i].ID){

			flag = 1;

     		for(int j=i;j<total-1;j++){

     		person[j].name=person[j+1].name;

     		person[j].ID=person[j+1].ID;

     		person[j].address=person[j+1].address;

     		person[j].contact=person[j+1].contact;

     		person[j].amount=person[j+1].amount;


			 }
			 total--;
			 cout<<"Your required data is deleted"<<endl;
			 break;

		 }

		 if(i==total-1 && flag==0){

		cout<<"No such record found"<<endl;

		 }

	 }

	 break;

	 case '2':

	 	total=0;

	 	cout<<"All record is deleted"<<endl;

	 	break;

	default:

		cout<<"Invalid Input"<<endl;

		break;

	}

}