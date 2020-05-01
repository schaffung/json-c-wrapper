/*
	Author: schaffung
	Date: 30/4/2020
*/

#ifndef LIBJSONCWRAPPER_H_
#define LIBJSONCWRAPPER_H_

#include <json-c/json.h>

// The JSON object initialization is done inside the functions.
int new_jobj_bool_val(json_object *jobj, const char *key, int value);
int new_jobj_int_val(json_object *jobj, const char *key, int value);
int new_jobj_double_val(json_object *jobj, const char *key, double value);
int new_jobj_string_val(json_object *jobj, const char *key, const char *value);
int new_jobj_jarr_val(json_object *jobj, const char *key, json_object *jarr);
int new_jobj_jobj_val(json_object *jobj1, const char *key, json_object *jobj2);
int new_jobj_bool_arr(json_object *jobj, const char **key_arr, int *value, int int_arr_len);
int new_jobj_int_arr(json_object *jobj, const char **key_arr, int *int_arr, int int_arr_len);
int new_jobj_double_arr(json_object *jobj, const char **key_arr, double *double_arr, int double_arr_len);
int new_jobj_string_arr(json_object *jobj, const char **key_arr, char **string_arr, int string_arr_len);
int new_jobj_jobj_arr(json_object *jobj, const char **key_arr, json_object **jobj_arr, int jobj_arr_len);
int new_jobj_jarr_arr(json_object *jobj, const char **key_arr, json_object **jarr_arr, int jarr_arr_len);

// The JSON array initialization will be done inside the functions.
int new_jarr_bool_val(json_object *jarr, int value);
int new_jarr_string_val(json_object *jarr, const char *string_val);
int new_jarr_int_val(json_object *jarr, int int_val);
int new_jarr_double_val(json_object *jarr, double double_val);
int new_jarr_jarr_val(json_object *jarr1, json_object *jarr2);
int new_jarr_jobj_val(json_object *jarr, json_object *jobj);
int new_jarr_bool_arr(json_object *jarr, int *bool_arr, int int_bool_len);
int new_jarr_int_arr(json_object *jarr, int *int_arr, int int_arr_len);
int new_jarr_double_arr(json_object *jarr, double *double_arr, int double_arr_len);
int new_jarr_string_arr(json_object *jarr, char **string_arr, int string_arr_len);
int new_jarr_jobj_arr(json_object *jarr, json_object **jobj_arr, int jobj_arr_len);
int new_jarr_jarr_arr(json_object *jarr, json_object **jarr_arr, int jarr_arr_len);

// The JSON array is already existing.
int push_json_array_string_value(json_object *jarr, const char *string_val);
int push_json_array_int_value(json_object *jarr, int int_val);
int push_json_array_double_value(json_object *jarr, double double_val);
int push_json_array_json_array(json_object *jarr1, json_object *jarr2);
int push_json_array_json_object(json_object *jarr, json_object *jobj);

// The JSON object initialization is done only in embed_object_new() function.
int embed_object(json_object *jobj1, const char *key, json_object *jobj2);

// No need to allocate memory for the json_in_string as it will be done in the function. Hence just pass
// the char pointer.
int json_object_to_string(json_object *jobj, char *json_in_string);

#endif LIBJSONCWRAPPER_H_