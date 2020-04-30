/*
	Author: schaffung
	Date: 30/4/2020
*/

#ifndef LIBJSONCWRAPPER_H_
#define LIBJSONCWRAPPER_H_


int create_json_boolean(void *jobj, const char *key, int value);
int create_json_int(void *jobj, const char *key, int value);
int create_json_double(void *jobj, const char *key, double value);
int create_json_string(void *jobj, const char *key, const char *value);
int create_json_array(void *jobj, const char *key, void *jarr);
int embed_object(void *jobj1, const char *key, void *jobj2);
int json_object_to_string(void *jobj, char *json_in_string);

#endif LIBJSONCWRAPPER_H_