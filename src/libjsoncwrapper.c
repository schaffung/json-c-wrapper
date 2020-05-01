/*
	Author: schaffung
	Date: 30/4/2020
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libjsoncwrapper.h"


int new_jobj_int_val(json_object *jobj, const char *key, int value)
{
	if( key == NULL )
	{
		return -1;
	}
	jobj = json_object_new_object();
	json_object_object_add(jobj, key, json_object_new_int(value));
	return 0;
}


int new_jobj_bool_val(json_object *jobj, const char *key, int value)
{
	if( key == NULL )
	{
		return -1;
	}
	jobj = json_object_new_object();
	json_object_object_add(jobj, key, json_object_new_boolean(value));	
	return 0;
}

int new_jobj_double_val(json_object *jobj, const char *key, double value)
{
	if( key == NULL )
	{
		return -1;
	}
	jobj = json_object_new_object();
	json_object_object_add(jobj, key, json_object_new_double(value));
	return 0;
}

int new_jobj_string_val(json_object *jobj, const char *key, const char *value)
{
	if( key == NULL || value == NULL )
	{
		return -1;
	}
	jobj = json_object_new_object();
	json_object_object_add(jobj, key, json_object_new_string(value));
	return 0;
}

int new_jobj_jarr_val(json_object *jobj, const char *key, json_object *jarr)
{
	if( key == NULL )
	{
		return -1;
	}
	(jobj = json_object_new_object();
	json_object_object_add(jobj, key, jarr);
	return 0;
}

int new_jobj_jobj_val(json_object *jobj1, const char *key, json_object *jobj2)
{
	if( key == NULL )
	{
		return -1;
	}
	jobj1 = json_object_new_object();
	json_object_object_add(jobj1, key, jobj2);
	return 0;
}

int embed_object(json_object *jobj1, const char *key, json_object *jobj2)
{
	if( key == NULL )
	{
		return -1;
	}
	json_object_object_add(jobj1, key, jobj2);
	return 0;
}



int json_object_to_string(json_object *jobj, char *json_in_string)
{
	char *json_in_string_ptr = NULL;

	if( jobj == NULL )
	{
		return -1;
	}
	
	json_in_string_ptr = (char *)json_object_to_json_string(jobj);
	
	json_in_string = (char *)malloc((strlen(json_in_string_ptr)+1));
	if( json_in_string == NULL )
	{
		return -2;
	}
	memset(json_in_string, '\0', strlen(json_in_string));
	strcpy(json_in_string, json_in_string_ptr);
	
	return 0;
}

	