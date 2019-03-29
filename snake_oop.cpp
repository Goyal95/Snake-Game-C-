#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{
	char data;
	Node *next;
	Node *prev;
	int pox;
	int poy;
	public:
	Node();
	Node(int,int);
	int GetData() const;
	void SetData(int);
	Node* GetNext() const; 
	void SetNext(Node*);
	Node* GetPrev() const;
	void SetPrev(Node*);
	static Node* Create(int,int);
	int GetPox() const;
	void SetPox(int);
	int GetPoy() const;
	void SetPoy(int);
};

 Node::Node(){
 	data='O'; next=NULL; prev=NULL; pox=6; poy=10;
 }
 
 Node::Node(int x,int y){
 	data='o'; next=NULL; prev=NULL; pox=x; poy=y;
 }
 
 int Node::GetData() const{
 	return this->data;	
 }
 
 void Node::SetData(int value){
 	this->data=value;	
 }
 
 Node* Node::GetNext() const{
 	return this->next;	
 }
 
 void Node::SetNext(Node* newnode){
 	this->next=newnode;		
 }
 
 Node* Node::GetPrev() const{
	return this->prev;
 }
 
 void Node::SetPrev(Node* newnode){
 	this->prev=newnode;
 }
 
 Node* Node::Create(int x,int y){
 	Node*temp;
 	if(x && y)
		temp=new Node(x,y);
 	else
	 	temp=new Node();
 	return temp;
 }
 
 int Node::GetPox() const{
	return this->pox;	
 }
	
 int Node::GetPoy() const{
	return this->poy;	
 }
	
void Node::SetPox(int x){
	this->pox=x;
}

void Node::SetPoy(int y){
	this->poy=y;
}

class Food{
	  	char data;
	  	int coordx;
	  	int coordy;
	  	public:
	  		Food();
	  		char GetData() const;
	  		int GetX() const;
	  		int GetY() const;
	  		void SetData(char);
	  		void SetX(int);
	  		void SetY(int);
	  		void GenerateFood(int *,int*);
};



Food::Food(){
	Food::data='*';
	Food::coordx=10;
	Food::coordy=9;
}

char Food::GetData() const{
	return this->data;
}

int Food::GetX() const{
	return this->coordx;
}

int Food::GetY() const{
	return this->coordy;
}
void Food::SetData(char data){
	this->data=data;
}
void Food::SetX(int x){
	this->coordx=x;
}
void Food::SetY(int y){
	this->coordy=y;
}

	
class BOX{
	int lengthx;
	int lengthy;
	char arr[50][50];
	public:
	BOX();	
	void intit();
	void UpdateBOX(Node*);
	void printBOX();
	void FoodBox(int,int,char);
};

BOX::BOX(){
	lengthx=20;
	lengthy=20;
	intit();
}

void BOX::intit(){
	int i,j;
	for(int i=0;i<=lengthx;i++){
		for(int j=0;j<=lengthy;j++){
			if(!i || !j || i==lengthx || j==lengthy){
				arr[i][j]='|';
			}
			else{
				arr[i][j]=' ';
			}
		}
	}
}

