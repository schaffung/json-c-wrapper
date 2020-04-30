/*
	Author: schaffung
	Date: 30/4/2020
*/

#ifndef LIBJSONCWRAPPER_H_
#define LIBJSONCWRAPPER_H_

// The JSON object initialization is done inside the functions.
int create_json_boolean(void *jobj, const char *key, int value);
int create_json_int(void *jobj, const char *key, int value);
int create_json_double(void *jobj, const char *key, double value);
int create_json_string(void *jobj, const char *key, const char *value);
int create_json_array(void *jobj, const char *key, void *jarr);

// The JSON array is already existing.
int create_new_json_array_with_string_arr(void *jarr, char **string_arr, int string_arr_len);
int create_new_json_array_with_int_arr(void *jarr, int *int_arr, int int_arr_len);
int create_new_json_array_with_double_arr(void *jarr, double *double_arr, int double_arr_len);
int push_json_array_string_value(void *jarr, const char *string_val);
int push_json_array_int_value(void *jarr, int int_val);
int push_json_array_double_value(void *jarr, double double_val);
int push_json_array_json_array(void *jarr1, void *jarr2);
int push_json_array_json_object(void *jarr, void *jobj);

// The JSON array initialization will be done inside the functions.
int new_json_array_string_value(void *jarr, const char *string_val);
int new_json_array_int_value(void *jarr, int int_val);
int new_json_array_double_value(void *jarr, double double_val);
int new_json_array_json_array_value(void *jarr1, void *jarr2);
int new_json_array_json_object_value(void *jarr, void *jobj);

// The JSON object initialization is done only in embed_object_new() function.
int embed_object(void *jobj1, const char *key, void *jobj2);
int embed_object_new(void *jobj1, const char *key, void *jobj2);

// No need to allocate memory for the json_in_string as it will be done in the function.
int json_object_to_string(void *jobj, char *json_in_string);

#endif LIBJSONCWRAPPER_H_