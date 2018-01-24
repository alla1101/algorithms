/* 
	experiment 17: heap and stack Memory allocation
	
	in this program, we're going to take a huge leap in 
	difficulty ... A program to manage a Database.

*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address{
	
	int id;
	
	int set;
	
	char name[MAX_DATA];
	
	char email[MAX_DATA];

};

struct Database{

	struct Address rows[MAX_ROWS];

};

struct Connection{

	FILE *file;
	struct Database *db;

};

void die(const char *message){

	if(errno){

		perror(message);

	}else{

		printf("Error: %s \n",message);

	}

	exit(1);

}

/*
	Address Print:
	prints one Address
*/
void Address_Print(struct Address *addr){

	printf("address->id=%d,address->set=%d,address->name=%s,address->email=%s\n",addr->id,addr->set,addr->name,addr->email);

}
/*
	Database Load
	loads the whole DB into conn->db
*/
void Database_Load(struct Connection *conn){

	int rc=fread(conn->db,sizeof(struct Database),1,conn->file);
	
	if (rc != 1){ 
		
		die("failed to load Database"); 

	}

}
/*
	Database Open
	
	Creates new connection
	allocates db in memory
	if mode =c then it opens file with write permission
	if mode !=c then it opens file with +r permission, and if file exists,
		it calls Database_Load 
*/
struct Connection *Database_Open(const char *file_name, char mode){

	struct Connection *conn=malloc(sizeof(struct Connection));

	if(!conn){
	
		die("memmory error");
	
	}

	conn->db=malloc(sizeof(struct Database));

	if(!conn->db){

		die("memory error");

	}

	if(mode == 'c'){

		conn->file=fopen(file_name,"w");

	}else{

		conn->file=fopen(file_name,"r+");

		if(conn->file){

			Database_Load(conn);

		}
	}

	if(!conn->file){

		die("Failed to open file");

	}

	return conn;
}
/*
	closes connections to Database
	frees memory 
*/
void Database_Close(struct Connection *conn){

	if(conn){

		if(conn->file){
		
			fclose(conn->file);
		
		}

		if(conn->db){
		
			free(conn->db);
		
		}

		free(conn);
	
	}

}
/*
	Database writes
	writes the whole db into file
*/
void Database_Write(struct Connection *conn){

	rewind(conn->file);

	int rc=fwrite(conn->db,sizeof(struct Database),1,conn->file);

	if(rc!=1){	die("error writing into database"); }

	rc=fflush(conn->file);

	if(rc==-1){	die("cannot flush database"); }
}

/*
	Creating Database
	initializing addresses in rows
	and put them into db in conn
*/
void Database_Create(struct Connection *conn){

	int i=0;
		
	for(i=0;i<MAX_ROWS;i++){
		//make a prototype to initialize 
		struct Address addr={.id=i, .set=0 };
		//store it in a row
		conn->db->rows[i]=addr;
	}

}
/*
	Database Set
*/
void Database_Set(struct Connection *conn, int id, char *name, char *email){

	struct Address *addr= &conn->db->rows[id];

	if(addr->set){	die("Already set, delete it first you retard"); }

	addr->set=1;

	//warining: there will be bugs
	char *res=strncpy(addr->name,name,MAX_DATA);
	//demonstrate the strncpy bug
	if(!res){	die("Name coping failed"); }

	res=strncpy(addr->email,email, MAX_DATA);

	if(!res){	die("email coping failed"); }

}

void Database_Get(struct Connection *conn, int id){

	struct Address *addr=&conn->db->rows[id];

	if(addr->set){

		Address_Print(addr);

	}else{

		die("ID is not set");

	}
}

void Database_Delete(struct Connection *conn, int id){
	
	struct Address addr={.id=id, .set=0};
	
	conn->db->rows[id]=addr;

}

void Database_List(struct Connection *conn){

	int i=0;

	struct Database *db=conn->db;

	for(i=0;i<MAX_ROWS;i++){

		struct Address *addr=&db->rows[i];

		if(addr->set){

			Address_Print(addr);
		
		}
	
	}
}

int main(int argc,char *argv[]){

	if(argc<3){die("usage: ./ex15 <dbfile> <action> [action parameters]"); }
	
	char *file_name=argv[1];

	char action=argv[2][0];

	struct Connection *conn=Database_Open(file_name,action);

	int id=0;

	if(argc > 3){	id=atoi(argv[3]); }

	if(id >= MAX_ROWS) { die("there're not that many records in database"); }

	switch(action){
		case 'c':
		case 'C':
			Database_Create(conn);
			Database_Write(conn);
			break;

		case 'g':
		case 'G':
			if(argc !=4){	die("there's no ID to get you idiot");}
			Database_Get(conn,id);
			break;

		case 's':
		case 'S':
			if(argc!=6){die("needs alot more info[id name email]");}
			Database_Set(conn,id,argv[4],argv[5]);
			Database_Write(conn);
			break;

		case 'd':
		case 'D':
			if(argc !=4){	die("there's no ID to delete you idiot");}
			Database_Delete(conn,id);
			Database_Write(conn);
			break;

		case 'l':
		case 'L':
			Database_List(conn);
			break;

		default:
			die("c,g,s,d or l, you idiot");
	}

	Database_Close(conn);

	return 0;

}