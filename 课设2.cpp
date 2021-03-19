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
void HideCursor()     //隐藏光标
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
void revoke_message_choice();//选择撤回哪种研究生函数 
void find_message_choice();//选择查询哪种研究生函数 
void input_message_choice();//选择输入哪种研究生信息函数 
void amend_message_choice();//选择修改哪种研究生信息函数 
void delete_message_choice();//选择删除哪种研究生信息函数 
void statistics_message_choice();//选择分析哪种研究生信息函数 
void input_academic_message();//输入学术研究生信息函数 
void input_engineer_message();//输入工程研究生信息函数 
void amend_academic_message();//修改学术研究生信息函数 
void amend_engineer_message();//修改工程研究生信息函数 
void delete_academic_message();//删除学术研究生信息函数 
void delete_engineer_message();//删除工程研究生信息函数 
void statistics_academic_message();//分析学术研究生信息函数 
void statistics_engineer_message();//分析工程研究生信息函数 
void find_academic_message();//查询学术研究生信息函数 
void find_engineer_message();//查询工程研究生信息函数 
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
academic_master* read_academic_message();//返回学术研究生信息链表的头节点函数 
engineer_master* read_engineer_message();//返回工程研究生信息链表的头节点函数 
void academic_creatFile(academic_master *p);//创建学术研究生信息文件函数 
void engineer_creatFile(engineer_master *p);//创建工程研究生信息文件函数 
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
		cout<<"请输入学术研究生的姓名:";
		cin>>name;
		p->set_name(name);
		toxy(24,3);
		cout<<"请输入学术研究生的学号:";
		cin>>num;
		p->set_num(num);
		toxy(24,5);
		cout<<"请输入学术研究生的性别:";
		cin>>sex;
		p->set_sex(sex);
		toxy(24,7);
		cout<<"请输入学术研究生的年龄:";
		cin>>age;
		p->set_age(age);
		toxy(24,9);
		cout<<"请输入学术研究生的课程成绩:"; 
		cin>>score;
		p->set_score(score);
		toxy(24,11);
		cout<<"请输入学术研究生的专业:";
		cin>>major;
		p->set_major(major);
		toxy(24,13);
		cout<<"请输入学术研究生的论文数量:";
		cin>>dissertation_num;
		p->set_dissertation_num(dissertation_num);
		toxy(24,15);
		cout<<"请输入学术研究生的第几篇论文和论文名字:";
		cin>>a>>dissertation_name; 
		p->set_dissertation_name(dissertation_name,a);
		toxy(24,16);
		cout<<"请输入学术研究生的第几篇论文和论文名字:";
		cin>>a>>dissertation_name;
		p->set_dissertation_name(dissertation_name,a);
		toxy(24,17);
		cout<<"请输入学术研究生的第几篇论文和论文名字:";
		cin>>a>>dissertation_name;
		p->set_dissertation_name(dissertation_name,a);
		toxy(24,19);
		cout<<"请输入学术研究生的第几篇论文和论文等级:";
		cin>>a>>dissertation_rank;
		p->set_dissertation_rank(dissertation_rank,a);
		toxy(24,20);
		cout<<"请输入学术研究生的第几篇论文和论文等级:";
		cin>>a>>dissertation_rank;
		p->set_dissertation_rank(dissertation_rank,a);
		toxy(24,21);
		cout<<"请输入学术研究生的第几篇论文和论文等级:";
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
			cout<<"是否继续... 1表示继续/2表示退出"; 
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
	ofstream outfile("D:\\java2\\学术研究生成绩.txt",ios::out);
	if(!outfile){
		cerr<<"文件打开失败！"<<endl;
		exit(1);
	}
	outfile<<"姓名"<<"\t"<<"学号"<<"\t"<<"性别"<<"\t"<<"年龄"<<"\t"<<"成绩"<<"\t"
			<<"专业"<<"\t"<<"论文数量"<<"\t"<<"论文名字1"<<"\t"<<"论文名字2"<<"\t"
			<<"论文名字3"<<"\t"<<"论文等级1"<<"\t"<<"论文等级2"<<"论文等级3"<<endl; 
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
	ifstream infile("D:\\java2\\学术研究生成绩.txt",ios::in);
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
		cerr<<"文件打开失败！";
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
		cout<<"请输入工程研究生的姓名:";
		cin>>name;
		p->set_name(name);
		toxy(24,3);
		cout<<"请输入工程研究生的学号:";
		cin>>num;
		p->set_num(num);
		toxy(24,5);
		cout<<"请输入工程研究生的性别:";
		cin>>sex;
		p->set_sex(sex);
		toxy(24,7);
		cout<<"请输入工程研究生的年龄:";
		cin>>age;
		p->set_age(age);
		toxy(24,9);
		cout<<"请输入工程研究生的课程成绩:"; 
		cin>>score;
		p->set_score(score);
		toxy(24,11);
		cout<<"请输入工程研究生的研究领域:";
		cin>>field;
		p->set_field(field);
		toxy(24,13);
		cout<<"请输入工程研究生的项目名字:";
		cin>>project_name;
		p->set_project_name(project_name);
		toxy(24,15);
		cout<<"请输入工程研究生的项目等级:";
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
			cout<<"是否继续....1表示继续/2表示退出"; 
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
	ofstream outfile("D:\\java2\\工程研究生成绩.txt",ios::out);
	if(!outfile){
		cerr<<"文件打开失败！"<<endl;
		exit(1);
	}
	outfile<<"姓名"<<"\t"<<"学号"<<"\t"<<"性别"<<"\t"<<"年龄"<<"\t"<<"课程成绩"<<"\t"
			<<"研究领域"<<"\t"<<"项目名字"<<"\t"<<"项目等级"<<endl; 
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
	ifstream infile("D:\\java2\\工程研究生成绩.txt",ios::in);
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
		cerr<<"文件打开失败！"<<endl;
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
	cout<<"是否撤销删除？y/n";
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
	cout<<"是否撤销删除？y/n";
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
		cout<<"请输入要修改的学术研究生姓名:";
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
				cout<<"|  该研究生的全部信息为:   "<<endl;
				toxy(24,5);
				cout<<"|姓     名:"<<p->get_name();
				toxy(24,7);
				cout<<"|学     号:"<<p->get_num();
				toxy(24,9);
				cout<<"|性     别:"<<p->get_sex();
				toxy(24,11); 
				cout<<"|年     龄:"<<p->get_age();
				toxy(24,13);
				cout<<"|课程 成绩:"<<p->get_score();
				toxy(24,15);
				cout<<"|论文 数量:"<<p->get_dissertation_num();
				toxy(24,17);
				cout<<"|论文1名字:"<<p->get_dissertation_name()[0];
				toxy(24,19);		
				cout<<"|论文2名字:"<<p->get_dissertation_name()[1];
				toxy(24,21);
				cout<<"|论文3名字:"<<p->get_dissertation_name()[2];
				toxy(24,23);
				cout<<"|论文1等级:"<<p->get_dissertation_rank()[0];
				toxy(24,25);
				cout<<"|论文2等级:"<<p->get_dissertation_rank()[1];
				toxy(24,27);
				cout<<"|论文3等级:"<<p->get_dissertation_rank()[2]; 
				toxy(24,28);
				cout<<"---------------------------";
				toxy(55,2);
				cout<<"--------------------------" ;
				toxy(55,3);
				cout<<"|  请输入要修改的信息   |"; 
				toxy(55,5);
				cout<<"|   1.姓    名          |";
				toxy(55,7);
				cout<<"|   2.学    号          |";
				toxy(55,9);
				cout<<"|   3.性    别          |";
				toxy(55,11);
				cout<<"|   4.年    龄          |";
				toxy(55,13);
				cout<<"|   5.论文数量          |";
				toxy(55,15);
				cout<<"|   6.论文名字          |";
				toxy(55,17);
				cout<<"|   7.论文等级          |";
				toxy(55,19);
				cout<<"|   8.课程成绩          |";
				toxy(55,20);
				cout<<"-------------------------"; 
				char t;
				while(1){
					t=getch();
					if(t=='1'){
						system("cls");
						toxy(24,5);
						cout<<"请输入修改的姓名:";
						cin>>name1;
						p->set_name(name1);
						Sleep(500); 
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   修改成功   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='2'){ 
						system("cls");
						toxy(24,5);
						cout<<"请输入修改的学号:";
						cin>>num;
						p->set_num(num);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   修改成功   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='3'){
						system("cls");
						toxy(24,5);
						cout<<"请输入修改的性别:";
						cin>>sex;
						p->set_sex(sex);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   修改成功   |";
						toxy(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='4'){
						system("cls");
						toxy(24,5);
						cout<<"请输入修改的年龄:";
						cin>>age;
						p->set_age(age);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   修改成功   |";
						cout<<(48,16);
						cout<<"----------------"; 
						break;
					}
					else if(t=='5'){
						system("cls");
						toxy(24,5);
						cout<<"请输入修改的论文数量:";
						cin>>dissertation_num;
						p->set_dissertation_num(dissertation_num);
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   修改成功   |";
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
						cout<<"| 请输入修改第几篇论文: |";
						toxy(24,7);
						cout<<"|  1.第一篇  2.第二篇   |";
						toxy(24,8);
						cout<<"|  3.第三篇             |";
						toxy(24,9);
						cout<<"-------------------------";
						while(1){
							ch=getch();
							system("cls");
							color(6);
							if(ch=='1'){
								system("cls");
								toxy(24,5);
								cout<<"请输入修改论文1的名字:";
								cin>>dissertation_name[0];
								p->set_dissertation_name(dissertation_name[0],1);
								break;
							}
							else if(ch=='2'){
								system("cls");
								toxy(24,5);
								cout<<"请输入修改论文2的名字:";
								cin>>dissertation_name[1];
								p->set_dissertation_name(dissertation_name[1],2);
								break;
							}
							else if(ch=='3'){
								system("cls");
								toxy(24,5);
								cout<<"请输入修改论文3的名字:";
								cin>>dissertation_name[2];
								p->set_dissertation_name(dissertation_name[2],3);
								break;
							}
						}
						
						Sleep(500);
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   修改成功   |";
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
						cout<<"| 请输入修改第几篇论文: |";
						toxy(24,7);
						cout<<"|  1.第一篇  2.第二篇   |";
						toxy(24,8);
						cout<<"|  3.第三篇             |";
						toxy(24,9);
						cout<<"-------------------------";
						while(1){
							color(6);
							ch=getch();
							if(ch=='1'){
								system("cls");
								toxy(24,5);
								cout<<"请输入修改的论文1的等级:";
								cin>>dissertation_rank[0];
								p->set_dissertation_rank(dissertation_rank[0],1);
								break;
							}
							else if(ch=='2'){
								system("cls");
								toxy(24,5);
								cout<<"请输入修改的论文2的等级:";
								cin>>dissertation_rank[1];
								p->set_dissertation_rank(dissertation_rank[1],2);
								break;
							}
							else if(ch=='3'){
								system("cls");
								toxy(24,5);
								cout<<"请输入修改的论文3的等级:";
								cin>>dissertation_rank[2];
								p->set_dissertation_rank(dissertation_rank[2],3);
								break;
							}
						}
						toxy(48,12);
						cout<<"----------------";
						toxy(48,14);
						cout<<"|   修改成功   |";
						toxy(48,16);
						cout<<"----------------";
						break;
					}
					else if(t=='8'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的课程成绩:";
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
			cout<<"系统里没有这个人！";
			cout<<"按1继续...";
			char e;
			e=getch();
		}
		Sleep(1000);
		system("cls");
		toxy(48,12);
		cout<<"----------------";
		toxy(48,14);
		cout<<"|   是否继续？ |";
		toxy(48,16);
		cout<<"|  1.是   2.否 |";
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
		cout<<"请输入修改的工程硕士名字:";
		cin>>name;
		while((p!=NULL)&&(p->next!=NULL)){
			if((p!=NULL)&&(p->get_name()==name)){
				a++;
				system("cls");
				cout<<"该研究生的全部信息为:"<<endl;
				cout<<"姓名:"<<p->get_name()<<endl;
				cout<<"学号:"<<p->get_num()<<endl;
				cout<<"性别:"<<p->get_sex()<<endl;
				cout<<"年龄:"<<p->get_age()<<endl;
				cout<<"课程分数"<<p->get_score()<<endl;
				cout<<"研究领域:"<<p->get_field()<<endl;
				cout<<"研究项目名字:"<<p->get_project_name()<<endl;
				cout<<"研究项目等级:"<<p->get_project_rank()<<endl;
				toxy(55,2);
				cout<<"-------------------------" ;
				toxy(55,3);
				cout<<"|  请输入要修改的信息   |"; 
				toxy(55,5);
				cout<<"|   1.姓    名          |";
				toxy(55,7);
				cout<<"|   2.学    号          |";
				toxy(55,9);
				cout<<"|   3.性    别          |";
				toxy(55,11);
				cout<<"|   4.年    龄          |";
				toxy(55,13);
				cout<<"|   5.研究领域          |";
				toxy(55,15);
				cout<<"|   6.项目名字          |";
				toxy(55,17);
				cout<<"|   7.项目等级          |";
				toxy(55,19);
				cout<<"|   8.课程成绩          |"; 
				toxy(55,20);
				cout<<"-------------------------";
				while(1){
					t=getch();
					if(t=='1'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的名字:";
						cin>>name1;
						p->set_name(name1);
						break;
					}
					else if(t=='2'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的学号:";
						cin>>num;
						p->set_num(num);
						break;
					}
					else if(t=='3'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的性别:";
						cin>>sex;
						p->set_sex(sex);
						break;
					}
					else if(t=='4'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的年龄:";
						cin>>age;
						p->set_age(age);
						break;
					}
					else if(t=='5'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的研究领域:";
						cin>>field;
						p->set_field(field);
						break;
					}
					else if(t=='6'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的项目名称:";
						cin>>project_name;
						p->set_project_name(project_name);
						break;
					}
					else if(t=='7'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的项目等级:";
						cin>>project_rank;
						p->set_project_rank(project_rank);
						break;
					}
					else if(t=='8'){
						system("cls");
						toxy(24,5);
						cout<<"请输入要修改研究生的课程成绩:";
						cin>>score;
						p->set_score(score);
						break;
					}
				}
			}
			p=p->next;
		}
		engineer_creatFile(head); //测试 
		if(a==0){
			cout<<"系统里没有这个人！";
			cout<<"按1继续";
			char e;
			t=getch();
		}
		system("cls");
		toxy(48,12);
		cout<<"----------------";
		toxy(48,14);
		cout<<"|   是否继续？ |";
		toxy(48,16);
		cout<<"|  1.是   2.否 |";
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
		cout<<"请输入要删除的研究生信息:"<<endl;
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
				cout<<"|  该研究生的全部信息为:   "<<endl;
				toxy(24,5);
				cout<<"|姓     名:"<<p->get_name();
				toxy(24,7);
				cout<<"|学     号:"<<p->get_num();
				toxy(24,9);
				cout<<"|性     别:"<<p->get_sex();
				toxy(24,11); 
				cout<<"|年     龄:"<<p->get_age();
				toxy(24,13);
				cout<<"|课程 成绩:"<<p->get_score();
				toxy(24,15);
				cout<<"|论文 数量:"<<p->get_dissertation_num();
				toxy(24,17);
				cout<<"|论文1名字:"<<p->get_dissertation_name()[0];
				toxy(24,19);		
				cout<<"|论文2名字:"<<p->get_dissertation_name()[1];
				toxy(24,21);
				cout<<"|论文3名字:"<<p->get_dissertation_name()[2];
				toxy(24,23);
				cout<<"|论文1等级:"<<p->get_dissertation_rank()[0];
				toxy(24,25);
				cout<<"|论文2等级:"<<p->get_dissertation_rank()[1];
				toxy(24,27);
				cout<<"|论文3等级:"<<p->get_dissertation_rank()[2]; 
				toxy(24,28);
				cout<<"---------------------------";
				toxy(48,11);
				cout<<"=============================";
				toxy(48,12);
				cout<<"|       请选择删除方式      |";
				toxy(48,14);
				cout<<"| 1.物理删除   2.逻辑删除   |"; 
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
			cout<<"系统里没有这个人"<<endl;
			cout<<"输入1继续....";
			char e;
			e=getch();
		}
		color(3);
		toxy(48,11);
		cout<<"======================";
		toxy(48,12);
		cout<<"|   是否继续删除？   |";
		toxy(48,14);
		cout<<"|  1.是       2.否   |";
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
		cout<<"请输入要删除的工程研究生的名字:"<<endl;
		cin>>name;
		head=read_engineer_message();
		p=head;
		while(p!=NULL){
			if(p->get_name()==name){
				system("cls");
				toxy(24,2);
				cout<<"---------------------------";
				toxy(24,3);
				cout<<"|  该研究生的全部信息为:   "<<endl;
				toxy(24,5);
				cout<<"|姓    名:"<<p->get_name();
				toxy(24,7);
				cout<<"|学    号:"<<p->get_num();
				toxy(24,9);
				cout<<"|性    别:"<<p->get_sex();
				toxy(24,11); 
				cout<<"|年    龄:"<<p->get_age();
				toxy(24,13);
				cout<<"|课程成绩:"<<p->get_score();
				toxy(24,15);
				cout<<"|项目领域:"<<p->get_field();
				toxy(24,17);
				cout<<"|项目名称:"<<p->get_project_name();
				toxy(24,19);
				cout<<"|项目等级:"<<p->get_project_rank();
				toxy(24,20);
				cout<<"---------------------------";
				toxy(48,11);
				cout<<"=============================";
				toxy(48,12);
				cout<<"|       请选择删除方式      |";
				toxy(48,14);
				cout<<"| 1.物理删除   2.逻辑删除   |"; 
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
		cout<<"|   是否继续删除？   |";
		toxy(48,14);
		cout<<"|  1.是       2.否   |";
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
	cout<<"该系统里有学术研究生的人数为: "<<i<<endl;
	cout<<"该系统里学术研究生的总成绩平均值为："<<sum_aver<<endl;
	cout<<"总成绩等于100的人数以及占比情况为:"<<a_num<<" "<<a_aver<<endl;
	cout<<"总成绩在90-100之间的人数以及占比情况为:"<<b_num<<" "<<b_aver<<endl;
	cout<<"总成绩在80-90之间的人数以及占比情况为:"<<c_num<<" "<<c_aver<<endl;
	cout<<"总成绩在70-80之间的人数以及占比情况为:"<<d_num<<" "<<d_aver<<endl;
	cout<<"总成绩在60-70之间的人数以及占比情况为:"<<e_num<<" "<<e_aver<<endl;
	cout<<"总成绩不及格的人数以及占比情况为:"<<f_num<<" "<<f_aver<<endl;
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
	cout<<"该学术研究生的总成绩排名为:"<<endl;
	for(int a=0;a<i;a++){
		cout<<pt[a]->get_name()<<": "<<pt[a]->get_academicsum_score()<<endl;
	}
	char t;
	cout<<"输入1返回主菜单：";
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
	cout<<"该系统里有工程研究生的人数为: "<<i<<endl;
	cout<<"该系统里工程研究生的总成绩平均值为："<<sum_aver<<endl;
	cout<<"总成绩等于100的人数以及占比情况为:"<<a_num<<" "<<a_aver<<endl;
	cout<<"总成绩在90-100之间的人数以及占比情况为:"<<b_num<<" "<<b_aver<<endl;
	cout<<"总成绩在80-90之间的人数以及占比情况为:"<<c_num<<" "<<c_aver<<endl;
	cout<<"总成绩在70-80之间的人数以及占比情况为:"<<d_num<<" "<<d_aver<<endl;
	cout<<"总成绩在60-70之间的人数以及占比情况为:"<<e_num<<" "<<e_aver<<endl;
	cout<<"总成绩不及格的人数以及占比情况为:"<<f_num<<" "<<f_aver<<endl;
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
	cout<<"该工程研究生的总成绩排名为:"<<endl;
	for(int a=0;a<i;a++){
		cout<<pt[a]->get_name()<<": "<<pt[a]->get_emgineersum_score()<<endl;
	}
	cout<<"输入1返回菜单:";
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
	cout<<"姓名"<<"学号"<<"性别"<<"年龄"<<"成绩"
			<<"专业"<<"论文数量"<<"论文名字1"<<"论文名字2"
			<<"论文名字3"<<"论文等级1"<<"论文等级2"<<"论文等级3"<<endl;
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
		cout<<"输入1回到菜单:";
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
	cout<<"姓名"<<"学号"<<"性别"<<"年龄"<<"课程成绩"
			<<"研究领域"<<"项目名字"<<"项目等级"; 
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
		cout<<"输入1回到菜单:";
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
		cout<<"欢迎登陆研究生成绩管理系统:";
		toxy(48,8);
		cout<<"***************************";
		toxy(48,10);
		cout<<"|     1.录入信息          |";
		toxy(48,12);
		cout<<"|     2.修改信息          |";
		toxy(48,14);
		cout<<"|     3.删除信息          |"; 
		toxy(48,16);
		cout<<"|     4.数据统计          |";
		toxy(48,18);
		cout<<"|     5.信息查询          |";
		toxy(48,20); 
		cout<<"|     6.退出软件          |";
		toxy(48,22);
		cout<<"|     7.撤销删除          |";
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
	cout<<"|     请问您属于哪种硕士类？       |";
	toxy(48,14);
	cout<<"|    1.学术硕士      2.工程硕士    |";
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
	cout<<"|     请问您属于哪种硕士类？       |";
	toxy(48,14);
	cout<<"|    1.学术硕士      2.工程硕士    |";
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
	cout<<"|     请问您属于哪种硕士类？       |";
	toxy(48,14);
	cout<<"|    1.学术硕士      2.工程硕士    |";
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
	cout<<"|     请问您属于哪种硕士类？       |";
	toxy(48,14);
	cout<<"|    1.学术硕士      2.工程硕士    |";
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
	cout<<"|     请问您属于哪种硕士类？       |";
	toxy(48,14);
	cout<<"|    1.学术硕士      2.工程硕士    |";
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
	cout<<"|     请问您属于哪种硕士类？       |";
	toxy(48,14);
	cout<<"|    1.学术硕士      2.工程硕士    |";
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
	cout<<"|    您确定要退出吗？    |";
	toxy(48,14);
	cout<<"|  1.确定       2.取消   |";
	toxy(48,15);
	cout<<"--------------------------";
	while(1){
		t=getch();
		switch(t){
			case '1': 
				color(6);
				toxy(48,10);
				cout<<"正在退出.....";
				Sleep(1000);
				system("cls");
				color(8);
				toxy(48,10);
				cout<<"---------------";
				toxy(48,11);
				cout<<"| 已退出软件  |"; 
				toxy(48,13);
				cout<<"| 感谢使用！  |";
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
