/*
	Author: schaffung
	Date: 30/4/2020
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>
#include "libjsoncwrapper.h"


int create_json_int(void *jobj, const char *key, int value)
{
	if( key == NULL )
	{
		return -1;
	}
	(json_object*)jobj = json_object_new_object();
	json_object_object_add((json_object*)jobj, key, json_object_new_int(value));
	return 0;
}


int create_json_boolean(void *jobj, const char *key, int value)
{
	if( key == NULL )
	{
		return -1;
	}
	(json_object*)jobj = json_object_new_object();
	json_object_object_add((json_object*)jobj, key, json_object_new_boolean(value));	
	return 0;
}

int create_json_double(void *jobj, const char *key, double value)
{
	if( key == NULL )
	{
		return -1;
	}
	(json_object*)jobj = json_object_new_object();
	json_object_object_add((json_object*)jobj, key, json_object_new_double(value));
	return 0;
}

int create_json_string(void *jobj, const char *key, const char *value)
{
	if( key == NULL || value == NULL )
	{
		return -1;
	}
	(json_object*)jobj = json_object_new_object();
	json_object_object_add((json_object*)jobj, key, json_object_new_string(value));
	return 0;
}

int create_json_array(void *jobj, const char *key, void *jarr)
{
	if( key == NULL )
	{
		return -1;
	}
	(json_object*)jobj = json_object_new_object();
	json_object_object_add(( json_object*)jobj, key, (json_object*)jarr);
	return 0;
}

int embed_object(void *jobj1, const char *key, void *jobj2)
{
	if( key == NULL )
	{
		return -1;
	}
	json_object_object_add((json_object*)jobj1, key, (json_object*)jobj2);
	return 0;
}

int embed_object_new(void *jobj1, const char *key, void *jobj2)
{
	if( key == NULL )
	{
		return -1;
	}
	(json_object*)jobj1 = json_object_new_object();
	json_object_object_add((json_object*)jobj1, key, (json_object*)jobj2);
	return 0;
}

int json_object_to_string(void *jobj, char *json_in_string)
{
	jobj = (json_object *)jobj;
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

	