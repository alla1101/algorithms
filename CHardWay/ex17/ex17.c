//Exercise 19: A simple object system
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex17.h"

int Monster_attack(void *self,int damage){
	Monster *monster=self;

	printf("you attack %s!\n",monster->_(description));
	
	monster->hit_points-=damage;

	if(monster->hit_points <= 0){
		printf("It's dead\n");
		return 1;
	}

	printf("it's still alive.\n");
	return 0;

}

int Monster_init(void *self){

	Monster *monster=self;

	monster->hit_points=10;

	return 1;
}

Object MonsterProto={
	.init=Monster_init,
	.attack=Monster_attack
};

void *Room_move(void *self,Direction direction){
	Room *room = self;
	Room *next=NULL;

	if(direction == NORTH && room->north){
		printf("you go north, into : \n");
		next=room->north;
	} else if(direction == SOUTH && room->south){
		printf("you go south, into : \n");
		next=room->south;
	} else if(direction == EAST && room->east){
		printf("you go east, into : \n");
		next=room->east;
	} else if(direction == WEST && room->west){
		printf("you go west, into : \n");
		next=room->west;
	} else {
		printf("you can't go that direction.\n");
		next=NULL;
	}

	if(next){
		next->_(describe)(next);
	}

	return next;
}

int Room_attack(void *self, int damage){
	Room *room=self;
	Monster *monster=room->bad_guy;

	if(!monster){
		printf("you flail in the air at nothing. Idiot. \n");
	}else{

		monster->_(attack)(monster,damage);
	}

	return 1;
}

Object RoomProto={
	.move=Room_move,
	.attack=Room_attack
};

void *Map_move(void *self,Direction direction){
	Map *map=self;
	Room *location = map->location;
	Room *next = NULL;

	next=location->_(move)(location,direction);
	if(next){
		map->location=next;
	}

	return next;
}

int Map_attack(void *self,int damage){
	Map *map=self;
	Room *location=map->location;
	return location->_(attack)(location,damage);
}
int Map_init(void *self){
	Map *map=self;

	//make some rooms for small map
	Room *hall=NEW(Room,"the great Hall");
	Room *throne=NEW(Room,"the great throne");
	Room *arena=NEW(Room,"the great arena");
	Room *kitchen=NEW(Room,"the great kitchen");

	arena->bad_guy=NEW(Monster,"the evil mintaur");

	//setup map rooms
	hall->north=throne;
	
	throne->west=arena;
	throne->east=kitchen;
	throne->south=hall;

	arena->east=throne;
	kitchen->west=throne;

	//start the map and the character off in the hall
	map->start=hall;
	map->location=hall;
	return 1;
}

Object MapProto={
	.init=Map_init,
	.move=Map_move,
	.attack=Map_attack
};

int process_input(Map *game){
	printf("\n> ");
	char ch=getchar();
	getchar(); // eat enter
	int damage=rand()%4;

	switch(ch){
		case -1:
			printf("giving up? you sucker .\n");
			return 0;
			break;
		case 'n':
			game->_(move)(game,NORTH);
			break;
		case 's':
			game->_(move)(game,SOUTH);
			break;
		case 'e':
			game->_(move)(game,EAST);
			break;
		case 'w':
			game->_(move)(game,WEST);
			break;
		case 'a':
			game->_(attack)(game,damage);
			break;
		case 'l':
			printf("you can go: \n");
			if(game->location->north)printf("north\n");
			if(game->location->south)printf("south\n");
			if(game->location->west)printf("west\n");
			if(game->location->east)printf("east\n");
			break;
		default:
			printf("what? %d\n",ch);
	}

	return 1;
}

int main(int argc,char *argv[]){
	//simple way to setup randomness
	srand(time(NULL));

	//Make our map to work with
	Map *game=NEW(Map,"the hall of the minotaur.\n");
	printf("you enter the ");
	game->location->_(describe)(game->location);
	while(process_input(game)){}
		return 0;
}