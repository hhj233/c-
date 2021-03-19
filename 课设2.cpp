#include <iostream>
#include <fstream> 
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
void color(short x){
	if(x>=0&&x<=15)	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
	else{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
}
void HideCursor()     //���ع��
{
 CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void toxy(int x,int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void menu();
void over();
void revoke_message_choice();//ѡ�񳷻������о������� 
void find_message_choice();//ѡ���ѯ�����о������� 
void input_message_choice();//ѡ�����������о�����Ϣ���� 
void amend_message_choice();//ѡ���޸������о�����Ϣ���� 
void delete_message_choice();//ѡ��ɾ�������о�����Ϣ���� 
void statistics_message_choice();//ѡ����������о�����Ϣ���� 
void input_academic_message();//����ѧ���о�����Ϣ���� 
void input_engineer_message();//���빤���о�����Ϣ���� 
void amend_academic_message();//�޸�ѧ���о�����Ϣ���� 
void amend_engineer_message();//�޸Ĺ����о�����Ϣ���� 
void delete_academic_message();//ɾ��ѧ���о�����Ϣ���� 
void delete_engineer_message();//ɾ�������о�����Ϣ���� 
void statistics_academic_message();//����ѧ���о�����Ϣ���� 
void statistics_engineer_message();//���������о�����Ϣ���� 
void find_academic_message();//��ѯѧ���о�����Ϣ���� 
void find_engineer_message();//��ѯ�����о�����Ϣ���� 
class master{
	public:
		void set_name(string name){
			this->name=name;
		}
		void set_num(int num){
			this->num=num;
		}
		void set_sex(string sex){
			this->sex=sex;
		}
		void set_age(int age){
			this->age=age;
		}
		void set_score(float score){
			this->score=score;
		}
		string get_name(){
			return(this->name);
		}
		int get_num(){
			return(this->num);
		}
		string get_sex(){
			return(this->sex);
		}
		int get_age(){
			return(this->age);
		}
		float get_score(){
			return(this->score);
		}
	private:
		int num;
		string name;
		string sex;
		int age;
		float score;
}; 
class academic_master:public master{
	public:
		int j;
		academic_master *next;
		void set_major(string major){
			this->major=major;
		}
		void set_dissertation_name(string name,int a){
			this->dissertation_name[a-1]=name;
		}
		void set_dissertation_rank(int rank,int a){
			this->dissertation_rank[a-1]=rank;
		}
		void set_dissertation_num(int num){
			this->dissertation_num=num;
		}
		void set_dissertation_score(float score){
			this->dissertation_score=score;
		}
		void set_academicsum_score(float score){
			this->academicsum_score=score;
		}
		string get_major(){
			return(this->major);
		}
		string* get_dissertation_name(){
			return(this->dissertation_name);
		}
		int* get_dissertation_rank(){
			return(this->dissertation_rank);
		}
		int get_dissertation_num(){
			return(this->dissertation_num);
		}
		float get_dissertation_score(){
			return(this->dissertation_score);
		}
		float get_academicsum_score(){
			return(this->academicsum_score);
		}
	private:
		string major;
		string dissertation_name[3];
		int dissertation_rank[3];
		int dissertation_num;
		float dissertation_score;
		float academicsum_score;
			
};
class engineer_master:public master{
	public:
		engineer_master *next;
		string get_field(){
			return(this->field);
		}
		string get_project_name(){
			return(this->project_name);
		}
		char get_project_rank(){
			return(this->project_rank);
		}
		float get_project_score(){
			return(this->project_score);
		}
		float get_emgineersum_score(){
			return(this->engineersum_score);
		}
		void set_field(string field){
			this->field=field;
		}
		void set_project_name(string name){
			this->project_name=name;
		}
		void set_project_rank(char rank){
			this->project_rank=rank;
		}
		void set_project_score(float score){
			this->project_score=score;
		}
		void set_engineersum_score(float score){
			this->engineersum_score=score;
		}
	private:
		string field;
		string project_name;
		char project_rank;
		float project_score;
		float engineersum_score;
};
academic_master *academic_ptr_head=NULL;
academic_master *academic_ptr=NULL;
engineer_master *engineer_ptr=NULL;
engineer_master *engineer_ptr_head=NULL;
academic_master* read_academic_message();//����ѧ���о�����Ϣ�����ͷ�ڵ㺯�� 
engineer_master* read_engineer_message();//���ع����о�����Ϣ�����ͷ�ڵ㺯�� 
void academic_creatFile(academic_master *p);//����ѧ���о�����Ϣ�ļ����� 
void engineer_creatFile(engineer_master *p);//���������о�����Ϣ�ļ����� 
void input_academic_message(){
	academic_master *head=NULL;
	academic_master *last=NULL;
	academic_master *head1=NULL;
	while(1){
		system("cls");
		char t;
		academic_master *p;
		p=new academic_master();
		int num;
		int a;
		string name;
		string sex;
		int age;
		float score;
		string major;
		string dissertation_name;
		int dissertation_rank;
		int dissertation_num;
		toxy(24,1);
		cout<<"������ѧ���о���������:";
		cin>>name;
		p->set_name(name);
		toxy(24,3);
		cout<<"������ѧ���о�����ѧ��:";
		cin>>num;
		p->set_num(num);
		toxy(24,5);
		cout<<"������ѧ���о������Ա�:";
		cin>>sex;
		p->set_sex(sex);
		toxy(24,7);
		cout<<"������ѧ���о���������:";
		cin>>age;
		p->set_age(age);
		toxy(24,9);
		cout<<"������ѧ���о����Ŀγ̳ɼ�:"; 
		cin>>score;
		p->set_score(score);
		toxy(24,11);
		cout<<"������ѧ���о�����רҵ:";
		cin>>major;
		p->set_major(major);
		toxy(24,13);
		cout<<"������ѧ���о�������������:";
		cin>>dissertation_num;
		p->set_dissertation_num(dissertation_num);
		toxy(24,15);
		cout<<"������ѧ���о����ĵڼ�ƪ���ĺ���������:";
		cin>>a>>dissertation_name; 
		p->set_dissertation_name(dissertation_name,a);
		toxy(24,16);
		cout<<"������ѧ���о����ĵڼ�ƪ���ĺ���������:";
		cin>>a>>dissertation_name;
		p->set_dissertation_name(dissertation_name,a);
		toxy(24,17);
		cout<<"������ѧ���о����ĵڼ�ƪ���ĺ���������:";
		cin>>a>>dissertation_name;
		p->set_dissertation_name(dissertation_name,a);
		toxy(24,19);
		cout<<"������ѧ���о����ĵڼ�ƪ���ĺ����ĵȼ�:";
		cin>>a>>dissertation_rank;
		p->set_dissertation_rank(dissertation_rank,a);
		toxy(24,20);
		cout<<"������ѧ���о����ĵڼ�ƪ���ĺ����ĵȼ�:";
		cin>>a>>dissertation_rank;
		p->set_dissertation_rank(dissertation_rank,a);
		toxy(24,21);
		cout<<"������ѧ���о����ĵڼ�ƪ���ĺ����ĵȼ�:";
		cin>>a>>dissertation_rank;
		p->set_dissertation_rank(dissertation_rank,a);
		if(head==NULL){
			head=p;
			last=head;
		}
		else{
			last->next=p;
			last=last->next;
		}
		while(1){
			system("cls");
			head1=read_academic_message();
			if(head1!=NULL){
				last->next=head1;
			}
			toxy(24,10);
			cout<<"�Ƿ����... 1��ʾ����/2��ʾ�˳�"; 
			t=getch();
			if(t=='1'){
				break;
			}
			if(t=='2'){
				academic_creatFile(head);
				menu();
			}
		}
	}
}
void academic_creatFile(academic_master *p){
	ofstream outfile("D:\\java2\\ѧ���о����ɼ�.txt",ios::out);
	if(!outfile){
		cerr<<"�ļ���ʧ�ܣ�"<<endl;
		exit(1);
	}
	outfile<<"����"<<"\t"<<"ѧ��"<<"\t"<<"�Ա�"<<"\t"<<"����"<<"\t"<<"�ɼ�"<<"\t"
			<<"רҵ"<<"\t"<<"��������"<<"\t"<<"��������1"<<"\t"<<"��������2"<<"\t"
			<<"��������3"<<"\t"<<"���ĵȼ�1"<<"\t"<<"���ĵȼ�2"<<"���ĵȼ�3"<<endl; 
	while(p!=NULL){
		outfile<<p->get_name()<<"\t"<<p->get_num()<<"\t"<<p->get_sex()<<"\t"
		<<p->get_age()<<"\t"<<p->get_score()<<"\t"<<p->get_major()<<"\t"
		<<p->get_dissertation_num()<<"\t"<<p->get_dissertation_name()[0]<<"\t"
		<<p->get_dissertation_name()[1]<<"\t"<<p->get_dissertation_name()[2]<<"\t"
		<<p->get_dissertation_rank()[0]<<"\t"<<p->get_dissertation_rank()[1]<<"\t"
		<<p->get_dissertation_rank()[2];
		if(p->next!=NULL){
			outfile<<endl;
		}
		p=p->next; 
	}
	outfile.close();
}
academic_master *read_academic_message(){
	ifstream infile("D:\\java2\\ѧ���о����ɼ�.txt",ios::in);
	academic_master *head=NULL;
	academic_master *last=NULL;
	int num;
	int a;
	string name;
	string sex;
	int age;
	float score;
	string major;
	string dissertation_name[3];
	int dissertation_rank[3];
	int dissertation_num;
	if(!infile){
		cerr<<"�ļ���ʧ�ܣ�";
		exit(1);
	}
	string temp;
	getline(infile,temp);
	while(!infile.eof()){
		academic_master *p=new academic_master();
		infile>>name>>num>>sex>>age>>score>>major>>dissertation_num>>dissertation_name[0]
		>>dissertation_name[1]>>dissertation_name[2]>>dissertation_rank[0]
		>>dissertation_rank[1]>>dissertation_rank[2];
		p->set_name(name);
		p->set_num(num);
		p->set_sex(sex);
		p->set_age(age);
		p->set_score(score);
		p->set_major(major);
		p->set_dissertation_num(dissertation_num);
		p->set_dissertation_name(dissertation_name[0],1);
		p->set_dissertation_name(dissertation_name[1],2);
		p->set_dissertation_name(dissertation_name[2],3);
		p->set_dissertation_rank(dissertation_rank[0],1);
		p->set_dissertation_rank(dissertation_rank[1],2);
		p->set_dissertation_rank(dissertation_rank[2],3);
		if(head==NULL){
			head=p;
			last=head;
		}
		else{
			last->next=p;
			last=last->next;
		}
	}
	infile.close();
	return(head);
}
void input_engineer_message(){
	engineer_master *head=NULL;
	engineer_master *last=NULL;
	engineer_master *head1=NULL;
	while(1){
		char t;
		system("cls");
		engineer_master *p;
		p=new engineer_master();
		p->next=NULL;
		int num;
		int a;
		string name;
		string sex;
		int age;
		float score;
		string field;
		string project_name;
		char project_rank;
		toxy(24,1);
		cout<<"�����빤���о���������:";
		cin>>name;
		p->set_name(name);
		toxy(24,3);
		cout<<"�����빤���о�����ѧ��:";
		cin>>num;
		p->set_num(num);
		toxy(24,5);
		cout<<"�����빤���о������Ա�:";
		cin>>sex;
		p->set_sex(sex);
		toxy(24,7);
		cout<<"�����빤���о���������:";
		cin>>age;
		p->set_age(age);
		toxy(24,9);
		cout<<"�����빤���о����Ŀγ̳ɼ�:"; 
		cin>>score;
		p->set_score(score);
		toxy(24,11);
		cout<<"�����빤���о������о�����:";
		cin>>field;
		p->set_field(field);
		toxy(24,13);
		cout<<"�����빤���о�������Ŀ����:";
		cin>>project_name;
		p->set_project_name(project_name);
		toxy(24,15);
		cout<<"�����빤���о�������Ŀ�ȼ�:";
		cin>>project_rank; 
		p->set_project_rank(project_rank);
		if(head==NULL){
			head=p;
			last=head;
		}
		else{
			last->next=p;
			last=last->next;
		}
		while(1){
			system("cls");
			head1=read_engineer_message();
			if(head1!=NULL){
				last->next=head1;
			}
			toxy(24,10);
			cout<<"�Ƿ����....1��ʾ����/2��ʾ�˳�"; 
			t=getch();
			if(t=='1'){
				break;
			}
			if(t=='2'){
				engineer_creatFile(head);
				menu();
			}
		}
	}
}
void engineer_creatFile(engineer_master *p){
	ofstream outfile("D:\\java2\\�����о����ɼ�.txt",ios::out);
	if(!outfile){
		cerr<<"�ļ���ʧ�ܣ�"<<endl;
		exit(1);
	}
	outfile<<"����"<<"\t"<<"ѧ��"<<"\t"<<"�Ա�"<<"\t"<<"����"<<"\t"<<"�γ̳ɼ�"<<"\t"
			<<"�о�����"<<"\t"<<"��Ŀ����"<<"\t"<<"��Ŀ�ȼ�"<<endl; 
	while(p!=NULL){
		outfile<<p->get_name()<<"\t"<<p->get_num()<<"\t"<<p->get_sex()<<"\t"
		<<p->get_age()<<"\t"<<p->get_score()<<"\t"<<p->get_field()<<"\t"
		<<p->get_project_name()<<"\t"<<p->get_project_rank();
		if(p->next!=NULL){
			outfile<<endl;
		}
		p=p->next;
	}
	outfile.close();
}
engineer_master *read_engineer_message(){
	ifstream infile("D:\\java2\\�����о����ɼ�.txt",ios::in);
	engineer_master *head=NULL;
	engineer_master *last=NULL;
	int num;
		int a;
		string name;
		string sex;
		int age;
		float score;
		string field;
		string project_name;
		char project_rank;
	if(!infile){
		cerr<<"�ļ���ʧ�ܣ�"<<endl;
		exit(1);
	}
	string temp;
	getline(infile,temp);
	while(!infile.eof()){
		engineer_master *p=new engineer_master();
		infile>>name>>num>>sex>>age>>score>>field>>project_name>>project_rank;
		p->set_name(name);
		p->set_num(num);
		p->set_sex(sex);
		p->set_age(age);
		p->set_score(score);
		p->set_field(field);
		p->set_project_name(project_name);
		p->set_project_rank(project_rank); 
		if(head==NULL){
			head=p;
			last=head;
		}
		else{
			last->next=p;
			last=last->next;
		}
	}
	infile.close();
	return(head);
}
void revoke_academic_message(){
	academic_master *head=NULL;
	academic_master *p=NULL;
	system("cls");
	color(5);
	p=academic_ptr_head;
	while(p!=NULL){
		cout<<p->get_name();
		p=p->next;
	}
	cout<<"�Ƿ���ɾ����y/n";
	char t;
	while(1){
		t=getch();
		if(t=='y'){
			head=read_academic_message();
			p=head;
			while(p!=NULL){
				if(p->next==NULL){
					p->next=academic_ptr_head;
					break;
				}
				p=p->next;
			}
			academic_creatFile(head);
			menu();
		}
		else if(t=='n'){
			menu();
		}
	}
}
void revoke_engineer_message(){
	engineer_master *head=NULL;
	engineer_master *p=NULL;
	system("cls");
	color(5);
	char t;
	cout<<"�Ƿ���ɾ����y/n";
	while(1){
		t=getch();
		if(t=='y'){
			head=read_engineer_message();
			p=head;
			while(p!=NULL){
				if(p->next==NULL){
					p->next=engineer_ptr_head;
					break;
				}
				p=p->next;
			}
			engineer_creatFile(head);
			menu();
		}
		else if(t=='n'){
			menu();
		}
	}
}
void amend_academic_message(){
	char t;
	string name;
	academic_master *head=NULL;
	academic_master *p=NULL; 
	int num;
	int a=0;
	string name1;
	string sex;
	int age;
	float score;
	string major;
	string dissertation_name[3];
	int dissertation_rank[3];
	int dissertation_num;
	while(1){
		system("cls");
		cout<<"������Ҫ�޸ĵ�ѧ���о�������:";
		cin>>name;
		head=read_academic_message();
		p=head;
		while(p!=NULL){
			if((p!=NULL)&&(p->get_name()==name)){
				a++;
				system("cls");
				toxy(24,2);
				cout<<"---------------------------";
				toxy(24,3);
				cout<<"|  ���о�����ȫ����ϢΪ:   "<<endl;
				toxy(24,5);
				cout<<"|��     ��:"<<p->get_name();
				toxy(24,7);
				cout<<"|ѧ     ��:"<<p->get_num();
				toxy(24,9);
				cout<<"|��     ��:"<<p->get_sex();
				toxy(24,11); 
				cout<<"|��     ��:"<<p->get_age();
				toxy(24,13);
				cout<<"|�γ� �ɼ�:"<<p->get_score();
				toxy(24,15);
				cout<<"|���� ����:"<<p->get_dissertation_num();
				toxy(24,17);
				cout<<"|����1����:"<<p->get_dissertation_name()[0];
				toxy(24,19);		
				cout<<"|����2����:"<<p->get_dissertation_name()[1];
				toxy(24,21);
				cout<<"|����3����:"<<p->get_dissertation_name()[2];
				toxy(24,23);
				cout<<"|����1�ȼ�:"<<p->get_dissertation_rank()[0];
				toxy(24,25);
				cout<<"|����2�ȼ�:"<<p->get_dissertation_rank()[1];
				toxy(24,27);
				cout<<"|����3�ȼ�:"<<p->get_dissertation_rank()[2]; 
				toxy(24,28);
				cout<<"---------------------------";
				toxy(55,2);
				cout<<"--------------------------" ;
				toxy(55,3);
				cout<<"|  ������Ҫ�޸ĵ���Ϣ   |"; 
				toxy(55,5);
				cout<<"|   1.��    ��          |";
				toxy(55,7);
				cout<<"|   2.ѧ    ��          |";
				toxy(55,9);
				cout<<"|   3.��    ��          |";
				toxy(55,11);
				cout<<"|   4.��    ��          |";
				toxy(55,13);
				cout<<"|   5.��������          |";
				toxy(55,15);
				cout<<"|   6.��������          |";
				toxy(55,17);
				cout<<"|   7.���ĵȼ�          |";
				toxy(55,19);
				cout<<"|   8.�γ̳ɼ�          |";
				toxy(55,20);
				cout<<"-------------------------"; 
				char t;
				while(1){
					t=getch();
					if(t=='1'){
						system("cls");
						toxy(24,5);
						cout<<"�������޸ĵ�����:";
						cin>>name1;
						p->set_name(name1);
						Sleep(500); 
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   �޸ĳɹ�   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='2'){ 
						system("cls");
						toxy(24,5);
						cout<<"�������޸ĵ�ѧ��:";
						cin>>num;
						p->set_num(num);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   �޸ĳɹ�   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='3'){
						system("cls");
						toxy(24,5);
						cout<<"�������޸ĵ��Ա�:";
						cin>>sex;
						p->set_sex(sex);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   �޸ĳɹ�   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='4'){
						system("cls");
						toxy(24,5);
						cout<<"�������޸ĵ�����:";
						cin>>age;
						p->set_age(age);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   �޸ĳɹ�   |";
						cout<<(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='5'){
						system("cls");
						toxy(24,5);
						cout<<"�������޸ĵ���������:";
						cin>>dissertation_num;
						p->set_dissertation_num(dissertation_num);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   �޸ĳɹ�   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='6'){
						system("cls");
						char ch;
						toxy(24,4);
						cout<<"-------------------------"; 
						toxy(24,5);
						cout<<"| �������޸ĵڼ�ƪ����: |";
						toxy(24,7);
						cout<<"|  1.��һƪ  2.�ڶ�ƪ   |";
						toxy(24,8);
						cout<<"|  3.����ƪ             |";
						toxy(24,9);
						cout<<"-------------------------";
						while(1){
							ch=getch();
							system("cls");
							color(6);
							if(ch=='1'){
								system("cls");
								toxy(24,5);
								cout<<"�������޸�����1������:";
								cin>>dissertation_name[0];
								p->set_dissertation_name(dissertation_name[0],1);
								break;
							}
							else if(ch=='2'){
								system("cls");
								toxy(24,5);
								cout<<"�������޸�����2������:";
								cin>>dissertation_name[1];
								p->set_dissertation_name(dissertation_name[1],2);
								break;
							}
							else if(ch=='3'){
								system("cls");
								toxy(24,5);
								cout<<"�������޸�����3������:";
								cin>>dissertation_name[2];
								p->set_dissertation_name(dissertation_name[2],3);
								break;
							}
						}
						
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   �޸ĳɹ�   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='7'){
						system("cls");
						char ch;
						toxy(24,4);
						cout<<"-------------------------"; 
						toxy(24,5);
						cout<<"| �������޸ĵڼ�ƪ����: |";
						toxy(24,7);
						cout<<"|  1.��һƪ  2.�ڶ�ƪ   |";
						toxy(24,8);
						cout<<"|  3.����ƪ             |";
						toxy(24,9);
						cout<<"-------------------------";
						while(1){
							color(6);
							ch=getch();
							if(ch=='1'){
								system("cls");
								toxy(24,5);
								cout<<"�������޸ĵ�����1�ĵȼ�:";
								cin>>dissertation_rank[0];
								p->set_dissertation_rank(dissertation_rank[0],1);
								break;
							}
							else if(ch=='2'){
								system("cls");
								toxy(24,5);
								cout<<"�������޸ĵ�����2�ĵȼ�:";
								cin>>dissertation_rank[1];
								p->set_dissertation_rank(dissertation_rank[1],2);
								break;
							}
							else if(ch=='3'){
								system("cls");
								toxy(24,5);
								cout<<"�������޸ĵ�����3�ĵȼ�:";
								cin>>dissertation_rank[2];
								p->set_dissertation_rank(dissertation_rank[2],3);
								break;
							}
						}
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   �޸ĳɹ�   |";
						toxy(48,16);
						cout<<"----------------";
						break;
					}
					else if(t=='8'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о����Ŀγ̳ɼ�:";
						cin>>score;
						p->set_score(score);
						break;
					}
				}
				academic_creatFile(head);
				break;
			}
			p=p->next;	
		}
		if(a==0){
			cout<<"ϵͳ��û������ˣ�";
			cout<<"��1����...";
			char e;
			e=getch();
		}
		Sleep(1000);
		system("cls");
		toxy(48,12);
		cout<<"----------------";
		toxy(48,14);
		cout<<"|   �Ƿ������ |";
		toxy(48,16);
		cout<<"|  1.��   2.�� |";
		toxy(48,18); 
		cout<<"----------------";
		while(1){
			t=getch();
			if(t=='1'){
				break;
			}
			else if(t=='2'){
				menu();
			}
		}
	}
}
void amend_engineer_message(){
	engineer_master *head;
	engineer_master *p;
	string name;
	int num;
		int a=0;
		string name1;
		string sex;
		int age;
		float score;
		string field;
		string project_name;
		char project_rank;
	char t;
	while(1){
		head=read_engineer_message();
		p=head;
		system("cls");
		cout<<"�������޸ĵĹ���˶ʿ����:";
		cin>>name;
		while((p!=NULL)&&(p->next!=NULL)){
			if((p!=NULL)&&(p->get_name()==name)){
				a++;
				system("cls");
				cout<<"���о�����ȫ����ϢΪ:"<<endl;
				cout<<"����:"<<p->get_name()<<endl;
				cout<<"ѧ��:"<<p->get_num()<<endl;
				cout<<"�Ա�:"<<p->get_sex()<<endl;
				cout<<"����:"<<p->get_age()<<endl;
				cout<<"�γ̷���"<<p->get_score()<<endl;
				cout<<"�о�����:"<<p->get_field()<<endl;
				cout<<"�о���Ŀ����:"<<p->get_project_name()<<endl;
				cout<<"�о���Ŀ�ȼ�:"<<p->get_project_rank()<<endl;
				toxy(55,2);
				cout<<"-------------------------" ;
				toxy(55,3);
				cout<<"|  ������Ҫ�޸ĵ���Ϣ   |"; 
				toxy(55,5);
				cout<<"|   1.��    ��          |";
				toxy(55,7);
				cout<<"|   2.ѧ    ��          |";
				toxy(55,9);
				cout<<"|   3.��    ��          |";
				toxy(55,11);
				cout<<"|   4.��    ��          |";
				toxy(55,13);
				cout<<"|   5.�о�����          |";
				toxy(55,15);
				cout<<"|   6.��Ŀ����          |";
				toxy(55,17);
				cout<<"|   7.��Ŀ�ȼ�          |";
				toxy(55,19);
				cout<<"|   8.�γ̳ɼ�          |"; 
				toxy(55,20);
				cout<<"-------------------------";
				while(1){
					t=getch();
					if(t=='1'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о���������:";
						cin>>name1;
						p->set_name(name1);
						break;
					}
					else if(t=='2'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о�����ѧ��:";
						cin>>num;
						p->set_num(num);
						break;
					}
					else if(t=='3'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о������Ա�:";
						cin>>sex;
						p->set_sex(sex);
						break;
					}
					else if(t=='4'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о���������:";
						cin>>age;
						p->set_age(age);
						break;
					}
					else if(t=='5'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о������о�����:";
						cin>>field;
						p->set_field(field);
						break;
					}
					else if(t=='6'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о�������Ŀ����:";
						cin>>project_name;
						p->set_project_name(project_name);
						break;
					}
					else if(t=='7'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о�������Ŀ�ȼ�:";
						cin>>project_rank;
						p->set_project_rank(project_rank);
						break;
					}
					else if(t=='8'){
						system("cls");
						toxy(24,5);
						cout<<"������Ҫ�޸��о����Ŀγ̳ɼ�:";
						cin>>score;
						p->set_score(score);
						break;
					}
				}
			}
			p=p->next;
		}
		engineer_creatFile(head); //���� 
		if(a==0){
			cout<<"ϵͳ��û������ˣ�";
			cout<<"��1����";
			char e;
			t=getch();
		}
		system("cls");
		toxy(48,12);
		cout<<"----------------";
		toxy(48,14);
		cout<<"|   �Ƿ������ |";
		toxy(48,16);
		cout<<"|  1.��   2.�� |";
		toxy(48,18); 
		cout<<"----------------";
		while(1){
			t=getch();
			if(t=='1'){
				break;
			}
			else if(t=='2'){
				menu();
			}
		}
	}
}
void delete_academic_message(){
	academic_master *head=NULL;
	academic_master *p=NULL;
	academic_master *last=NULL;
	string name;
	char t;
	int a=0;
	while(1){
		system("cls");
		color(3);
		cout<<"������Ҫɾ�����о�����Ϣ:"<<endl;
		cin>>name;
		head=read_academic_message();
		p=head;
		while(p!=NULL){
			if(p->get_name()==name){
				a++;
				system("cls");
				toxy(24,2);
				cout<<"---------------------------";
				toxy(24,3);
				cout<<"|  ���о�����ȫ����ϢΪ:   "<<endl;
				toxy(24,5);
				cout<<"|��     ��:"<<p->get_name();
				toxy(24,7);
				cout<<"|ѧ     ��:"<<p->get_num();
				toxy(24,9);
				cout<<"|��     ��:"<<p->get_sex();
				toxy(24,11); 
				cout<<"|��     ��:"<<p->get_age();
				toxy(24,13);
				cout<<"|�γ� �ɼ�:"<<p->get_score();
				toxy(24,15);
				cout<<"|���� ����:"<<p->get_dissertation_num();
				toxy(24,17);
				cout<<"|����1����:"<<p->get_dissertation_name()[0];
				toxy(24,19);		
				cout<<"|����2����:"<<p->get_dissertation_name()[1];
				toxy(24,21);
				cout<<"|����3����:"<<p->get_dissertation_name()[2];
				toxy(24,23);
				cout<<"|����1�ȼ�:"<<p->get_dissertation_rank()[0];
				toxy(24,25);
				cout<<"|����2�ȼ�:"<<p->get_dissertation_rank()[1];
				toxy(24,27);
				cout<<"|����3�ȼ�:"<<p->get_dissertation_rank()[2]; 
				toxy(24,28);
				cout<<"---------------------------";
				toxy(48,11);
				cout<<"=============================";
				toxy(48,12);
				cout<<"|       ��ѡ��ɾ����ʽ      |";
				toxy(48,14);
				cout<<"| 1.����ɾ��   2.�߼�ɾ��   |"; 
				toxy(48,15);
				cout<<"=============================";
				while(1){
					t=getch();
					if(t=='1'){
						if(last==NULL){
							head=p->next;
							academic_creatFile(head);
							delete p;
						}
						else{
							last->next=p->next;
							academic_creatFile(head);
							delete p;
						}
						break;
					}
					else if(t=='2'){
						if(last==NULL){
							head=p->next;
							academic_creatFile(head);
							academic_ptr=new academic_master();
							academic_ptr->next=NULL;
							academic_ptr->set_name(p->get_name());
							academic_ptr->set_num(p->get_num());
							academic_ptr->set_sex(p->get_sex());
							academic_ptr->set_age(p->get_age());
							academic_ptr->set_major(p->get_major());
							academic_ptr->set_score(p->get_score());
							academic_ptr->set_dissertation_name(p->get_dissertation_name()[0],1);
							academic_ptr->set_dissertation_name(p->get_dissertation_name()[1],2);
							academic_ptr->set_dissertation_name(p->get_dissertation_name()[2],3);
							academic_ptr->set_dissertation_num(p->get_dissertation_num());
							academic_ptr->set_dissertation_rank(p->get_dissertation_rank()[0],1);
							academic_ptr->set_dissertation_rank(p->get_dissertation_rank()[1],2);
							academic_ptr->set_dissertation_rank(p->get_dissertation_rank()[2],3);
							delete p;
							if(academic_ptr_head==NULL){
								academic_ptr_head=academic_ptr;
							}
							academic_ptr=academic_ptr->next;
						}
						else{
							last->next=p->next;
							academic_creatFile(head);
							academic_master *ptr=new academic_master();
							ptr->set_name(p->get_name());
							ptr->set_num(p->get_num());
							ptr->set_sex(p->get_sex());
							ptr->set_age(p->get_age());
							ptr->set_major(p->get_major());
							ptr->set_score(p->get_score());
							ptr->set_dissertation_name(p->get_dissertation_name()[0],1);
							ptr->set_dissertation_name(p->get_dissertation_name()[1],2);
							ptr->set_dissertation_name(p->get_dissertation_name()[2],3);
							ptr->set_dissertation_num(p->get_dissertation_num());
							ptr->set_dissertation_rank(p->get_dissertation_rank()[0],1);
							ptr->set_dissertation_rank(p->get_dissertation_rank()[1],2);
							ptr->set_dissertation_rank(p->get_dissertation_rank()[2],3);
							delete p;
							if(academic_ptr_head==NULL){
								academic_ptr_head=ptr;
								academic_ptr=academic_ptr_head;
							}
							else{
								academic_ptr->next=ptr;
								academic_ptr=academic_ptr->next;
							}
						}
						break;
					}
				}
			}
			last=p;
			p=p->next;
		}
		system("cls");
		if(a==0){
			cout<<"ϵͳ��û�������"<<endl;
			cout<<"����1����....";
			char e;
			e=getch();
		}
		color(3);
		toxy(48,11);
		cout<<"======================";
		toxy(48,12);
		cout<<"|   �Ƿ����ɾ����   |";
		toxy(48,14);
		cout<<"|  1.��       2.��   |";
		toxy(48,15);
		cout<<"======================";
		char ch;
		while(1){
			ch=getch();
			if(ch=='1'){
				break;
			}
			else if(ch=='2'){
				menu();
			}
		} 
	}
}
void delete_engineer_message(){
	engineer_master *head=NULL;
	engineer_master *p=NULL;
	engineer_master *last=NULL;
	string name;
	while(1){
		system("cls");
		color(3);
		cout<<"������Ҫɾ���Ĺ����о���������:"<<endl;
		cin>>name;
		head=read_engineer_message();
		p=head;
		while(p!=NULL){
			if(p->get_name()==name){
				system("cls");
				toxy(24,2);
				cout<<"---------------------------";
				toxy(24,3);
				cout<<"|  ���о�����ȫ����ϢΪ:   "<<endl;
				toxy(24,5);
				cout<<"|��    ��:"<<p->get_name();
				toxy(24,7);
				cout<<"|ѧ    ��:"<<p->get_num();
				toxy(24,9);
				cout<<"|��    ��:"<<p->get_sex();
				toxy(24,11); 
				cout<<"|��    ��:"<<p->get_age();
				toxy(24,13);
				cout<<"|�γ̳ɼ�:"<<p->get_score();
				toxy(24,15);
				cout<<"|��Ŀ����:"<<p->get_field();
				toxy(24,17);
				cout<<"|��Ŀ����:"<<p->get_project_name();
				toxy(24,19);
				cout<<"|��Ŀ�ȼ�:"<<p->get_project_rank();
				toxy(24,20);
				cout<<"---------------------------";
				toxy(48,11);
				cout<<"=============================";
				toxy(48,12);
				cout<<"|       ��ѡ��ɾ����ʽ      |";
				toxy(48,14);
				cout<<"| 1.����ɾ��   2.�߼�ɾ��   |"; 
				toxy(48,15);
				cout<<"=============================";
				char t;
				
				while(1){
					t=getch();
					if(t=='1'){
						if(last==NULL){
							head=p->next;
							engineer_creatFile(head);
							delete p;
						}
						else{
							last->next=p->next;
							engineer_creatFile(head);
							delete p;
						}
						break;
					}
					else if(t=='2'){
						if(last==NULL){
							head=p->next;
							engineer_creatFile(head);
							engineer_ptr=new engineer_master();
							engineer_ptr->set_name(p->get_name());
							engineer_ptr->set_num(p->get_num());
							engineer_ptr->set_age(p->get_age());
							engineer_ptr->set_sex(p->get_sex());
							engineer_ptr->set_score(p->get_score());
							engineer_ptr->set_field(p->get_field());
							engineer_ptr->set_project_name(p->get_project_name());
							engineer_ptr->set_project_rank(p->get_project_rank());
							delete p;
							if(engineer_ptr_head==NULL){
								engineer_ptr_head=engineer_ptr;
							}
							engineer_ptr=engineer_ptr->next;
						}
						else{
							last->next=p->next;
							engineer_creatFile(head);
							engineer_master *ptr=new engineer_master();
							ptr->set_name(p->get_name());
							ptr->set_num(p->get_num());
							ptr->set_age(p->get_age());
							ptr->set_sex(p->get_sex());
							ptr->set_score(p->get_score());
							ptr->set_field(p->get_field());
							ptr->set_project_name(p->get_project_name());
							ptr->set_project_rank(p->get_project_rank());
							delete p;
							if(engineer_ptr_head==NULL){
								engineer_ptr_head=ptr;
								engineer_ptr=engineer_ptr_head;
							}
							else{
								engineer_ptr->next=ptr;
								engineer_ptr=engineer_ptr->next;
							}
						}
						break;
					}
				}
			}
			last=p;
			p=p->next;
		}
		system("cls");
		color(3);
		toxy(48,11);
		cout<<"======================";
		toxy(48,12);
		cout<<"|   �Ƿ����ɾ����   |";
		toxy(48,14);
		cout<<"|  1.��       2.��   |";
		toxy(48,15);
		cout<<"======================";
		char ch;
		while(1){
			ch=getch();
			if(ch=='1'){
				break;
			}
			else if(ch=='2'){
				menu();
			}
		} 
	}
}
void statistics_academic_message(){
	academic_master *head=NULL;
	academic_master *p=NULL;
	head=read_academic_message();
	p=head;
	int a_num=0;
	int b_num=0;
	int c_num=0;
	int d_num=0;
	int e_num=0;
	int f_num=0;
	float sum=0;
	float score;
	float dissertation_score;
	int i=0;
	float sum_aver;
	float a_aver;
	float b_aver;
	float c_aver;
	float d_aver;
	float e_aver;
	float f_aver;
	while(p!=NULL){
		i++;
		dissertation_score=(p->get_dissertation_rank()[0]*10/90+
		p->get_dissertation_rank()[1]*10/90+p->get_dissertation_rank()[2]*10/90)*100;
		p->set_dissertation_score(dissertation_score);
		score=p->get_score()*0.7+dissertation_score*0.3;
		p->set_academicsum_score(score);
		sum+=score;
		if(score==100){
			a_num++;
		}
		else if(score<100&&score>=90){
			b_num++;
		}
		else if(score<90&&score>=80){
			c_num++;
		}
		else if(score<80&&score>=70){
			d_num++;
		}
		else if(score<70&&score>=60){
			e_num++;
		}
		else if(score<60&&score>0){
			f_num++;
		}
		p=p->next;
	}
	sum_aver=(float)sum/i;
	a_aver=(float)a_num/i;
	b_aver=(float)b_num/i;
	c_aver=(float)c_num/i;
	d_aver=(float)d_num/i;
	e_aver=(float)e_num/i;
	f_aver=(float)f_num/i;
	system("cls");
	cout<<"��ϵͳ����ѧ���о���������Ϊ: "<<i<<endl;
	cout<<"��ϵͳ��ѧ���о������ܳɼ�ƽ��ֵΪ��"<<sum_aver<<endl;
	cout<<"�ܳɼ�����100�������Լ�ռ�����Ϊ:"<<a_num<<" "<<a_aver<<endl;
	cout<<"�ܳɼ���90-100֮��������Լ�ռ�����Ϊ:"<<b_num<<" "<<b_aver<<endl;
	cout<<"�ܳɼ���80-90֮��������Լ�ռ�����Ϊ:"<<c_num<<" "<<c_aver<<endl;
	cout<<"�ܳɼ���70-80֮��������Լ�ռ�����Ϊ:"<<d_num<<" "<<d_aver<<endl;
	cout<<"�ܳɼ���60-70֮��������Լ�ռ�����Ϊ:"<<e_num<<" "<<e_aver<<endl;
	cout<<"�ܳɼ�������������Լ�ռ�����Ϊ:"<<f_num<<" "<<f_aver<<endl;
	p=head;
	int j=0;
	academic_master **pt=new academic_master*[i];
	while(p!=NULL){
		pt[j++]=p;
		p=p->next;
	} 
	for(int a=0;a<i;a++){
		for(int b=a+1;b<i;b++){
			academic_master *temp;
			if(pt[a]->get_academicsum_score()<pt[b]->get_academicsum_score()){
				temp=pt[a];
				pt[a]=pt[b];
				pt[b]=temp;
			}
		}
	}
	cout<<"��ѧ���о������ܳɼ�����Ϊ:"<<endl;
	for(int a=0;a<i;a++){
		cout<<pt[a]->get_name()<<": "<<pt[a]->get_academicsum_score()<<endl;
	}
	char t;
	cout<<"����1�������˵���";
	while(1){
		t=getch();
		if(t=='1'){
			menu();
		}
		else{
			break;
		}
	}
}
void statistics_engineer_message(){
	engineer_master *head=NULL;
	engineer_master *p=NULL;
	head=read_engineer_message();
	p=head;
	int a_num=0;
	int b_num=0;
	int c_num=0;
	int d_num=0;
	int e_num=0;
	int f_num=0;
	float sum=0;
	float score;
	float project_score;
	int i=0;
	float sum_aver;
	float a_aver;
	float b_aver;
	float c_aver;
	float d_aver;
	float e_aver;
	float f_aver;
	while((p!=NULL)&&(p->next!=NULL)){
		i++;
		if(p->get_project_rank()=='a'){
			project_score=90;
			p->set_project_score(project_score);
			score=p->get_score()*0.5+project_score*0.5;
		}
		else if(p->get_project_score()=='b'){
			project_score=75;
			p->set_project_score(project_score);
			score=p->get_score()*0.5+project_score*0.5;
		}
		else if(p->get_project_score()=='c'){
			project_score=60;
			p->set_project_score(project_score);
			score=p->get_score()*0.5+project_score*0.5;
		}
		p->set_engineersum_score(score);
		sum+=score;
		if(score==100){
			a_num++;
		}
		else if(score<100&&score>=90){
			b_num++;
		}
		else if(score<90&&score>=80){
			c_num++;
		}
		else if(score<80&&score>=70){
			d_num++;
		}
		else if(score<70&&score>=60){
			e_num++;
		}
		else if(score<60&&score>0){
			f_num++;
		}
		p=p->next;
	}
	sum_aver=(float)sum/i; 
	a_aver=(float)a_num/i;
	b_aver=(float)b_num/i;
	c_aver=(float)c_num/i;
	d_aver=(float)d_num/i;
	e_aver=(float)e_num/i;
	f_aver=(float)f_num/i;
	system("cls");
	cout<<"��ϵͳ���й����о���������Ϊ: "<<i<<endl;
	cout<<"��ϵͳ�﹤���о������ܳɼ�ƽ��ֵΪ��"<<sum_aver<<endl;
	cout<<"�ܳɼ�����100�������Լ�ռ�����Ϊ:"<<a_num<<" "<<a_aver<<endl;
	cout<<"�ܳɼ���90-100֮��������Լ�ռ�����Ϊ:"<<b_num<<" "<<b_aver<<endl;
	cout<<"�ܳɼ���80-90֮��������Լ�ռ�����Ϊ:"<<c_num<<" "<<c_aver<<endl;
	cout<<"�ܳɼ���70-80֮��������Լ�ռ�����Ϊ:"<<d_num<<" "<<d_aver<<endl;
	cout<<"�ܳɼ���60-70֮��������Լ�ռ�����Ϊ:"<<e_num<<" "<<e_aver<<endl;
	cout<<"�ܳɼ�������������Լ�ռ�����Ϊ:"<<f_num<<" "<<f_aver<<endl;
	p=head;
	char t;
	engineer_master **pt=new engineer_master*[i];
	int j=0;
	while(p!=NULL){
		pt[j++]=p;
		p=p->next;
	}
	for(int a=0;a<i;a++){
		for(int b=0;b<i;b++){
			engineer_master *temp;
			if(pt[a]->get_emgineersum_score()<pt[b]->get_emgineersum_score()){
				temp=pt[a];
				pt[a]=pt[b];
				pt[b]=temp;
			}
		}
	}
	cout<<"�ù����о������ܳɼ�����Ϊ:"<<endl;
	for(int a=0;a<i;a++){
		cout<<pt[a]->get_name()<<": "<<pt[a]->get_emgineersum_score()<<endl;
	}
	cout<<"����1���ز˵�:";
	while(1){
		t=getch();
		if(t=='1'){
			menu();
		}
		else{
			break;
		}
	}
}
void find_academic_message(){
	academic_master *head=NULL;
	academic_master *p=NULL;
	head=read_academic_message();
	p=head;
	int i=4;
	system("cls");
	color(3);
	toxy(1,3);
	cout<<"����"<<"ѧ��"<<"�Ա�"<<"����"<<"�ɼ�"
			<<"רҵ"<<"��������"<<"��������1"<<"��������2"
			<<"��������3"<<"���ĵȼ�1"<<"���ĵȼ�2"<<"���ĵȼ�3"<<endl;
	while(p!=NULL){
		toxy(1,i++);
		cout<<p->get_name()<<"\t"<<p->get_num()<<"\t"<<p->get_sex()<<"\t"
		<<p->get_age()<<"\t"<<p->get_score()<<"\t"<<p->get_major()<<"\t"
		<<p->get_dissertation_num()<<"\t"<<p->get_dissertation_name()[0]<<"\t"
		<<p->get_dissertation_name()[1]<<"\t"<<p->get_dissertation_name()[2]<<"\t"
		<<p->get_dissertation_rank()[0]<<"\t"<<p->get_dissertation_rank()[1]<<"\t"
		<<p->get_dissertation_rank()[2];
		p=p->next;
	}
	while(1){
		char t;
		toxy(4,i++);
		cout<<"����1�ص��˵�:";
		t=getch();
		if(t=='1'){
			menu(); 
		}
		else{
			break; 
		}
	}
}
void find_engineer_message(){
	engineer_master *head=NULL;
	engineer_master *p=NULL;
	head=read_engineer_message();
	p=head;
	int i=4;
	system("cls");
	color(3);
	toxy(1,3);
	cout<<"����"<<"ѧ��"<<"�Ա�"<<"����"<<"�γ̳ɼ�"
			<<"�о�����"<<"��Ŀ����"<<"��Ŀ�ȼ�"; 
	while(p->next!=NULL){
		toxy(1,i++);
		cout<<p->get_name()<<"\t"<<p->get_num()<<"\t"<<p->get_sex()<<"\t"
		<<p->get_age()<<"\t"<<p->get_score()<<"\t"<<p->get_field()<<"\t"
		<<p->get_project_name()<<"\t"<<p->get_project_rank();
		p=p->next;
	}
	while(1){
		char t;
		toxy(4,i++);
		cout<<"����1�ص��˵�:";
		t=getch();
		if(t=='1'){
			menu(); 
		}
		else{
			break; 
		}
	}
}
void menu(){
	while(1){
		system("cls");
		char t;
		HideCursor();
		color(15);
		toxy(50,5);
		cout<<"��ӭ��½�о����ɼ�����ϵͳ:";
		toxy(48,8);
		cout<<"***************************";
		toxy(48,10);
		cout<<"|     1.¼����Ϣ          |";
		toxy(48,12);
		cout<<"|     2.�޸���Ϣ          |";
		toxy(48,14);
		cout<<"|     3.ɾ����Ϣ          |"; 
		toxy(48,16);
		cout<<"|     4.����ͳ��          |";
		toxy(48,18);
		cout<<"|     5.��Ϣ��ѯ          |";
		toxy(48,20); 
		cout<<"|     6.�˳����          |";
		toxy(48,22);
		cout<<"|     7.����ɾ��          |";
		toxy(48,24); 
		cout<<"***************************";
		t=getch();
		switch(t){
			case '1': input_message_choice();break;
			case '2': amend_message_choice();break;
			case '3': delete_message_choice();break;
			case '4': statistics_message_choice();break;
			case '5': find_message_choice();break;
			case '6': over();break;
			case '7': revoke_message_choice();break;
			default : break;
		}
	} 
} 
void input_message_choice(){
	char t;
	system("cls");
	toxy(48,11);
	cout<<"------------------------------------";
	toxy(48,12);
	cout<<"|     ��������������˶ʿ�ࣿ       |";
	toxy(48,14);
	cout<<"|    1.ѧ��˶ʿ      2.����˶ʿ    |";
	toxy(48,15);
	cout<<"------------------------------------";
	while(1){
		t=getch();
		if(t=='1'){
			input_academic_message();
			break;
		}
		else if(t=='2'){
			input_engineer_message();
			break;
		}
	}
	  
}
void amend_message_choice(){
	char t;
	system("cls");
	toxy(48,11);
	cout<<"------------------------------------";
	toxy(48,12);
	cout<<"|     ��������������˶ʿ�ࣿ       |";
	toxy(48,14);
	cout<<"|    1.ѧ��˶ʿ      2.����˶ʿ    |";
	toxy(48,15);
	cout<<"------------------------------------";
	while(1){
		t=getch();
		if(t=='1'){
			amend_academic_message();
			break;
		}
		else if(t=='2'){
			amend_engineer_message();
			break;
		}
	}
}
void delete_message_choice(){
	char t;
	system("cls");
	toxy(48,11);
	cout<<"------------------------------------";
	toxy(48,12);
	cout<<"|     ��������������˶ʿ�ࣿ       |";
	toxy(48,14);
	cout<<"|    1.ѧ��˶ʿ      2.����˶ʿ    |";
	toxy(48,15);
	cout<<"------------------------------------";
	while(1){
		t=getch();
		if(t=='1'){
			delete_academic_message();
			break;
		}
		else if(t=='2'){
			delete_engineer_message();
			break;
		}
	}
}
void statistics_message_choice(){
	char t;
	system("cls");
	toxy(48,11);
	cout<<"------------------------------------";
	toxy(48,12);
	cout<<"|     ��������������˶ʿ�ࣿ       |";
	toxy(48,14);
	cout<<"|    1.ѧ��˶ʿ      2.����˶ʿ    |";
	toxy(48,15);
	cout<<"------------------------------------";
	while(1){
		t=getch();
		if(t=='1'){
			statistics_academic_message();
			break;
		}
		else if(t=='2'){
			statistics_engineer_message();
			break;
		}
	}
}
void find_message_choice(){
	char t;
	system("cls");
	toxy(48,11);
	cout<<"------------------------------------";
	toxy(48,12);
	cout<<"|     ��������������˶ʿ�ࣿ       |";
	toxy(48,14);
	cout<<"|    1.ѧ��˶ʿ      2.����˶ʿ    |";
	toxy(48,15);
	cout<<"------------------------------------";
	while(1){
		t=getch();
		if(t=='1'){
			find_academic_message();
			break;
		}
		else if(t=='2'){
			find_engineer_message();
			break;
		}
	}
}
void revoke_message_choice(){
	char t;
	system("cls");
	toxy(48,11);
	cout<<"------------------------------------";
	toxy(48,12);
	cout<<"|     ��������������˶ʿ�ࣿ       |";
	toxy(48,14);
	cout<<"|    1.ѧ��˶ʿ      2.����˶ʿ    |";
	toxy(48,15);
	cout<<"------------------------------------";
	while(1){
		t=getch();
		if(t=='1'){
			revoke_academic_message();
			break;
		}
		else if(t=='2'){
			revoke_engineer_message();
			break;
		}
	}
}
void over(){
	char t;
	toxy(48,11);
	cout<<"--------------------------";
	toxy(48,12);
	cout<<"|    ��ȷ��Ҫ�˳���    |";
	toxy(48,14);
	cout<<"|  1.ȷ��       2.ȡ��   |";
	toxy(48,15);
	cout<<"--------------------------";
	while(1){
		t=getch();
		switch(t){
			case '1': 
				color(6);
				toxy(48,10);
				cout<<"�����˳�.....";
				Sleep(1000);
				system("cls");
				color(8);
				toxy(48,10);
				cout<<"---------------";
				toxy(48,11);
				cout<<"| ���˳����  |"; 
				toxy(48,13);
				cout<<"| ��лʹ�ã�  |";
				toxy(48,14);
				cout<<"---------------";
				exit(0);
				break;
			case '2':
				menu();
				break;
			default :break;	
		}
	}
}
int main(){
	menu();
}
