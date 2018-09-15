#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Object.h"
#include <assert.h>

void Object_destroy(void *self){

	Object *obj=self;

	assert(obj != NULL);
	assert(obj->description != NULL);
	free(obj->description);
	free(obj);

}

void Object_describe(void *self){

	Object *obj=self;
	assert(obj != NULL);
	assert(obj->description != NULL);
	printf("%s.\n",obj->description);

}

int Object_init(void *self){
	// Does Nothing
	return 1;
}

void *Object_move(void *self,Direction direction){

	printf("you can't go that direction\n");
	return NULL;

}

int Object_attack(void *self,int damage){

	printf("you can't attack that. \n");
	return 0;

}

void *Object_new(size_t size, Object proto, char *description){
	
	if(!proto.init){ proto.init=Object_init; }
	if(!proto.describe){ proto.describe=Object_describe; }
	if(!proto.destroy){ proto.destroy=Object_destroy; }
	if(!proto.attack){ proto.attack=Object_attack; }
	if(!proto.move){ proto.move=Object_move; }

	Object *el=calloc(1,size);
	
	assert(el != NULL);
	
	*el=proto;

	assert(description != NULL);
	el->description=strdup(description);

	assert(el->description != NULL);

	//initialize it with whatever init we were given
	if(!el->init(el)){
		
		el->destroy(el);
		
		return NULL;

	}

	return el;
}