void BOX::printBOX(){
	for(int i=0;i<=lengthx;i++){
		for(int j=0;j<=lengthy;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
}

void BOX::UpdateBOX(Node* head){
	Node *temp;
	temp=head;
	while(temp!=NULL){
		arr[temp->GetPox()][temp->GetPoy()]=temp->GetData();
		temp=temp->GetNext();
	}
}
void BOX::FoodBox(int x ,int y,char data){
	arr[x][y]=data;
}
class Snake{
	Node* head;
	Node* tail;
	public:
		Snake();
		Node* GetHead() const;
		void SetHead(Node*);
		Node* GetTail() const;
		static Snake CreateSnake();
		void SetTail(Node*);
		int SnakeBite(int,int,Node*);
		char SnakeMove(char,char);
		int SnakeDies(Node*);
		Node *SnakeHead(char );
		void Swapper(int,int);
		void SnakeGrow(int,int);
		int EatsTail(Node*);
};
Snake::Snake(){
	head=NULL;
	tail=NULL;
}

char SnakeMove(char move,char prevmove){
if(move=='a'||move=='s'||move=='d'||move=='w'){
	if((move=='w' && prevmove!='s') || (move=='a' && prevmove!='d') 
	|| (move=='d' && prevmove!='a') || (move=='s' && prevmove!='w')){
		prevmove=move;
	}
}
return prevmove;
}
 	
Node* Snake::SnakeHead(char move){
	Node* temp=new Node();
	if(move=='w'){
		temp->SetPox(this->GetHead()->GetPox()-1);   
		temp->SetPoy(this->GetHead()->GetPoy());	 
	}
	else if(move=='s'){
		temp->SetPox(this->GetHead()->GetPox()+1);
		temp->SetPoy(this->GetHead()->GetPoy());
	}
	else if(move=='a'){
		temp->SetPox(this->GetHead()->GetPox());
		temp->SetPoy(this->GetHead()->GetPoy()-1);
	}
	else if(move=='d'){
		temp->SetPox(this->GetHead()->GetPox());
		temp->SetPoy(this->GetHead()->GetPoy()+1);
	}
	return temp;
}

void Snake::Swapper(int cx,int cy){
		Node *temp,*temp1;
		temp=this->GetHead();
		int size=0;
		while(temp!=NULL){
		int x=0,y=0;
		size++;
		if(temp->GetNext()==NULL){
			temp->SetData(' ');
			size--;
		}
		x=temp->GetPox();  
		y=temp->GetPoy();
				temp->SetPox(cx);
				temp->SetPoy(cy);
			cx=x;
			cy=y;
			temp=temp->GetNext();
		}
}

Node* Snake::GetHead() const{
	return this->head;
}

Node* Snake::GetTail() const{
	return this->tail;
}

void Snake::SetHead(Node* newnode){
	this->head=newnode;
}

void Snake::SetTail(Node* newnode){
	this->tail=newnode;	
}

Snake Snake::CreateSnake(){
	Node *head,*temp,*temp1;
	head=Node::Create(0,0);
	temp=head;
	for(int i=10;i<15;i++){
		temp1=Node::Create(5,i);		
		temp->SetNext(temp1);
		temp=temp1;
	}
	temp->SetData(' ');
	Snake c;
	c.SetTail(temp);
	c.SetHead(head);
	return  c;
}

int main(){
	BOX baby;
	Snake snake,*head1,snake2;
	Node *head,*cobra;
	snake2=snake.CreateSnake();
	baby.UpdateBOX(snake2.GetHead());
	Food Mouse;
	int xloc,yloc;
	char data;
	xloc=Mouse.GetX();
	yloc=Mouse.GetY();
	data=Mouse.GetData();
	baby.FoodBox(xloc,yloc,data);
	baby.printBOX();
	char ch,prev='s',move;
	while(1){
		cin>>ch;
		prev=SnakeMove(ch,prev);
		head=snake2.SnakeHead(prev);
		if(snake2.SnakeDies(head)){
			cout<<"Game Over\n";
			break;
		}
		if(snake2.SnakeBite(xloc,yloc,head)){
			snake2.SnakeGrow(head->GetPox(),head->GetPoy());
			Mouse.GenerateFood(&xloc,&yloc);
			baby.FoodBox(xloc,yloc,'*');
			system("cls");
		}
		else{
			if(snake2.EatsTail(head))
				cout<<"eats\n.";
			snake2.Swapper(head->GetPox(),head->GetPoy());
		}
		baby.UpdateBOX(snake2.GetHead());
		system("cls");
		baby.printBOX();
	}
}
	
int Snake::SnakeBite(int x,int y,Node* head){
	if(head->GetPox()==x && head->GetPoy()==y){
		return 1;
	}
	else{
		return 0;
	}
}

void Snake::SnakeGrow(int cx,int cy){
		Node *temp,*temp1,*temp2;
		int flag=0,one,two;
		temp=this->GetHead();
		while(temp!=NULL){
			int x=0,y=0;
			if(!flag){
				if(temp->GetNext()->GetNext()==NULL){
					temp1=temp;
					flag=1;
				}
			}
			if(temp->GetNext()==NULL){	
				temp->SetData('o');
			}
			x=temp->GetPox();  
			y=temp->GetPoy();
			temp->SetPox(cx);
			temp->SetPoy(cy);
			cx=x; cy=y;
			one=temp->GetPox();
			two=temp->GetPoy();
			temp=temp->GetNext();
		}
		temp2=Node::Create(one,two);
		temp=this->GetHead();
		while(temp->GetNext()!=NULL)
			temp=temp->GetNext();
		temp->SetNext(temp2);
		this->SetTail(temp2);
}

void Food::GenerateFood(int *xloc,int *yloc){
	*xloc=rand()%(20-1)+1;
	*yloc=rand()%(20-1)+1;
}

int Snake::SnakeDies(Node* head){
	Node*temp=this->GetHead();
	if(head->GetPox()==-1 || head->GetPoy()==-1 || head->GetPox()==20 ||head->GetPoy()==20 || head->GetData() == ' ')
		return 1;
	return 0; 
}

int Snake::EatsTail(Node* head){
	Node*temp = this->GetHead();
	Node*temp1;
	while(temp!=NULL){
		if(head->GetPox()==temp->GetPox() && head->GetPoy()==temp->GetPoy()){
			temp1=temp->GetNext();
			while(temp1!=NULL){
				cout<<"1\n";
			printf("%c",temp1->GetData());
			printf("%c",temp1->GetData());
				temp1=temp1->GetNext();
			}
			temp->SetNext(NULL);
			this->SetTail(temp);
			return 1;
				}
	temp=temp->GetNext();
	}
	return 0;
}
