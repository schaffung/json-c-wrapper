/*
	Author: schaffung
	Date: 30/4/2020
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libjsoncwrapper.h"


/*
	Definition for Functions wherein the JSON Object doesn't exist and is created newly.
*/

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
	jobj = json_object_new_object();
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


int new_jobj_bool_arr(json_object *jobj, const char **key_arr, int *bool_arr, int int_bool_len)
{
	if( int_bool_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_bool_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jobj_bool_val(jobj, key_arr[iter_val], bool_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jobj_bool_val(jobj, key_arr[iter_val], bool_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}


int new_jobj_int_arr(json_object *jobj, const char **key_arr, int *int_arr, int int_arr_len)
{
	if( int_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jobj_int_val(jobj, key_arr[iter_val], int_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jobj_int_val(jobj, key_arr[iter_val], int_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}



int new_jobj_double_arr(json_object *jobj, const char **key_arr, double *double_arr, int double_arr_len)
{
	if( double_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < double_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jobj_double_val(jobj, key_arr[iter_val], double_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jobj_double_val(jobj, key_arr[iter_val], double_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}


int new_jobj_string_arr(json_object *jobj, const char **key_arr, const char **string_arr, int string_arr_len)
{
	if( string_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < string_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jobj_string_val(jobj, key_arr[iter_val], string_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jobj_string_val(jobj, key_arr[iter_val], string_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}


int new_jobj_jobj_arr(json_object *jobj, const char **key_arr, json_object **jobj_arr, int jobj_arr_len)
{
	if( jobj_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jobj_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jobj_jobj_val(jobj, key_arr[iter_val], jobj_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jobj_jobj_val(jobj, key_arr[iter_val], jobj_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}


int new_jobj_jarr_arr(json_object *jobj, const char **key_arr, json_object **jarr_arr, int jarr_arr_len)
{
	if( jarr_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jarr_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jobj_jarr_val(jobj, key_arr[iter_val], jarr_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jobj_jarr_val(jobj, key_arr[iter_val], jarr_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}



/*
	Definition for Functions wherein the JSON Object is already initialized and existing.
*/

int push_jobj_bool_val(json_object *jobj, const char *key, int value)
{
	if( key == NULL || jobj == NULL )
	{
		return -1;
	}
	json_object_object_add(jobj, key, json_object_new_boolean(value));	
	return 0;
}

int push_jobj_int_val(json_object *jobj, const char *key, int value)
{
	if( key == NULL || jobj == NULL )
	{
		return -1;
	}
	json_object_object_add(jobj, key, json_object_new_int(value));
	return 0;
}

int push_jobj_double_val(json_object *jobj, const char *key, double value)
{
	if( key == NULL || jobj == NULL )
	{
		return -1;
	}
	json_object_object_add(jobj, key, json_object_new_double(value));
	return 0;
}

int push_jobj_string_val(json_object *jobj, const char *key, const char *value)
{
	if( key == NULL || jobj == NULL )
	{
		return -1;
	}
	json_object_object_add(jobj, key, json_object_new_string(value));
	return 0;
}

int push_jobj_jarr_val(json_object *jobj, const char *key, json_object *jarr)
{
	if( key == NULL || jobj == NULL )
	{
		return -1;
	}
	json_object_object_add(jobj, key, jarr);
	return 0;
}

int push_jobj_jobj_val(json_object *jobj1, const char *key, json_object *jobj2)
{
	if( key == NULL || jobj1 == NULL )
	{
		return -1;
	}
	json_object_object_add(jobj1, key, jobj2);
	return 0;
}


int push_jobj_bool_arr(json_object *jobj, const char **key_arr, int *bool_arr, int int_bool_len)
{
	if( int_bool_len < 1 || jobj == NULL)
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_bool_len; iter_val++)
	{
		if( push_jobj_bool_val(jobj, key_arr[iter_val], bool_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


int push_jobj_int_arr(json_object *jobj, const char **key_arr, int *int_arr, int int_arr_len)
{
	if( int_arr_len < 1 || jobj == NULL)
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_arr_len; iter_val++)
	{
		if( push_jobj_int_val(jobj, key_arr[iter_val], int_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}

int push_jobj_double_arr(json_object *jobj, const char **key_arr, double *double_arr, int double_arr_len)
{
	if( double_arr_len < 1 || jobj == NULL)
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < double_arr_len; iter_val++)
	{
		if( push_jobj_double_val(jobj, key_arr[iter_val], double_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


int push_jobj_string_arr(json_object *jobj, const char **key_arr, const char **string_arr, int string_arr_len)
{
	if( string_arr_len < 1 || jobj == NULL)
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < string_arr_len; iter_val++)
	{
		if( push_jobj_string_val(jobj, key_arr[iter_val], string_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}



int push_jobj_jobj_arr(json_object *jobj, const char **key_arr, json_object **jobj_arr, int jobj_arr_len)
{
	if( jobj_arr_len < 1 || jobj == NULL)
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jobj_arr_len; iter_val++)
	{
		if( push_jobj_jobj_val(jobj, key_arr[iter_val], jobj_arr[iter_val]) != 0)
		{
			return -2;
		}

	}
	return 0;
}


int push_jobj_jarr_arr(json_object *jobj, const char **key_arr, json_object **jarr_arr, int jarr_arr_len)
{
	if( jarr_arr_len < 1 || jobj == NULL)
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jarr_arr_len; iter_val++)
	{
		if( push_jobj_jarr_val(jobj, key_arr[iter_val], jarr_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


/*
	Definition for Functions wherein the JSON Array doesn't exist and is created newly.
*/

int new_jarr_bool_val(json_object *jarr, int value)
{
	jarr = json_object_new_array();
	json_object_array_add(jarr, json_object_new_boolean(value));
	return 0;
}

int new_jarr_int_val(json_object *jarr, int int_val)
{
	jarr = json_object_new_array();
	json_object_array_add(jarr, json_object_new_int(int_val));
	return 0;
}

int new_jarr_double_val(json_object *jarr, double double_val)
{
	jarr = json_object_new_array();
	json_object_array_add(jarr, json_object_new_double(double_val));
	return 0;
}


int new_jarr_string_val(json_object *jarr, const char *string_val)
{
	if( string_val == NULL )
	{
		return -1;
	}
	jarr = json_object_new_array();
	json_object_array_add(jarr, json_object_new_string(string_val));
	return 0;
}

int new_jarr_jarr_val(json_object *jarr1, json_object *jarr2)
{
	if( jarr2 == NULL )
	{
		return -1;
	}
	jarr1 = json_object_new_array();
	json_object_array_add(jarr1, jarr2);
	return 0;
}


int new_jarr_jobj_val(json_object *jarr, json_object *jobj)
{
	if( jobj == NULL )
	{
		return -1;
	}
	jarr = json_object_new_array();
	json_object_array_add(jarr, jobj);
	return 0;
}

int new_jarr_bool_arr(json_object *jarr, int *bool_arr, int int_bool_len)
{
	if( int_bool_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_bool_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jarr_bool_val(jarr, bool_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jarr_bool_val(jarr, bool_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}


int new_jarr_int_arr(json_object *jarr, int *int_arr, int int_arr_len)
{
	if( int_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jarr_int_val(jarr, int_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jarr_int_val(jarr, int_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}

int new_jarr_double_arr(json_object *jarr, double *double_arr, int double_arr_len)
{
	if( double_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < double_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jarr_double_val(jarr, double_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jarr_double_val(jarr, double_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}


int new_jarr_string_arr(json_object *jarr, const char **string_arr, int string_arr_len)
{
	if( string_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < string_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jarr_string_val(jarr, string_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jarr_string_val(jarr, string_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}



int new_jarr_jobj_arr(json_object *jarr, json_object **jobj_arr, int jobj_arr_len)
{
	if( jobj_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jobj_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jarr_jobj_val(jarr, jobj_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jarr_jobj_val(jarr, jobj_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}


int new_jarr_jarr_arr(json_object *jarr, json_object **jarr_arr, int jarr_arr_len)
{
	if( jarr_arr_len < 1 )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jarr_arr_len; iter_val++)
	{
		if( iter_val == 0 )
		{
			if( new_jarr_jarr_val(jarr, jarr_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
		else
		{
			if( push_jarr_jarr_val(jarr, jarr_arr[iter_val]) != 0)
			{
				return -2;
			}
		}
	}
	return 0;
}






/*
	Definition for Functions wherein the JSON Array is already initialized and existing.
*/

int push_jarr_bool_val(json_object *jarr, int value)
{
	if( jarr == NULL )
	{
		return -1;
	}
	json_object_array_add(jarr, json_object_new_boolean(value));
	return 0;
}

int push_jarr_int_val(json_object *jarr, int int_val)
{
	if( jarr == NULL )
	{
		return -1;
	}
	json_object_array_add(jarr, json_object_new_int(int_val));
	return 0;
}


int push_jarr_double_val(json_object *jarr, double double_val)
{
	if( jarr == NULL )
	{
		return -1;
	}
	json_object_array_add(jarr, json_object_new_double(double_val));
	return 0;
}

int push_jarr_string_val(json_object *jarr, const char *string_val)
{
	if( string_val == NULL || jarr == NULL)
	{
		return -1;
	}
	json_object_array_add(jarr, json_object_new_string(string_val));
	return 0;
}

int push_jarr_jarr_val(json_object *jarr1, json_object *jarr2)
{
	if( jarr1 == NULL || jarr2 == NULL )
	{
		return -1;
	}
	json_object_array_add(jarr1, jarr2);
	return 0;
}


int push_jarr_jobj_val(json_object *jarr, json_object *jobj)
{
	if( jarr == NULL || jobj == NULL )
	{
		return -1;
	}
	json_object_array_add(jarr, jobj);
	return 0;
}


int push_jarr_bool_arr(json_object *jarr, int *bool_arr, int int_bool_len)
{
	if( int_bool_len < 1 || jarr == NULL )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_bool_len; iter_val++)
	{
		if( push_jarr_bool_val(jarr, bool_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


int push_jarr_int_arr(json_object *jarr, int *int_arr, int int_arr_len)
{
	if( int_arr_len < 1 || jarr == NULL )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < int_arr_len; iter_val++)
	{
		if( push_jarr_int_val(jarr, int_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


int push_jarr_double_arr(json_object *jarr, double *double_arr, int double_arr_len)
{
	if( double_arr_len < 1 || jarr == NULL )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < double_arr_len; iter_val++)
	{
		if( push_jarr_double_val(jarr, double_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


int push_jarr_string_arr(json_object *jarr, const char **string_arr, int string_arr_len)
{
	if( string_arr_len < 1 || jarr == NULL )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < string_arr_len; iter_val++)
	{
		if( push_jarr_string_val(jarr, string_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


int push_jarr_jobj_arr(json_object *jarr, json_object **jobj_arr, int jobj_arr_len)
{
	if( jobj_arr_len < 1 || jarr == NULL )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jobj_arr_len; iter_val++)
	{
		if( push_jarr_jobj_val(jarr, jobj_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
	return 0;
}


int push_jarr_jarr_arr(json_object *jarr, json_object **jarr_arr, int jarr_arr_len)
{
	if( jarr_arr_len < 1 || jarr == NULL )
	{
		return -1;
	}
	
	for (int iter_val = 0; iter_val < jarr_arr_len; iter_val++)
	{
		if( push_jarr_jarr_val(jarr, jarr_arr[iter_val]) != 0)
		{
			return -2;
		}
	}
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

	